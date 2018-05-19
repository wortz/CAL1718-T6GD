/*
 * files.h
 *
 *  Created on: 09/04/2018
 *      Author: Asus
 */

#ifndef FILES_H_
#define FILES_H_

#include "HomeDeliveryCompany.h"
#include <iostream>
#include <sstream>
#include <fstream>

#include "Utility.h"

extern HomeDeliveryCompany * company;

void readFiles();
void readNodesFile();
void readDirectionFile();
void readConectionsFile();
void readSupermarketsFile();
void readClientsFile();
void saveSupermarketsFile();
void saveClientsFile();

#endif /* FILES_H_ */
