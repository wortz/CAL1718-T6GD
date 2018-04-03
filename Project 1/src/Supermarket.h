/*
 * Supermarkets.h
 */

#ifndef SUPERMARKET_H_
#define SUPERMARKET_H_

#include <iostream>
#include <vector>
#include "Graph.h"
#include "Client.h"

using namespace std;

class Supermarket {
	Vertex<int> * node;
	vector<Client *> clients;
public:
	Supermarket(Vertex<int>* node);
	void addClient(Client * client);
};


#endif /* SUPERMARKET_H_ */
