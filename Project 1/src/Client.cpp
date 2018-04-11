/*
 * Client.cpp
 *
 *  Created on: 03/04/2018
 *      Author: Asus
 */

#include "Client.h"

using namespace std;

Client::Client(Vertex * node,string name){
	this->node=node;
	this->name=name;
	this->visited=false;
}

long long int Client::getNodeId(){
	return node->getInfo();
}

bool Client::isVisited(){
	return visited;
}

string Client::getName(){
	return name;
}

Vertex* Client::getVertex(){
	return node;
}

void Client::setVisited(bool visited){
	this->visited=visited;
}
