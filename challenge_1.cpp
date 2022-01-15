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

//
// ... add any helper functions (write them yourself!) here ...
//

int main() {
	cout << "Challenge 1 ...\n";

	ifstream infile("numbers.txt");
	vector<int> lines;
	string num = 0;

	if(infile.is_open()){
		while (!infile.eof()){
			getline(infile, num);
			lines.push_back(stoi(num));
		}
		infile.close();
	}

	for(int i = 0; i < lines.size(); i++){
		cout << lines[i] << endl;
	}
	return 0;
	// ...
	// get each line and put them in a vector
	// go through each index and check if theres a three
	// sum += vector[i] if no three
}
