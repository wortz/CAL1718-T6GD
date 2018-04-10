#include "HomeDeliveryCompany.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>

using namespace std;

HomeDeliveryCompany::HomeDeliveryCompany(){
	this->graph=new Graph();
}

void HomeDeliveryCompany::setGraph(Graph * graph){
	this->graph=graph;
}

Road * HomeDeliveryCompany::getRoad(int id){
	for(auto r:roads){
		if(r->getId()==id)
			return r;
	}
	return NULL;
}

Graph * HomeDeliveryCompany::getGraph(){
	return graph;
}

Supermarket* HomeDeliveryCompany::findSuper(int id){
	for(auto it:supermarkets){
		if(it->getId()==id)
			return it;
	}
	return NULL;
}

bool HomeDeliveryCompany::addClient(Client * c){
	if(addClientToSupermarket(c)){
		clients.push_back(c);
		return true;
	}
	return false;
}

void HomeDeliveryCompany::addRoad(Road* r){
	roads.push_back(r);
}

void HomeDeliveryCompany::addSupermarket(Supermarket* s){
	int idmax=0;
	if (s->getId() == -1&&supermarkets.size()>0) {
		Supermarket * aux=supermarkets[supermarkets.size()-1];
		idmax=aux->getId();
	}
		idmax++;
		s->setId(idmax);
		supermarkets.push_back(s);
	if(!clients.size()==0)
		reworkOrganization();
}

void HomeDeliveryCompany::reworkOrganization(){
	for(auto v:clients){
		addClientToSupermarket(v);
	}
}

bool HomeDeliveryCompany::addClientToSupermarket(Client * c){
	double d=-1;
	double curr;
	bool notConnected=true;
	Supermarket* i;
	for(auto v:supermarkets){
		graph->dijkstraShortestPath(v->getNode()->getInfo());
		auto n=c->getVertex();
		if(n->getPrevious()==NULL && notConnected){
			continue;
		}
		if(d==-1){
			d=n->getDist();
			i=v;
		}
		else{
			if((curr=n->getDist())<d){
				d=curr;
				i=v;
			}
		}
		notConnected=false;
	}
	if (notConnected)
		return false;
	i->addClient(c);
	return true;
}

bool HomeDeliveryCompany::isAvailable(int node){
	for(auto s:supermarkets){
			if(node==s->getNode()->getInfo()){
				return false;
			}
		}
		for(auto c:clients){
			if(node==c->getNodeId()){
				return false;
			}
		}
		return true;
}

bool HomeDeliveryCompany::removeClient(int nodeId) {
	for (unsigned int i = 0; i < clients.size(); i++)
		if (nodeId == clients[i]->getNodeId()) {
			for (auto s : supermarkets)
				if (s->removeClient(clients[i]))
					break;
			clients.erase(clients.begin() + i);
			return true;
		}
	return false;
}

bool HomeDeliveryCompany::removeSupermarket(int id){
	Supermarket* s = findSuper(id);
	for(unsigned int i=0;i<supermarkets.size();i++)
			if(s->getNode()->getInfo()==supermarkets[i]->getNode()->getInfo()){
				supermarkets.erase(supermarkets.begin()+i);
				this->reworkOrganization();
				return true;
			}
	return false;
}


void HomeDeliveryCompany::coutNodesAvailable(){
//	auto allNodes=graph->getNodes();
	for(auto node:graph->getNodes()){
		if(isAvailable(node->getInfo()))
			cout << "Node Id : " << node->getInfo() << endl;
	}
}

void HomeDeliveryCompany::coutClients(){
	for(auto it:clients){
	cout << "Client " << it->getName() << " located at node " << it->getNodeId() << endl;
	}
}

void HomeDeliveryCompany::coutSupermarkets(){
	for(auto it:supermarkets){
		cout << "Supermarket number " << it->getId() << " located at node " << it->getNode()->getInfo() << endl;
	}
}

vector<Vertex*> HomeDeliveryCompany::createRote(int id){
	Supermarket * s;
	vector<Vertex*> TempPath;
	vector<Vertex*> AllPath;
	int info1;
	s=findSuper(id);
	int info2;
	info1=s->getNode()->getInfo();
	for(unsigned int i=0;i<s->getNrClients();i++){
		graph->dijkstraShortestPath(info1);
		info2=s->closestClient();
		TempPath=graph->getPath(info1,info2);
		for(auto it:TempPath)
			AllPath.push_back(it);
		info1=info2;
	}
	info2=s->getNode()->getInfo();
	graph->dijkstraShortestPath(info1);
	TempPath=graph->getPath(info1,info2);
	for(auto it:TempPath)
		AllPath.push_back(it);
	s->resetAllVisited();
//	printGraphviewer(AllPath);
	return AllPath;
}

/*void HomeDeliveryCompany::printGraphviewer(vector<Vertex> v){
	gv = new GraphViewer(Height, Width, false);
	gv->setBackground("background.png");
	gv->createWindow(1003, 784);
	gv->defineVertexColor("green");
	gv->defineEdgeColor("blue");
	int u=0;
	for(unsigned int i=0;i<v.size();i++){
		int info=v[i].getInfo();
		int x=coord2Y(v[i].getLon());
		int y=coord2Y(v[i].getLat());
		gv->addNode(info,x,y);
	}
	for(unsigned int i=0;i<(v.size()-1);i++){
			int info1=v[i].getInfo();
			int info2=v[i+1].getInfo();
			int oneway=0;
			auto e=graph->findEdge(info1,info2);
			if(e.isOneWay())
				oneway=1;
			gv->addEdge(u,info1,info2,oneway);
			u++;
		}
}
*/









