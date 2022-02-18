// challenge_1.cpp

//
// You may use only the following #includes in your code:
//
#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
//
// You don't need to use them all, but you can't use any others. Don't change
// these in any way.

using namespace std;

// ... add any helper functions (write them yourself!) here ...

// Checks if there is a 3 in any of the digit places
bool three_check(int num) {
	// Gives the absolute value of the number
	if(num < 0) {
		num *= -1;
	}
	while(num != 0) {
		// Checks if one's place is a 3
		if(num % 10 == 3) {
			return true;
		}
		else {
			// Moves on to next place value
			num = num / 10;
		}
	}
	return false;
}

int main() {
	cout << "Challenge 1 ...\n";

	// Creates ifstream object
	ifstream infile("numbers1.txt");
	vector<int> lines;
	string num;
	int sum = 0;

	if(infile.is_open()) {
		while (getline(infile, num)) {
			// Reads in each line and formats the string to and integer
			int formatted_num = stoi(num);

			// Checks if there is a 3 and pushes into vector if false
			if(!three_check(formatted_num)) {
				lines.push_back(formatted_num);
			}
		}
		infile.close();
	}

	for(int i = 0; i <= lines.size() - 1; i++) {
		// Adds up all values in vector
		sum += lines[i];
	}

	cout << "The sum of all numbers without the digit 3 is: " << sum;
	return 0;
	// ...
	// get each line and put them in a vector
	// go through each index and check if theres a three
	// sum += vector[i] if no three
}