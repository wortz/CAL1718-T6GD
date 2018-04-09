/*
 * Client.h
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Graph.h"

using namespace std;

class Client {
	Vertex<int> * node;
public:
	Client(Vertex<int>* node);
	int getNodeId();
	Vertex<int>* getVertex();
};



#endif /* CLIENT_H_ */
