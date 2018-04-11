/*
 * Road.h
 */

#ifndef ROAD_H_
#define ROAD_H_

#include <string>
using namespace std;

class Road {
	long long int id;
	string name;
	bool oneway;
public:
	Road(long long int id,string name,bool oneway);
	int getId();
	string getName();
	bool isOneway();
};


#endif /* ROAD_H_ */
