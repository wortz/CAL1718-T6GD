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

#include <math.h>

double deg2rad(double deg);
double calculateDist(double lat1, double lat2, double lon1, double lon2);


#endif /* UTILITY_H_ */
