/*
 * Supermarkets.h
 */

#ifndef SUPERMARKET_H_
#define SUPERMARKET_H_

#include <iostream>
#include <vector>
#include "Graph.h"
#include "Client.h"


class Supermarket {
	Vertex * node;
	vector<Client *> clients;
	int id;
public:
	Supermarket(Vertex* node);
	void setId(int id);
	void addClient(Client * client);
	Vertex * getNode();
	int getId();
	bool removeClient(Client * c);
	long long int closestClient();
	unsigned int getNrClients();
	void resetAllVisited();
	friend ostream& operator<<(ostream& os, const Supermarket * s){
		for(auto it:s->clients){
			os << "Client " << it->getName() << " located at node " << it->getNodeId() << endl;
		}
		return os;
	}
};



#endif /* SUPERMARKET_H_ */
