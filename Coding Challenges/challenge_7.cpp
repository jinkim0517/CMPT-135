// challenge_7.cpp

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

int main() {
	cout << "Challenge 7 ...\n";

	ifstream infile("bits7.txt");

	vector<int> columns_sums;
	string row;
	int max_value = 0;
	int highest_column = 0;

	for (int i = 0; i < 500; i++) {
		columns_sums.push_back(0);
	}

	while (getline(infile, row)) {
		for (int n = 0; n < 500; n++) {
			// cout << row[n] << endl;
			if (row[n] == '1') {
				columns_sums[n] += 1;
			}
		}
	}

	for (int i = 0; i < columns_sums.size(); i++) {
		if (columns_sums[i] >= max_value) {
			max_value = columns_sums[i];
			highest_column = i;
		}
	}

	cout << "The column with the highest sum is: Column " << highest_column << " with a sum of "
		 << max_value << ".\n";
}
