#include <iostream>
#include <fstream>
#include "BST.h"


using namespace std;

template<typename E, typename F>
void mainmenu(BST<E, F>);

int main() {
	BST<string, int> cityDatabase;
	ifstream myFile;
	string name;
	int* coordinates = new int[2];
	myFile.open("Cities.txt");

	myFile >> name >> coordinates[0] >> coordinates[1];
	while (!myFile.eof()) {
		cityDatabase.insert(name, coordinates);
		myFile >> name >> coordinates[0] >> coordinates[1];
	}

	cityDatabase.print();
	cityDatabase.remove("Atlanta");
	cityDatabase.print();
	

	system("pause");
}

template<typename E, typename F>
void mainmenu(BST<E, F> database) {

}