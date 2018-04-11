/*
 * Client.h
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Graph.h"
#include <string>


class Client {
	Vertex * node;
	string name;
	bool visited;
public:
	Client(Vertex* node,string name);
	long long int getNodeId();
	string getName();
	bool isVisited();
	Vertex* getVertex();
	void setVisited(bool visited);
};



#endif /* CLIENT_H_ */
