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
	if (s->getId() == -1) {
		Supermarket * aux=supermarkets[supermarkets.size()-1];
		idmax=aux->getId();
	}
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

bool HomeDeliveryCompany::isAvailable(Vertex * v){
	for(auto s:supermarkets){
			if(v->getInfo()==s->getNode()->getInfo()){
				return false;
			}
		}
		for(auto c:clients){
			if(v->getInfo()==c->getNodeId()){
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

bool HomeDeliveryCompany::removeSupermarket(Supermarket * s){
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
		if(isAvailable(node))
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

void HomeDeliveryCompany::showPath(int id){
	Supermarket * s;
	vector<Vertex *> Allpath;
	vector<Vertex *> TempPath;
	int info1;
	for(auto it:supermarkets){
		s=it;
		if(s->getId()==id)
			break;
	}
	info1=s->getNode()->getInfo();
	graph->dijkstraShortestPath(info1);
	int info2=s->closestClient();
	TempPath=graph->getPath(info1,info2);
	for(auto it:TempPath){

	}

}








