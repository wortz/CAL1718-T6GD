/*
 * menu.cpp
 *
 *  Created on: 09/04/2018
 *      Author: Asus
 */

#include "menu.h"


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
					"Rotas."
				};

				for (size_t i = 0; i < options.size() - 1 ; i++) {
					cout << " " << i+1 << " - ";
					cout << options.at(i) << "\n";
				}
				cout << " 0 - SAIR\n";
				cout << "\n" << "Escolha a opcao desejada: ";
				cin >> input;

				if(!(input>=0&&input<=options.size())){
					cout << "\n" << "";
				}

				/* validar input */
				if (input == 0) {
					system("cls");
					break;
				}

				switch (input) {
				case 1:
					addClient();
					break;
				case 2: // funçao 2
					break;
				case 3: // funçao 3
					break;
				case 4: // funçao 4
					break;
				case 5: // funçao 5
					break;
				case 6:
					break;
				case 7:
					break;
				}

				/* call function and clear console */
				system("cls");
				cin.ignore();
		}
}

void addClient() {
	/*company->isAvailable(....)            ver se o nó esta livre
	* company->addSupermarket(....)         se estiver livre adicionar
	*/
}

void removeClient(){
	/*
	 * company->removeClient(....)           se existir remover(return true se remover,false se nao existir)
	 */
}

void printClients(){
	/*
	 * company->coutClients()              dá print de todos os clientes
	 */
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
