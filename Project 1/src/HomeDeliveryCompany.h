
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
  void readFiles();
  double calculateDist(double lat1, double lat2, double lon1, double lon2);
  double deg2rad(double deg);
  void readNodesFile();
  void readDirectionFile();
  void readConectionsFile();
  void readSupermarketsFile();
  void readClientsFile();
  Road * getRoad(int id);
};

#endif /* HOMEDELIVERYCOMPANY_H_ */
