#include <iostream>
#include <string>

#include "random.h"

using std::string;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

// Check the error of cin input
bool cinErrorCheck () {
	bool cinError;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error: Invalid input, enter a number." << endl;
		cinError = true;
	} else {
		cinError = false;
	};
	return cinError;
};

int main () {
	cout << endl;	
	cout << "Welcome to Guess Number game! " << endl << endl;

	bool playing = true;
	int diff;
	string diffName;
	// cycle of game
	while (playing) {
		
		cout << "Choose difficulty:" << endl;	
		cout << "1 - easy" << endl << "2 - medium" << endl << "3 - hard" << endl << endl;
	
		diff = 0;
		diffName = "";
		cin >> diff;

		if (cinErrorCheck()) {
			continue;
		};

		int attempts = 0;
		bool easy = false;
		switch(diff) {
			case 1:
				attempts = 10;
				easy = true;
				diffName = "'easy'";
				break;
			case 2:
				attempts = 6;
				diffName = "'medium'";
				break;
			case 3:
				attempts = 4;
				diffName = "'hard'";
				break;
			default:
				cerr << "Error: wrong number." << endl;
				cerr << "Your number: " << diff << endl;
				cerr << "Need: 1-3" << endl;
				continue;
		};
		
		int theNumber = randomNumber() % 101;
		int guessedNumber = 0;
		bool win = false;
		cout << "Game started on difficulty " << diffName << endl;
		while (attempts > 0 and !win) {
			cout << "Attempts: " << attempts << endl;
			cout << "Guess number: ";
			cin >> guessedNumber;
			cout << endl;
			if (cinErrorCheck()) {
				continue;
			};
			if (guessedNumber == theNumber) {
				win = true;
			} else {
				if (guessedNumber > theNumber) {
					cout << "Number is lower than your." << endl;
				} else {
					cout << "Number is higher than your." << endl;
				};
			};
			attempts--;	
		};
		if (win) {
			cout << "You win!" << endl;
		} else {
			cout << "You loose(" << endl;
			cout << "The number was: " << theNumber << endl;
		};
		
		int exit = 0;
		while (exit != 1 and exit != 2) {
			cout << "Continue game?" << endl 
			     << "1 - continue" << endl 
			     << "2 - exit" << endl;
			cin >> exit;
			cout << endl;
			if (cinErrorCheck()) {
				continue;
			};
			switch (exit) {
				case 1:
					continue;
					break;
				case 2:
					playing = false;
					break;
				default:
					cerr << "Error: wrong number." << endl << endl;
					cerr << "Your number: " << diff << endl;
					cerr << "Need: 1-3" << endl;
					continue;
			};
		};
	};

	return 0;
}
