// challenge_3.cpp

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

// Counts number of a's in a word
int a_check(string line) {
	int num_of_a = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == 'a') {
			num_of_a++;
		}
	}
	return num_of_a;
}

// Counts number of e's in a word
int e_check(string line) {
	int num_of_e = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == 'e') {
			num_of_e++;
		}
	}
	return num_of_e;
}

// Counts number of i's in a word
int i_check(string line) {
	int num_of_i = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == 'i') {
			num_of_i++;
		}
	}
	return num_of_i;
}

// Counts number of o's in a word
int o_check(string line) {
	int num_of_o = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == 'o') {
			num_of_o++;
		}
	}
	return num_of_o;
}

// Counts number of u's in a word
int u_check(string line) {
	int num_of_u = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == 'u') {
			num_of_u++;
		}
	}
	return num_of_u;
}

// Checks if a word contains all five vowels exactly once
bool vowel_check(string line) {
	if (a_check(line) == 1 && e_check(line) == 1 && i_check(line) == 1) {
		if (o_check(line) == 1 && u_check(line) == 1){
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
int main() {
	cout << "Challenge 3 ...\n";
	
	ifstream infile("enable1.txt");
	string line;
	int correct_words = 0;

	while (infile.is_open()) {
		while (getline(infile, line)) {
			if (vowel_check(line)) {
				correct_words++;
			}
		}
		infile.close();
	}

	cout << "Number of words that contain all five vowels exactly once: "
		 << correct_words;

	return 0;
}