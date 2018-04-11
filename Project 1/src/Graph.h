/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <algorithm>
#include "MutablePriorityQueue.h"



class Edge;
class Graph;



#define INF std::numeric_limits<double>::max()

/****************** Provided structures  ********************/


class Vertex {
	long long int info;                // contents
	double lon,lat;		   //coordinates in earthsystem
	vector<Edge > adj;  // list of outgoing edges
	int queueIndex = 0; 	// required by MutablePriorityQueue
	int indegree;          // auxiliary field used by topsort
	double dist;
	Vertex *path = NULL;
	int index;

	void addEdge(Vertex *d, double w,bool oneway,string name);
	bool removeEdgeTo(Vertex *d);
public:
	long long int getInfo();
	bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue
	double getLon();
	int getIndex();
	double getLat();
	double getDist();
	Edge findEdgeTo(const long long int &dest);
	Vertex * getPrevious();
	Vertex(long long int in,double lat,double lon,int index);
	friend class Graph;
	friend class MutablePriorityQueue<Vertex>;
};





class Edge {
	Vertex * dest;      // destination vertex
	double weight;         // edge weight
	bool oneway;
	string name;
public:
	Edge(Vertex *d, double w,bool oneway,string name);
	bool isOneWay();
	string getName();
	friend class Graph;
	friend class Vertex;
};

class Graph {
	vector<Vertex *> vertexSet;    // vertex set
	vector<Edge *> edgesSet;		  //edges set


public:
	Vertex *findVertex(const long long int &in) const;
	int getNumVertex() const;
	bool addVertex(const long long int &in,double lat,double lon,int index);
	bool removeVertex(const long long int &in);
	bool addEdge(const long long int &sourc, const long long int &dest, double w,bool oneway,string name);
	bool removeEdge(const long long int &sourc, const long long int &dest);
	vector<Vertex*> getPath(const long long int &origin, const long long int &dest) const;
	void dijkstraShortestPath(const long long int &s);
	bool relax(Vertex *v, Vertex *w, double weight);
	Vertex * initSingleSource(const long long int &origin);
	vector<Vertex *> getNodes();
	Edge findEdge(const long long int &sourc,const long long int &dest);
};

/****************** Provided constructors and functions ********************/








#endif /* GRAPH_H_ */
