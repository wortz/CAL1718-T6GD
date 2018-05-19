/*
 * utility.h
 *
 *  Created on: 09/04/2018
 *      Author: Asus
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#define PI 3.14159265
#define earthRadius (6371.0*1000.0)
#define Height 451
#define Width 766
#define maxlat 41.7772
#define maxlon -7.3523
#define minlat 41.7005
#define minlon -7.5267

#include <math.h>
#include "Graph.h"

double deg2rad(double deg);
double calculateDist(double lat1, double lat2, double lon1, double lon2);
int coord2Y(double lat);
int coord2X(double lon);


#endif /* UTILITY_H_ */
