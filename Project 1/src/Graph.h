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

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;


#define INF std::numeric_limits<double>::max()

/****************** Provided structures  ********************/

template <class T>
class Vertex {
	T info;                // contents
	double lon,lat;		   //coordinates in earthsystem
	vector<Edge<T> > adj;  // list of outgoing edges
	bool visited;          // auxiliary field used by dfs and bfs
	bool processing;       // auxiliary field used by isDAG
	int indegree;          // auxiliary field used by topsort
	double dist;

	void addEdge(Vertex<T> *d, double w);
	bool removeEdgeTo(Vertex<T> *d);
public:
	double getLon();
	double getLat();
	Vertex(T in,double lat,double lon);
	friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>>;
};


template <class T>
Vertex<T>::Vertex(T in,double lon,double lat): info(in)  {
	this->lat=lat;
	this->lon=lon;
	this->dist=INF;
	this->visited=false;
	this->processing=false;
	this->indegree=0;
}

/*
 *  Returns the vertex lat
 */
template <class T>
double Vertex<T>::getLat(){
	return this->lat;
}

/*
 *  Returns the vertex lon
 */
template <class T>
double Vertex<T>::getLon(){
	return this->lon;
}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
	adj.push_back(Edge<T>(d, w));
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	for (auto it = adj.begin(); it != adj.end(); it++)
		if (it->dest  == d) {
			adj.erase(it);
			return true;
		}
	return false;
}



template <class T>
class Edge {
	Vertex<T> * dest;      // destination vertex
	double weight;         // edge weight
public:
	Edge(Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}


template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set
	vector<Edge<T> *> edgesSet;		  //edges set


public:
	void dfsVisit(Vertex<T> *v,  vector<T> & res) const;
	Vertex<T> *findVertex(const T &in) const;
	int getNumVertex() const;
	bool addVertex(const T &in,double lat,double lon);
	bool removeVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w,bool oneway);
	bool removeEdge(const T &sourc, const T &dest);
	vector<T> getPath(const T &origin, const T &dest) const;
	void dijkstraShortestPath(const T &s);
	bool relax(Vertex<T> *v, Vertex<T> *w, double weight);
	Vertex<T> * initSingleSource(const T &origin);
};

/****************** Provided constructors and functions ********************/





template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return NULL;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in,double lat,double lon) {
	if ( findVertex(in) != NULL)
		return false;
	vertexSet.push_back(new Vertex<T>(in,lat,lon));
	return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w,bool oneway) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	v1->addEdge(v2,w);
	if(!oneway)
		v2->addEdge(v1,w);
	return true;
}

/*
 * Removes an edge from a graph (this).
 * The edge is identified by the source (sourc) and destination (dest) contents.
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	return v1->removeEdgeTo(v2);
}

/*
 *  Removes a vertex with a given content (in) from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
template <class T>
bool Graph<T>::removeVertex(const T &in) {
	for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
		if ((*it)->info  == in) {
			auto v = *it;
			vertexSet.erase(it);
			for (auto u : vertexSet)
				u->removeEdgeTo(v);
			delete v;
			return true;
		}
	return false;
}

/**
* Initializes single
-
source shortest path data (path, dist).
* Receives the content of the source vertex and returns a pointer to the source vertex.
* Used by all single
-
source shortest path algorithms.
*/
template<class T>
Vertex<T> * Graph<T>::initSingleSource(const T &origin) {
	for(auto v : vertexSet) {
		v->dist = INF;
		v->path =nullptr;
	}
	auto s = findVertex(origin);
	s->dist = 0;
	return s;
}

/**
* Analyzes an edge in single
-
source shortest path algorithm.
* Returns true if the target vertex was relaxed (dist, path).
* Used by all single
-
source shortest path algorithms.
*/
template<class T>
bool Graph<T>::relax(Vertex<T> *v, Vertex<T> *w, double weight) {
	if (v->dist + weight < w->dist) {
		w->dist = v->dist + weight;
		w->path = v;
		return true;
	} else
		return false;
}

/**
* Dijkstra algorithm.
*/
template <class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
	auto s = initSingleSource(origin);
	MutablePriorityQueue<Vertex<T>> q;
	q.insert(s);
	while (!q.empty()) {
		auto v = q.extractMin();
	for (auto e : v->adj) {
		auto
		oldDist = e.dest->dist;
		if(relax(v, e.dest, e.weight)) {
			if(oldDist == INF)
				q.insert(e.dest);
			else
				q.decreaseKey(e.dest);
		}
	}
 }
}

/**
 * Gets the path from node origin to node dest
 * returns the vector of all the nodes
 */

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) const {
	vector<T> res;
	auto v = findVertex(dest);
	if (v == nullptr || v->dist == INF)
	// missing or disconnected
	return res;
	for (; v != nullptr; v = v->path)
		res.push_back(v->info);
	reverse(res.begin(), res.end());
	return res;
}

#endif /* GRAPH_H_ */
