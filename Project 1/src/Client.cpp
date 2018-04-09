/*
 * Client.cpp
 *
 *  Created on: 03/04/2018
 *      Author: Asus
 */

#include "Client.h"

using namespace std;

Client::Client(Vertex<int> * node){
	this->node=node;
}

int Client::getNodeId(){
	return node->getInfo();
}

Vertex<int>* Client::getVertex(){
	return node;
}
