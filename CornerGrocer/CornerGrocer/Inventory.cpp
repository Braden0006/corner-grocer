#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <string>

void Inventory::InventoryList() {
	ifstream inFS;
	ofstream outFS;

	string inputFile;

	string itemName;

	cin >> inputFile;

	inFS.open(inputFile);

	// Checks to see if the file could not be opened 
	if (!inFS.is_open()) {
		cout << "Could not open file " << inputFile << endl;
	}

	inFS >> itemName;

	while (!inFS.fail()) {
		items.push_back(itemName);

		inFS >> itemName;
	}

	inFS.close();

	outFS.open("frequency.dat");

	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat" << endl;
	}

	outFS.close();
}