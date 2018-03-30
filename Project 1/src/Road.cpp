/*
 * Road.cpp
 */

#include "Road.h"

using namespace std;

Road::Road(int id,string name,bool oneway) : id(id), name(name), oneway(oneway)  {}

int Road::getId(){
	return this->id;
}

string Road::getName(){
	return this->name;
}

bool Road::isOneway(){
	return this->oneway;
}

