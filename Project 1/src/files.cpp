/*
 * files.cpp
 *
 *  Created on: 09/04/2018
 *      Author: Asus
 */
#include "files.h"


using namespace std;

HomeDeliveryCompany * company=new HomeDeliveryCompany();
Graph * graph=new Graph();

void readFiles() {
	company->setGraph(graph);
	readNodesFile();
	readDirectionFile();
	readConectionsFile();
	readSupermarketsFile();
	readClientsFile();
}

void readNodesFile() {
	cout << "Trying to read nodes.txt File ..........";
	ifstream file;
	string line;
	int i=1;
	long long int n;
	double lat, lon;
	char crap;
	file.open("nodes.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);
			ss >> n >> crap >> lat >> crap >> lon >> crap;
			graph->addVertex(n, lat, lon,i);
			i++;
		}
		file.close();
		cout << "          Done!\n";
	} else
		cout << "\nUnable to open nodes.txt file";
}

void readDirectionFile() {
	cout << "Trying to read roadDir.txt File ..........";
	ifstream file;
	string line, data, name;
	long long int n;
	bool oneway;
	char crap = ';';
	file.open("roadDir.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);
			ss >> n;
			getline(ss, data, crap);
			getline(ss, data, crap);
			name = data;
			getline(ss, data, crap);
			oneway = (data == "False") ? true : false;
			company->addRoad(new Road(n, name, oneway));
		}
		file.close();
		cout << "        Done!\n";
	} else
		cout << "\nUnable to open roadCon.txt file";
}

void readConectionsFile() {
	cout << "Trying to read roadCon.txt File ..........";
	ifstream file;
	string line;
	long long int n;
	long long int src, dst;
	double dist;
	char crap;
	file.open("roadCon.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);
			//read from roadCon.txt,variables n , crab,src,ds,source,dest,dist
			ss >> n >> crap >> src >> crap >> dst >> crap;
			Vertex * source = graph->findVertex(src);
			Vertex * dest = graph->findVertex(dst);
			if (source == NULL || dest == NULL) {
				cout << "\nError the files nodes.txt and roadCon.txt do not match.";
				return;
			}
			dist = calculateDist(source->getLat(), dest->getLat(),source->getLon(), dest->getLon());
			auto v=company->getRoad(n);
			if(v==NULL){
				cout << "\nError the files roadDir.txt and roadCon.txt do not match.";
				return;
			}
			graph->addEdge(src, dst, dist,v->isOneway());
		}
		file.close();
		cout << "        Done!\n";
	} else
		cout << "\nUnable to open roadCon.txt file";
}

void readSupermarketsFile()
{
	cout << "Trying to read supermarkets.txt File ..........";
	ifstream file;
	string line;
	long long int nodeId;
	char crap;
	file.open("supermarkets.txt");
	if(file.is_open()){
		while(getline(file,line)){
			stringstream ss(line);
			ss >> nodeId >> crap;
			auto v=graph->findVertex(nodeId);
			if(v!=NULL)
				company->addSupermarket(new Supermarket(v));
			else {
				cout << "\nError the files supermarkets.txt and nodes.txt do not match.";
				break;
			}
		}
		file.close();
		cout << "   Done!\n";
	}else
		cout << "\nUnable to open supermarkets.txt file.";
}

void readClientsFile()
{
	cout << "Trying to read clients.txt File ..........";
	ifstream file;
	string line, data, name;
	long long int nodeId;
	char crap = ';';
	file.open("clients.txt");
	if(file.is_open()){
		while(getline(file,line)){
			stringstream ss(line);
			ss >> nodeId;
			getline(ss, data, crap);
			getline(ss, data, crap);
			name=data;
			auto v=graph->findVertex(nodeId);
			if(v!=NULL){
				if(!company->addClient(new Client(v,name))){
					cout << "\nThe company has no path to reach client: " << name
									<< " located on node: " << nodeId << "\nThat client will not be added.";
				}
			}
			else{
				cout << "\nError the files clients.txt and nodes.txt do not match.";
			}
		}
		file.close();
		cout << "        \nDone!\n";
	}else
		cout << "\nUnable to open clients.txt file.";
}

void saveClientsFile(){
	cout << "Saving clients info to clients.txt File ..........";

}

