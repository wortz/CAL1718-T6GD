/*
 * menu.cpp
 *
 *  Created on: 09/04/2018
 *      Author: Asus
 */

#include "menu.h"
#include <string.h>

void inicateApp(){
	readFiles();
	mainMenu();
}

void mainMenu(){
	size_t input = 0;
	while (true) {
		vector<string> options = {
			"Add client.",
			"Remove client.",
			"See existent clients.",
			"Add Supermarket.",
			"Remove Supermarket.",
			"See existent Supermarkets.",
			"See clients atributed to a certain supermarket.",
			"See routes.",
			"See distance and time of routes."
		};

		for (size_t i = 0; i < options.size() - 1 ; i++) {
			cout << " " << i+1 << " - ";
			cout << options.at(i) << "\n";
		}
		cout << " 0 - EXIT\n";
		cout << "\n" << "Chose an option: ";
		cin >> input;

		if(!(input>=0&&input<=options.size())){
			cout << "\n" << "";
		}
		/* validar input */
		if (input == 0) {
			break;
		}
		for (unsigned int j = 0; j < 10; j++)
			cout << "\n\n\n\n\n";
		switch (input) {
		case 1:
			addClient();
			break;
		case 2:
			removeClient();
			break;
		case 3:
			printClients();
			break;
		case 4:addSupermarket();
			break;
		case 5:removerSupermarket();
			break;
		case 6:printSupermarkets();
			break;
		case 7:printClientsSupermarket();
			break;
		case 8:// routes
			break;
		case 9:// see time and distance routes
			break
		}
		if (!returnmenu())
			return;
	}
}

bool returnmenu() {
	char c;
	while (true) {
		cout << "\n\n\n Do you wish to return to main menu? (y/n)\n";
		cin >> c;
		if (c == 'y') {
			for (unsigned int j = 0; j < 10; j++)
				cout << "\n\n\n\n\n";
			return true;
		}
		return false;
	}
}

	void addClient() {
	int info;
	cout << "Vértices livres:\n";
	company->coutNodesAvailable();
	cout << "\n\n";
	cout << "Insira o ID do Vertice desejado, para adicionar cliente:\n";
	cin >> info;
	Graph * g = company->getGraph();
	Vertex * v = g->findVertex(info);
	string name;
	if (v == NULL) {
		if (company->isAvailable(info)) { // alterar isavailablre arguments
			cout << "\n Vertive livre! \nInsira agora o nome do Cliente a acrescentar:\n";
			cin.ignore();
			cin >> name;
			Client * c = new Client(v, name);
			company->addClient(c);
		}
		else
			cout << "\nVertice com ID inserido já ocupado!\n";
	} else
		cout << "\nVertice com ID inserido nao existe!\n";
}

void removeClient(){
	int info;
	cout << "Insira o ID do Vertice desejado, para remover cliente:\n";
	cin >> info;
	Graph * g = company->getGraph();
	Vertex * v = g->findVertex(info);
	if (v == NULL) {
		if (!company->isAvailable(info)) { // alterar isavailablre arguments to int in
			company->removeClient(info);
			cout << "\nVertice com ID inserido liberado!\n";
		}
		else {
			cout << "\nVertice com ID inserido não esta ocupado!\n";
		}
	} else
		cout << "\nVertice com ID inserido nao existe!\n";
}

void printClients() {
	cout << "Clients:\n";
	company->coutClients();
}

void addSupermarket(){
	int info;
	cout << "Vértices livres:\n";
	company->coutNodesAvailable();
	cout << "\n\n";
	cout << "Insira o ID do Vertice desejado, para adicionar supermercado:\n";
	cin >> info;
	Graph * g = company->getGraph();
	Vertex * v = g->findVertex(info);
	if (v == NULL) {
		if (company->isAvailable(info)) { // alterar isavailablre arguments
			cout << "\n Vertice livre! \nInsira agora o nome do Cliente a acrescentar:\n";
			Supermarket * s = new Supermarket(v);
			company->addSupermarket(s);
		}
		else {
			cout << "\nVertice com ID inserido já ocupado!\n";
		}
	} else
		cout << "\nVertice com ID inserido nao existe!\n";
}

void removerSupermarket(){
	int info;
	cout << "Insira o ID do Vertice desejado, para remover supermercado:\n";
	cin >> info;
	Graph * g = company->getGraph();
	Vertex * v = g->findVertex(info);
	if (v == NULL) {
		if (company->isAvailable(info)) { // alterar isavailablre arguments
			company->removeSupermarket(info); // alterar removesupermarket
		}
		else {
			cout << "\nVertice com ID inserido já ocupado!\n";
		}
	}
	else
		cout << "\nVertice com ID inserido nao existe!\n";
}

void printSupermarkets(){
	cout << "Clients:\n";
	company->coutSupermarkets();
}

void printClientsSupermarket(){
	int idoption;
	printSupermarkets();
	cout << "\n" << "Insert id of Supermarket you want:\n";
	cin >> idoption;
	cout << company->findSuper(idoption);
}
