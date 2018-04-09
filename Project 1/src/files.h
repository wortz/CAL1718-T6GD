/*
 * files.h
 *
 *  Created on: 09/04/2018
 *      Author: Asus
 */

#ifndef FILES_H_
#define FILES_H_

#define PI 3.14159265
#define earthRadius (6371.0*1000.0)

#include "HomeDeliveryCompany.h"
#include <iostream>



void readFiles();
double calculateDist(double lat1, double lat2, double lon1, double lon2);
double deg2rad(double deg);
void readNodesFile();
void readDirectionFile();
void readConectionsFile();
void readSupermarketsFile();
void readClientsFile();
void saveSupermarketsFile();
void saveClientsFile();

#endif /* FILES_H_ */
