
#ifndef HOMEDELIVERYCOMPANY_H_
#define HOMEDELIVERYCOMPANY_H_

#include "Graph.h"
#include "Road.h"
#include "Supermarket.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>

using namespace std;

class HomeDeliveryCompany {
  Graph<int> * graph;
  vector<Road *> roads;
  vector<Supermarket *> supermarkets;
  vector<Client *> clients;

  public:
  HomeDeliveryCompany();
  void findVertex();
  void setGraph(Graph<int> * graph);
  void addClient(Client * c);
  void addRoad(Road* r);
  void addSupermarket(Supermarket* s);
  void addClientToSupermarket(Client * c);
  Road * getRoad(int id);

};

#endif /* HOMEDELIVERYCOMPANY_H_ */
