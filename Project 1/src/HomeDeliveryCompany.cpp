#include "HomeDeliveryCompany.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>



HomeDeliveryCompany::HomeDeliveryCompany(){
}

void HomeDeliveryCompany::setGraph(Graph<int> * graph){
	this->graph=graph;
}

Road * HomeDeliveryCompany::getRoad(int id){
	for(auto r:roads){
		if(r->getId()==id)
			return r;
	}
	return NULL;
}

void HomeDeliveryCompany::addClient(Client * c){
	clients.push_back(c);
	addClientToSupermarket(c);
}

void HomeDeliveryCompany::addRoad(Road* r){
	roads.push_back(r);
}

void HomeDeliveryCompany::addSupermarket(Supermarket* s){
	supermarkets.push_back(s);
}

void HomeDeliveryCompany::addClientToSupermarket(Client * c){
	double d=-1;
	double curr;
	Supermarket* i;
	for(auto v:supermarkets){
		graph->dijkstraShortestPath(c->getNodeId());
		auto n=c->getVertex();
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
	}
	i->addClient(c);
}









