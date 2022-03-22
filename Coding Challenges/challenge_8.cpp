// challenge_8.cpp

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

int calculator(const vector<string>& v) {
	int ans = 0;
	if (v.size() == 1) {
		return stoi(v[0]);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == "@") {
			if (ans < stoi(v[i + 1])) {
				ans = stoi(v[i + 1]);
			}
			else {
				ans = stoi(v[i - 1]);
			}
		}

		if (v[i] == "+") {
			ans += stoi(v[i + 1]);
		}

		if (v[i] == "-") {
			ans -= stoi(v[i + 1]);
		}

		if (v[i] == "*") {
			ans *= stoi(v[i + 1]);
		}
	}
	return ans;
}

int main() {
	cout << "Challenge 8 ...\n";
	ifstream infile("expr8.txt");
	string equation;
	string temp;
	vector<string> terms;
	vector<int> sums;

	while(getline(infile, equation)) {
		for (int i = 0; i < equation.size(); i++) {
			if (equation[i] != ' ' && equation[i] != '\n') {
				temp += equation[i];
			}
			else {
				terms.push_back(temp);
				temp = "";
			}
		}
		terms.push_back(temp);
		temp = "";
		sums.push_back(calculator(terms));
	}

	int eights = 0;
	for (int i = 0; i < sums.size(); i++) {
		if (sums[i] % 8 == 0) {
			eights++;
		}
	}
	cout << "Number of sums that are multiples of eight is: " << eights << endl;
}
