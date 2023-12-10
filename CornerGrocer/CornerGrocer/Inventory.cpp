#include "Inventory.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Reads a file and writes the produce items and its frequency that matches a user input
void Inventory::MenuOne() {

	// Clears the map so no value is called multiple times when the function is called more than once
	itemFrequency.clear();

	ifstream inFS;
	ofstream outFS;

	string itemName;
	string userWord;

	cout << endl;
	cout << "Enter what item you would like to search: ";
	cin >> userWord;
	cout << endl;

	inFS.open(userFile);

	// Checks to see if the file could not be opened 
	if (!inFS.is_open()) {
		cout << "Could not open file " << userFile << endl;
	}

	// Reads each line and compares each word in userFile to userWord
	while (getline(inFS, itemName)) {
		istringstream iss(itemName);
		string item;

		while (iss >> item) {
			if (item == userWord) {
				itemFrequency[item]++;
			}
		}
	}

	// Closes text file
	inFS.close();

	// Opens a new text file
	outFS.open("frequency.dat");

	// Checks to see if the file could not be opened
	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat" << endl;
	}

	// Iterates through itemFrequency and writes each pair to the text file, while also displaying each item to the terminal
	for (const auto& pair : itemFrequency) {
		outFS << pair.first << ": " << pair.second << endl;
		cout << pair.first << ": " << pair.second << endl;
	}

	// Closes text file
	outFS.close();
}

// Reads a file and writes the produce names and their frequency
void Inventory::MenuTwo() {

	// Clears the map so no value is getting added multiple times when the function is called more than once
	itemFrequency.clear();

	ifstream inFS;
	ofstream outFS;

	string itemName;

	inFS.open(userFile);

	// Checks to see if the file could not be opened 
	if (!inFS.is_open()) {
		cout << "Could not open file " << userFile << endl;
	}

	// Reads each line and adds the item to the map, while also adding a number next to it if their are more than one occurences of the same item
	while (getline(inFS, itemName)) {
		istringstream iss(itemName);
		string item;

		while (iss >> item) {
			itemFrequency[item]++;
		}
	}

	// Closes text file
	inFS.close();

	// Opens a new text file
	outFS.open("frequency.dat");

	// Checks to see if the file could not be opened
	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat" << endl;
	}

	// Iterates over itemFrequency and writes them to the output file, while also displaying each item to the terminal
	for (const auto& pair : itemFrequency) {
		outFS << pair.first << ": " << pair.second << endl;
		cout << pair.first << ": " << pair.second << endl;
	}

	outFS.close();
}

// Reads a text file and writes the produce items name and frequency in a histogram
void Inventory::MenuThree() {

	// Clears everything in the map, so nothing gets added multiple times when the function is called more than once
	histogramFrequency.clear();

	ifstream inFS;
	ofstream outFS;

	string itemName;

	inFS.open(userFile);

	// Checks to see if the file could not be opened 
	if (!inFS.is_open()) {
		cout << "Could not open file " << userFile << endl;
	}

	// Reads each line and adds the item to the map, while also adding an asterisk next to it if their are more than one occurences of the same item
	while (getline(inFS, itemName)) {
		istringstream iss(itemName);
		string item;

		while (iss >> item) {
			histogramFrequency[item] += "*";
		}
	}

	// Closes the text file
	inFS.close();

	// Opens a new text file
	outFS.open("frequency.dat");

	// Checks to see if the file could not be opened
	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat" << endl;
	}

	// Iterates over histogramFrequency and writes each item to the output file, while also displaying each item to the terminal
	for (const auto& pair : histogramFrequency) {
		outFS << pair.first << ": " << pair.second << endl;
		cout << pair.first << ": " << pair.second << endl;
	}

	// Closes the file
	outFS.close();
}

void Inventory::Menu() {
	string userItem;

	cout << "Corner Grocer" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "1. Display frequency for a specific item" << endl;
	cout << "2. Display a list of all items and their frequencies" << endl;
	cout << "3. Display histogram of all items" << endl;
	cout << "4. Exit application" << endl;
	cout << "Please enter your selection as a number 1-4: ";

	// User input
	cin >> userItem;

	// Runs the function that the user input selects
	while (userItem != "4") {

		if (userItem == "1") {
			MenuOne();
		}
		else if (userItem == "2") {
			cout << endl;
			MenuTwo();
		}
		else if (userItem == "3") {
			cout << endl;
			MenuThree();
		}
		else {
			cout << endl;
			cout << "That is not a valid entry" << endl;
			cout << endl;
		}

		cout << endl;
		cout << "Select another option: ";
		cin >> userItem;
	}

	cout << endl;
	cout << "Thank you, goodbye" << endl;
}