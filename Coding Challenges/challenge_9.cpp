// challenge_9.cpp

//
// You may use only the following #includes in your code:
//
#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//
// You don't need to use them all, but you can't use any others. Don't change
// these in any way.

using namespace std;

void swap(string& s, int a, int b) {
	char temp = s[a];
	s[a] = s[b];
	s[b] = temp;
}

void vector_swap(vector<string>& s, int a, int b) {
	string temp = s[a];
	s[a] = s[b];
	s[b] = temp;
}

void letter_sort(string& s) {
	for (int x = 0; x < s.size(); x++) {
		for(int i = 0; i < s.size() - 1; i++) {
			if (s[i] > s[i + 1]) {
				swap(s, i + 1, i);
			}
		}
	}
}

void vector_sort(vector<string>& s, vector<string>& index) {
	for (int x = 0; x < s.size(); x++) {
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i][0] > (s[i + 1][0])) {
				vector_swap(s, i, i + 1);
				vector_swap(index, i, i + 1);
			}
			else if (s[i][0] == (s[i + 1][0])) {
				for(int a = 0; a < s[i].size(); a++) {
					if (s[i][a] > (s[i + 1][a])) {
						vector_swap(s, i, i + 1);
						vector_swap(index, i, i + 1);
						a = s[i].size();
					}
				}
			}
		}
	}
}

int main() {
	cout << "Challenge 9 ...\n";
	ifstream infile("words9.txt");
	string word;
	vector<string> four_plus;
	vector<string> index;
	int i = 1;

	while (getline(infile, word)) {
		if (word.size() > 4) {
			index.push_back(to_string(i));
			four_plus.push_back(word);
		}
		i++;
	}

	for (int i = 0; i < four_plus.size(); i++) {
		letter_sort(four_plus[i]);
	}

	vector_sort(four_plus, index);

	cout << four_plus[12345] << endl;
}
