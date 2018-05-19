/*
 * utility.cpp
 *
 *  Created on: 09/04/2018
 *      Author: Asus
 */

#include "Utility.h"

double calculateDist(double lat1, double lat2, double lon1, double lon2) {
	  double dlat,dlon, latsin, lonsin,result;
	  dlat=deg2rad(lat2-lat1);
	  dlon=deg2rad(lon2-lon1);
	  latsin = sin(dlat/2);
	  lonsin = sin(dlon/2);
	  result = asin(sqrt(latsin * latsin + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * lonsin * lonsin));
	  return 2.0 * earthRadius * result;
}

double deg2rad(double deg) {
	return (deg * PI / 180);
}

int coord2X(double lon){
	return (round(Width / (maxlon - minlon) * (lon - minlon)));
}

int coord2Y(double lat){
	return (Height
	- (round(Height / (maxlat - minlat) * (lat - minlat))));
}



