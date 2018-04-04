#include "Graph.h"
#include "Road.h"
#include "Supermarket.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>

#define PI 3.14159265
#define earthRadius (6371.0*1000.0)

using namespace std;

files() {
		graph = new Graph<int>();
}

void readFiles() {
	readNodesFile();
	readDirectionFile();
	readConectionsFile();
}

void readNodesFile() {
	cout << "Trying to read nodes.txt File ..........";
	ifstream file;
	string line;
	int n;
	double lat, lon;
	char crab;
	file.open("nodes.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);
			ss >> n >> crab >> lat >> crab >> lon >> crab;
			graph->addVertex(n, lat, lon);
		}
		file.close();
		cout << "   Done!\n";
	} else
		cout << "\nUnable to open nodes.txt file";
}

void readDirectionFile() {
	cout << "Trying to read roadDir.txt File ..........";
	ifstream file;
	string line, data, name;
	int n;
	bool oneway;
	char crab = ';';
	file.open("roadDir.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);
			ss >> n;
			getline(ss, data, crab);
			getline(ss, data, crab);
			name = data;
			getline(ss, data, crab);
			oneway = (data == "False") ? false : true;
			roads.push_back(new Road(n, name, oneway));
		}
		file.close();
		cout << "   Done!\n";
	} else
		cout << "\nUnable to open roadCon.txt file";
}

void readConectionsFile() {
	cout << "Trying to read roadCon.txt File ..........";
	ifstream file;
	string line;
	int n;
	int src, dst;
	double dist;
	char crab;
	file.open("roadCon.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);
			//read from roadCon.txt,variables n , crab,src,ds,source,dest,dist
			ss >> n >> crab >> src >> crab >> dst >> crab;
			Vertex<int> * source = graph->findVertex(src);
			Vertex<int> * dest = graph->findVertex(dst);
			if (source == NULL || dest == NULL) {
				cout << "\nError the files nodes.txt and roadCon.txt do not match.";
				return;
			}
			dist = calculateDist(source->getLat(), dest->getLat(),
					source->getLon(), dest->getLon());
			auto v=getRoad(n);
			if(v==NULL){
				cout << "\nError the files roadDir.txt and roadCon.txt do not match.";
				return;
			}
			graph->addEdge(src, dst, dist,v->isOneway());
		}
		file.close();
		cout << "   Done!\n";
	} else
		cout << "\nUnable to open roadCon.txt file";
}

void readSupermarketsFile()
{
	cout << "Trying to read supermarkets.txt File ..........";
	ifstream file;
	string line;
	int nodeId;
	file.open("supermarkets.txt");
	if(file.is_open()){
		while(getline(file,line)){
			stringstream ss(line);
			ss << nodeId;
			if(graph->findVertex(nodeId))
				supermarkets.push_back(new Supermarket(graph->findVertex(nodeId)));
			else {
				cout << "\nError the files supermarkets.txt and nodes.txt do not match.";
			}
		}
	}else
		cout << "\nUnable to open supermarkets.txt file";
}

void readClientsFile()
{
	cout << "Trying to read clients.txt File ..........";
	ifstream file;
	string line;
	int nodeId;
	file.open("clients.txt");
	if(file.is_open()){
		while(getline(file,line)){
			stringstream ss(line);
			ss << nodeId;
			if(graph->findVertex(nodeId)){
				clients.push_back(new Client(graph->findVertex(nodeId)));

			}
			else{
				cout << "\nError the files clients.txt and nodes.txt do not match.";
			}
		}
	}else
		cout << "\nUnable to open clients.txt file";
}

double deg2rad(double deg) {
	return (deg * PI / 180);
}

Road * getRoad(int id){
	for(auto r:roads){
		if(r->getId()==id)
			return r;
	}
	return NULL;
}



double calculateDist(double lat1, double lat2, double lon1, double lon2) {
	  double dlat,dlon, latsin, lonsin,result;
	  dlat=deg2rad(lat2-lat1);
	  dlon=deg2rad(lon2-lon1);
	  latsin = sin(dlat/2);
	  lonsin = sin(dlon/2);
	  result = asin(sqrt(latsin * latsin + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * lonsin * lonsin));
	  return 2.0 * earthRadius * result;
	}
