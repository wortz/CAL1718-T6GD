#include "menu.h"


int main(){
<<<<<<< HEAD
	inicateApp();
=======
	readFiles();
	size_t input = 0;
	while (true) {
		vector<string> options = {
			"Adicionar cliente",
			"Remover cliente",
			"Adicionar Supermercado",
			"Remover Supermercado",
			"Teste com lista de clientes",
			"Teste com x clientes aleatórios"
		};

		for (size_t i = 0; i < options.size() - 1 ; i++) {
			cout << " " << i+1 << " - ";
			cout << options.at(i) << "\n";
		}
		cout << " 0 - SAIR\n";
		cout << "\n" << "Escolha a opcao desejada: ";
		cin >> input;

		/* validar input */
		if (input == 0 || input > options.size()) {
			system("cls");
			break;
		}

		switch (input) {
		case 1: // funçao 1
			break;
		case 2: // funçao 2
			break;
		case 3: // funçao 3
			break;
		case 4: // funçao 4
			break;
		case 5: // funçao 5
			break;
		}

		/* call function and clear console */
		system("cls");
		cin.ignore();
	}
>>>>>>> b1895458e880953ebcf8d78075ff30fbc7000879
}


