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
bool three_check(int num){
	while(num != 0){
		if(num % 10 == 3){
			return true;
		}
		else{
			num = num / 10;
		}
	}
	return false;
}

int main() {
	cout << "Challenge 1 ...\n";

	ifstream infile("numbers1.txt");
	vector<int> lines;
	string num;
	int sum = 0;

	if(infile.is_open()){
		while (!infile.eof()){
			getline(infile, num);
			int formatted_num = stoi(num);
			
			if(formatted_num < 0){
				formatted_num *= -1;
			}

			if(three_check(formatted_num)){
				lines.push_back(formatted_num);
			}
		}
		infile.close();
	}

	for(int i = 0; i <= lines.size(); i++){
		sum += lines[i];
		//cout << lines[i] << "	";
	}

	cout << "The sum of all numbers with the digit 3 is: " << sum;
	return 0;
	// ...
	// get each line and put them in a vector
	// go through each index and check if theres a three
	// sum += vector[i] if no three
}
