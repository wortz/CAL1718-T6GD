
#ifndef HOMEDELIVERYCOMPANY_H_
#define HOMEDELIVERYCOMPANY_H_

#define VELOCITY 0.5

#include "Graph.h"
#include "Road.h"
#include "Supermarket.h"
#include "Utility.h"
#include "graphviewer.h"
#include <iostream>



class HomeDeliveryCompany {
  Graph * graph;
  vector<Road *> roads;
  vector<Supermarket *> supermarkets;
  vector<Client *> clients;


  void reworkOrganization();
  bool addClientToSupermarket(Client * c);
  public:
  bool isAvailable(long long int node);
  HomeDeliveryCompany();
  void setGraph(Graph * graph);
  bool addClient(Client * c);
  void addRoad(Road* r);
  void addSupermarket(Supermarket* s);
  void coutNodesAvailable();
  Road * getRoad(long long int id);
  Graph * getGraph();
  Supermarket* findSuper(int id);
  bool removeClient(long long int nodeId);
  bool removeSupermarket(int id);
  void coutClients();
  void coutSupermarkets();
  vector<Vertex*> createRote(int id);
  void printGraphviewer(vector<Vertex> v);


};

#endif /* HOMEDELIVERYCOMPANY_H_ */
