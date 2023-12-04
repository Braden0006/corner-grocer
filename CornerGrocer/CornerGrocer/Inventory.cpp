#include "Inventory.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void Inventory::UserInputFile() {
	string inputFile;

	cout << "Enter the name of the text file: ";

	cin >> inputFile;

	userFile = inputFile;
}

void Inventory::MenuTwo() {
	ifstream inFS;
	ofstream outFS;

	string itemName;

	inFS.open(userFile);

	// Checks to see if the file could not be opened 
	if (!inFS.is_open()) {
		cout << "Could not open file " << userFile << endl;
	}

	while (getline(inFS, itemName)) {
		istringstream iss(itemName);
		string item;

		while (iss >> item) {
			itemFrequency[item]++;
		}
	}

	inFS.close();

	outFS.open("frequency.dat");

	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat" << endl;
	}

	for (const auto& pair : itemFrequency) {
		outFS << pair.first << ": " << pair.second << endl;
	}

	outFS.close();
}

void Inventory::Menu() {
	string userItem;

	cout << "Please select an option below: " << endl;
	cout << endl;
	cout << "Option 1 - 1" << endl;
	cout << "Option 2 - 2" << endl;
	cout << "Option 3 - 3" << endl;
	cout << endl;

	cin >> userItem;
}