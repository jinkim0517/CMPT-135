// challenge_2.cpp

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

struct file_data {
	int different = 0;
	int repeated = 0;
	int ordinary = 0;
	int total_words = 0;
};

//
// ... add any helper functions (write them yourself!) here ...
bool different_check (string line) {
	if (line.size() == 1) {
		return true;
	}

	for (int i = 0; i < line.length() - 1; i++) {
        for (int j = i + 1; j < line.length(); j++) {
            if (line[i] == line[j]) {
                return false;
            }
        }
    }
    return true;
}

bool repeated_check (string line) {
	bool result = false;
	int first_letter = 0;

	if (line.size() == 1) {
		return true;
	}

	for (int i = 0; i < line.size(); i++){
		if (line[first_letter] == line[i]){
			result = true;
		}
		else return false;
	}
	return result;
}

int main() {
	cout << "Challenge 2 ...\n";

	ifstream infile("strings2.txt");
	string words;
	file_data input_file;

	while (infile.is_open()) {
		while (getline(infile, words)) {
			// Checks if there is a 3 and pushes into vector if false
			if (!different_check(words) && !repeated_check(words)) {
				input_file.ordinary++;
				cout << words << endl;
			}
			else if (words.size() == 1) {
				input_file.different++;
				input_file.repeated++;
			}
			else if (words.size() == 0) {
				input_file.ordinary++;
			}
			else if (different_check(words)) {
				input_file.different++;
			}
			else {
				input_file.repeated++;
				cout << words << endl;
			}
		}
		infile.close();
	}
	
	cout << "Different:" << setw(5) << input_file.different << endl;
	cout << "Repeated:"  << setw(6) << input_file.repeated  << endl;
	cout << "Ordinary:"  << setw(6) << input_file.ordinary  << endl;

	return 0;
}