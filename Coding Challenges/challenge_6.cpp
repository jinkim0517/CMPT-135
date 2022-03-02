// challenge_6.cpp

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

class letter {
private:
	char name;
	int frequency;

public:
	letter()
	:name(), frequency(0)
	{ }

	letter(char s) 
	:name(s), frequency(1)
	{ }

	void add_another() {
		frequency++;
	}

	char get_name() {
		return name;
	}

	int get_frequency() {
		return frequency;
	}
};

//
bool unique_check(char word, vector<letter> list) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i].get_name() == word) {
			return false;
		}
	}
	return true;
}

void add_to_list(char let, vector<letter> &list) {
	if (unique_check(let, list)) {
		letter new_letter(let);
		list.push_back(new_letter);
	}
	else {
		for (int i = 0; i < list.size(); i++) {
			if (list[i].get_name() == let) {
				list[i].add_another();
			}
		}
	}
}

void swap(letter *letter1, letter *letter2) 
{ 
    letter temp = *letter1; 
    *letter1 = *letter2; 
    *letter2 = temp; 
} 

void frequency_sort(vector<letter> &list) 
{ 
	// Referenced from https://www.geeksforgeeks.org/selection-sort/
    int i = 0;
	int j = 0;
	int min_value = 0;; 
  
    for (i = 0; i < list.size(); i++) 
    { 
        min_value = i; 
        for (j = i+1; j < list.size(); j++) {
			if (list[j].get_frequency() > list[min_value].get_frequency()) { 
				min_value = j; 
			}
			if (list[j].get_frequency() == list[i].get_frequency()) {
				if(list[j].get_name() < list[min_value].get_name()) {
					swap(&list[j], &list[i]);
				}
			}
		}
        swap(&list[min_value], &list[i]); 
    } 
} 

int main() {
	cout << "Challenge 6 ...\n";

	ifstream infile("words6.txt");
	char c;
	vector<letter> alphabet;

	while (infile.get(c)) {
		if (c != '\n') {
			add_to_list(c, alphabet);
		}
	}
	add_to_list(c, alphabet);

	frequency_sort(alphabet);

	string result;
	for (int i = 0; i < alphabet.size(); i++) {
		result += alphabet[i].get_name();
	}

	cout << "Resultant string is: " << result << endl;
}