#include <iostream>
#include <fstream>
#include <iomanip>
#include "BST.h"


using namespace std;

template<typename E, typename F>
void mainmenu(BST<E, F>&);

int main() {
	BST<string, int> cityDatabase;
	ifstream myFile;
	string name;
	myFile.open("Cities.txt");
	cout << setprecision(2) << fixed;

	while (!myFile.eof()) {
		int* coordinates = new int[2];
		myFile >> name >> coordinates[0] >> coordinates[1];
		cityDatabase.insert(name, coordinates);		
	}

	mainmenu(cityDatabase);
}

template<typename E, typename F>
void mainmenu(BST<E, F>& database) {
	int choice;
	double distance;
	string cityName;
	int* coordinates = new int[2];
	cout << "Welcome to the City Coordinate Database" << endl;
	cout << "Please select an option from the list below." << endl;
	cout << "1. Display the current database." << endl;
	cout << "2. Insert a city with given coordinates." << endl;
	cout << "3. Remove a city from the database (by name only)." << endl;
	cout << "4. Print all cities within a given distance of a particular point." << endl;
	cout << "5. Close the program." << endl;
	cout << "Choice -> ";
	cin >> choice;
	switch (choice) {
	case 1:
		system("CLS");
		cout << "The current database holds: " << endl;
		database.print();
		cout << endl;
		mainmenu(database);
		break;
	case 2:
		cout << "Please enter the city name: ";
		cin >> cityName;
		cout << "Please enter the city coordinates (x y): ";
		cin >> coordinates[0] >> coordinates[1];
		database.insert(cityName, coordinates);
		system("CLS");
		mainmenu(database);
		break;
	case 3:
		cout << "Please enter the city name to be removed: ";
		cin >> cityName;
		database.remove(cityName);
		system("CLS");
		cout << cityName << " has been removed.\n" << endl;
		mainmenu(database);
		break;
	case 4:
		cout << "Please enter a coordinate you would like to check (x y): ";
		cin >> coordinates[0] >> coordinates[1];
		cout << "Please enter a distance to display all cities within the given distance to the point: ";
		cin >> distance;
		system("CLS");
		cout << "Cities within the given distance are as follows: " << endl;
		database.printClose(coordinates, distance);
		cout << endl;
		mainmenu(database);
		break;
	case 5:
		return;
		break;
	}
}