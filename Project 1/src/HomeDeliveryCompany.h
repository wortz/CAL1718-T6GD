
#ifndef HOMEDELIVERYCOMPANY_H_
#define HOMEDELIVERYCOMPANY_H_

#include "Graph.h"
#include "Road.h"
#include "Supermarket.h"
#include <iostream>
#include "graphviewer.h"



class HomeDeliveryCompany {
  Graph * graph;
  vector<Road *> roads;
  vector<Supermarket *> supermarkets;
  vector<Client *> clients;


  void reworkOrganization();
  bool addClientToSupermarket(Client * c);
  public:
  bool isAvailable(Vertex * v);
  HomeDeliveryCompany();
  void setGraph(Graph * graph);
  bool addClient(Client * c);
  void addRoad(Road* r);
  void addSupermarket(Supermarket* s);
  void coutNodesAvailable();
  Road * getRoad(int id);
  Graph * getGraph();
  bool removeClient(int nodeId);
  bool removeSupermarket(Supermarket * s);
  void coutClients();
  void coutSupermarkets();
  void showPath(int id);


};

#endif /* HOMEDELIVERYCOMPANY_H_ */
