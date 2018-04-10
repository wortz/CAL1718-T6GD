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

using namespace std;

class Edge;
class Graph;



#define INF std::numeric_limits<double>::max()

/****************** Provided structures  ********************/


class Vertex {
	int info;                // contents
	double lon,lat;		   //coordinates in earthsystem
	vector<Edge > adj;  // list of outgoing edges
	int queueIndex = 0; 	// required by MutablePriorityQueue
	int indegree;          // auxiliary field used by topsort
	double dist;
	Vertex *path = NULL;

	void addEdge(Vertex *d, double w,bool oneway);
	bool removeEdgeTo(Vertex *d);
public:
	int getInfo();
	bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue
	double getLon();
	double getLat();
	double getDist();
	Vertex * getPrevious();
	Vertex(int in,double lat,double lon);
	friend class Graph;
	friend class MutablePriorityQueue<Vertex>;
};





class Edge {
	Vertex * dest;      // destination vertex
	double weight;         // edge weight
	bool oneway;
public:
	Edge(Vertex *d, double w,bool oneway);
	friend class Graph;
	friend class Vertex;
};

class Graph {
	vector<Vertex *> vertexSet;    // vertex set
	vector<Edge *> edgesSet;		  //edges set


public:
	Vertex *findVertex(const int &in) const;
	int getNumVertex() const;
	bool addVertex(const int &in,double lat,double lon);
	bool removeVertex(const int &in);
	bool addEdge(const int &sourc, const int &dest, double w,bool oneway);
	bool removeEdge(const int &sourc, const int &dest);
	vector<Vertex *> getPath(const int &origin, const int &dest) const;
	void dijkstraShortestPath(const int &s);
	bool relax(Vertex *v, Vertex *w, double weight);
	Vertex * initSingleSource(const int &origin);
	vector<Vertex *> getNodes();
};

/****************** Provided constructors and functions ********************/








#endif /* GRAPH_H_ */
