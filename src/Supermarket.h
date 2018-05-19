/*
 * Supermarkets.h
 */

#ifndef SUPERMARKET_H_
#define SUPERMARKET_H_

#include <iostream>
#include <vector>
#include "Graph.h"
#include "Client.h"
#include <string>


class Supermarket {
	Vertex * node;
	vector<Client *> clients;
	int id;
	string cadeia;
public:
	Supermarket(Vertex* node, string cadeia);
	void setId(int id);
	void addClient(Client * client);
	Vertex * getNode();
	int getId();
	bool removeClient(Client * c);
	long long int closestClient();
	unsigned int getNrClients();
	string getCadeia();
	void resetAllVisited();
	void eraseClients();
	friend ostream& operator<<(ostream& os, const Supermarket * s){
		for(auto it:s->clients){
			os << "Client " << it->getName() << " located at node " << it->getNodeId() << endl;
		}
		return os;
	}
};



#endif /* SUPERMARKET_H_ */
