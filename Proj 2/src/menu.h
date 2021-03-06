/*
 * menu.h
 *
 *  Created on: 09/04/2018
 *      Author: Asus
 */

#ifndef MENU_H_
#define MENU_H_

#include "files.h"
#include<iostream>
#include "Graph.h"
#include "graphviewer.h"
#include "edgetype.h"




void returnmenu();
void inicateApp();
void mainMenu();
void addClient();
void removeClient();
void addSupermarket();
void removerSupermarket();
void printSupermarkets();
void printClients();
void printClientsSupermarket();
void printGraph();
void closeWindow();
void lines();
void seeDistTime();
void returnmenu(GraphViewer * gv);
void searchSupermarket();
void sortVectors(vector<Road *> & roadList, vector<int> &indexes);
bool searchSuperinVertexes(string s);


#endif /* MENU_H_ */
