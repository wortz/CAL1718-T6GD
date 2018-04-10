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
	while (returnmenu()) {
		vector<string> options = {
			"Add client.",
			"Remove client.",
			"See existent clients.",
			"Add Supermarket.",
			"Remove Supermarket.",
			"See existent Supermarkets.",
			"Routes."
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
			// funçao 3
			break;
		case 4:
			// funçao 4
			break;
		case 5:
			// funçao 5
			break;
		case 6:
			// funçao 6
			break;
		case 7:
			// funçao 7
			break;
		}
	}
	return;
}

bool returnmenu() {
	char c;
	while (true) {
		cout << "\n\n\n Do you wish to return to main menu? (y/n)\n";
		cin >> c;
		if (c == 'y') {
			for (unsigned int j = 0; j < 10; j++)
				cout << "\n\n\n\n\n";
			mainMenu();
		} else if (c == 'n')
			return false;
	}
}

void addClient() {
	int info;
	cout << "Insira o ID do Vertice desejado, para adicionar cliente:\n";
	cin >> info;
	Graph * g = company->getGraph();
	Vertex * v = g.findVertex(info);
	string name;
	if (v == NULL) {
		if (company->isAvailable(info)) { // alterar isavailablre arguments
			cout << "\n Vertive livre! \nInsira agora o nome do Cliente a acrescentar:\n";
			cin >> name;
			Client * c = new Client(v, name);
			company->addClient(c);
		}
		else {
			cout << "\nVertice com ID inserido já ocupado!\n";
		}
	} else
		cout << "\nVertice com ID inserido nao existe!\n";
}

void removeClient(){
	int info;
	cout << "Insira o ID do Vertice desejado, para adicionar cliente:\n";
	cin >> info;
	Graph * g = company->getGraph();
	Vertex * v = g.findVertex(info);
	string name;
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

void printClients(){
	cout << "Clients:\n";
	company->coutClients();
}

void addSupermarket(){

	/*company->isAvailable(....)            ver se o nó esta livre
	* company->addSupermarket(....)         se estiver livre adicionar
	*/
}

void removerSupermarket(){
	/*
	 * company->removeSupermarket(....)           se existir remover(return true se remover,false se nao existir)
	 */
}

void printSupermarkets(){
	/*
	 * company->coutClients()              dá print de todos os clientes
	 */
}
