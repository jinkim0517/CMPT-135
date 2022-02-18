// challenge_5.cpp

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
void string_words(const string &s, vector<string> &output)
{
	// Referenced from: https://www.cplusplus.com/forum/beginner/99171/
    int start = 0;
    int last = s.find_first_of(", ");

    while (last != string::npos)
    {
        if (last > start)
        {
            output.push_back(s.substr(start, last - start));
        }

        start = ++last;
        last = s.find_first_of(", ", last);
    }
    output.push_back(s.substr(start));
}

double select_min(vector<double> num) {
	double min_value = num[0];
	for (int i = 0; i < num.size(); i++) {
		if (num[i] < min_value) {
			min_value = num[i];
		}
	}
	return min_value;
}

double select_max(vector<double> num) {
	double max_value = num[0];
	for (int i = 0; i < num.size(); i++) {
		if (num[i] > max_value) {
			max_value = num[i];
		}
	}
	return max_value;
}
//

int main() {
	cout << "Challenge 5 ...\n";

	ifstream infile("numbers5.txt");
	string word;
	vector<double> min_nums;
	vector<double> max_nums;

	while (getline(infile, word)) {
		vector<string> string_numbers;
		vector<double> double_numbers;
		string_words(word, string_numbers);
		for (int i = 0; i < string_numbers.size(); i++) {
			double_numbers.push_back(stod(string_numbers[i]));
		}
		min_nums.push_back(select_min(double_numbers));
		max_nums.push_back(select_max(double_numbers));
	}

	cout << "The minimum value of all maximums is (A): " << select_min(max_nums) << endl;
	cout << "The maximum value of all minimums is (B): " << select_max(min_nums) << endl;
}
