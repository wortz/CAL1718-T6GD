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
	int input = -1;
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
		cout << " 10 - EXIT\n";
		cout << "\n" << "Chose an option: ";

		cin >> input;

		cin.clear();
		cin.ignore();
		switch (input) {
		case 1:
			lines();
			addClient();
			returnmenu();
			return;
		case 2:
			lines();
			removeClient();
			returnmenu();
			return;
		case 3:
			lines();
			printClients();
			returnmenu();
			return;
		case 4:
			lines();
			addSupermarket();
			returnmenu();
			return;
		case 5:
			lines();
			removerSupermarket();
			returnmenu();
			return;
		case 6:
			lines();
			printSupermarkets();
			returnmenu();
			return;
		case 7:
			lines();
			printClientsSupermarket();
			returnmenu();
			return;
		case 8:
			lines();
			printGraph();
			returnmenu();
			return;
		case 9:// see time and distance routes
			return;
		case 10:
			cout<<"\n\n\n\nExiting.\n";
			break;
		default:
			cout << "\n" << "";
			mainMenu();
			return;
		}
		 saveSupermarketsFile();
		 saveClientsFile();
}

void returnmenu() {
	char c;
	while (c!='y') {
		cout << "\n\n\nDo you wish to return to main menu? (y/n (EXIT) )\n";
		cin >> c;
		if (c == 'n')
			break;
		if (c == 'y') {
			for (unsigned int j = 0; j < 10; j++)
				cout << "\n\n\n\n\n";
			mainMenu();
		}
	}
}

	void addClient() {
	int info;
	cout << "Vertices livres:\n";
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
			cout << "\nVertice com ID inserido ja ocupado!\n";
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
	cout << "Supermarkets:\n";
	company->coutSupermarkets();
}

void printClientsSupermarket(){
	int idoption;
	printSupermarkets();
	cout << "\n" << "Insert id of Supermarket you want:\n";
	cin >> idoption;
	cout << company->findSuper(idoption);
}

void printGraph(){
	cout<< "Choose a supermarket ID:\n";
	printSupermarkets();
	cout<<endl;
	int sup=0;
	while(company->findSuper(sup)==NULL)
			cin>> sup;
	GraphViewer *gv = new GraphViewer(Width,Height, false);
	gv->setBackground("background.png"); //from 1.b)
	gv->createWindow(Width,Height);
	gv->defineEdgeColor("black");
	gv->defineEdgeCurved(false);
	auto vetor=company->createRote(sup);
	int u=0;
	for(unsigned int i=0;i<vetor.size();i++){
		gv->defineVertexColor("blue");
	    int index=vetor[i]->getIndex();
	    long long int a=vetor[i]->getInfo();
	    cout << index << " - " << a << endl;
		int x=coord2X(vetor[i]->getLon());
		int y=coord2Y(vetor[i]->getLat());
		gv->addNode(index,x,y);
		if (!company->isAvailable(a))
			gv->setVertexColor(index,"red");
		if(i==vetor.size()-1)
			gv->setVertexColor(index,"green");
	}
	for(unsigned int i=0;i<(vetor.size()-1);i++){
			long long int info1=vetor[i]->getInfo();
			long long int info2=vetor[i+1]->getInfo();
			auto e=company->getGraph()->findEdge(info1,info2);
			int index1=vetor[i]->getIndex();
			int index2=vetor[i+1]->getIndex();
			gv->addEdge(u,index1,index2,EdgeType::UNDIRECTED);
			u++;
	}
	gv->defineVertexSize(0.5);
	gv->rearrange();
	cin.ignore();
	getchar();
	gv->closeWindow();
}


void lines(){
	for (unsigned int j = 0; j < 10; j++)
				cout << "\n\n\n\n\n";
}

