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
#define Height	1003
#define Width 784
#define maxlat 41.1589000
#define maxlon -8.6012000
#define minlat 41.1492000
#define minlon -8.6230000

#include <math.h>
#include "Graph.h"

double deg2rad(double deg);
double calculateDist(double lat1, double lat2, double lon1, double lon2);
int coord2Y(double lat);
int coord2X(double lon);


#endif /* UTILITY_H_ */
