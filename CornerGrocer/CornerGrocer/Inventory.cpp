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

// Reads a file and writes the produce items and its frequency that matches a user input
void Inventory::MenuOne() {
	ifstream inFS;
	ofstream outFS;

	string itemName;
	string userWord;

	cout << "Enter what item you would like to search: ";
	cin >> userWord;
	cout << endl;

	inFS.open(userFile);

	// Checks to see if the file could not be opened 
	if (!inFS.is_open()) {
		cout << "Could not open file " << userFile << endl;
	}

	while (getline(inFS, itemName)) {
		istringstream iss(itemName);
		string item;

		while (iss >> item) {
			if (item == userWord) {
				itemFrequency[item]++;
			}
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

// Reads a file and writes the produce names and their frequency
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

// Reads a text file and writes the produce items name and frequency in a histogram
void Inventory::MenuThree() {
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
			histogramFrequency[item] += "*";
		}
	}

	inFS.close();

	outFS.open("frequency.dat");

	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat" << endl;
	}

	for (const auto& pair : histogramFrequency) {
		outFS << pair.first << ": " << pair.second << endl;
	}

	outFS.close();
}

void Inventory::Menu() {
	string userItem;

	cout << "Corner Grocer" << endl;
	cout << "1. Display frequency for a specific item" << endl;
	cout << "2. Display a list of all items and their frequencies" << endl;
	cout << "3. Display histogram of all items" << endl;
	cout << "4. Exit application" << endl;
	cout << endl;

	cin >> userItem;

	while (userItem != "4") {

		if (userItem == "1") {
			MenuOne();
		}
		else if (userItem == "2") {
			MenuTwo();
		}
		else if (userItem == "3") {
			MenuThree();
		}
		else {
			cout << endl;
			cout << "That is not a valid entry" << endl;
			cout << endl;
		}

		cout << "Select another option: ";
		cin >> userItem;
	}

	cout << endl;
	cout << "Thank you, goodbye" << endl;
}