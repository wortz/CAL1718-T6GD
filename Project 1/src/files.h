/*
 * files.h
 */

#ifndef FILES_H_
#define FILES_H_

using namespace std;

class files {
  Graph<int> * graph;
  vector<Road *> roads;
  vector<Supermarket *> supermarkets;
  vector<Client *> clients;

  public:
  files();
  void readFiles();
  double calculateDist(double lat1, double lat2, double lon1, double lon2);
  double deg2rad(double deg);
  void readNodesFile();
  void readDirectionFile();
  void readConectionsFile();
  Road * getRoad(int id);
};

#endif /* FILES_H_ */
