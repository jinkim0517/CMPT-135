// challenge_4.cpp

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

class item {
private:
	string name;
	int frequency;
public:
	item()
	: name(""), frequency(0)
	{ }

	item(string s)
	: name(s), frequency(1)
	{ }

	string get_name() {
		return name;
	}

	int get_frequency() {
		return frequency;
	}

	void add_another() {
		frequency++;
	}
};

bool unique_check(string word, vector<item> list) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i].get_name() == word) {
			return false;
		}
	}
	return true;
}

void add_to_list(string word, vector<item> &list) {
	if (unique_check(word, list)) {
		item new_item(word);
		list.push_back(new_item);
	}
	else {
		for (int i = 0; i < list.size(); i++) {
			if (list[i].get_name() == word) {
				list[i].add_another();
			}
		}
	}
}

void swap(item *item1, item *item2) 
{ 
    item temp = *item1; 
    *item1 = *item2; 
    *item2 = temp; 
} 

void frequency_sort(vector<item> &list) 
{ 
	// Referenced from https://www.geeksforgeeks.org/selection-sort/
    int i = 0;
	int j = 0;
	int min_value = 0;; 
  
    for (i = 0; i < list.size(); i++) 
    { 
        min_value = i; 
        for (j = i+1; j < list.size(); j++) {
			if (list[j].get_frequency() < list[min_value].get_frequency()) { 
				min_value = j; 
			}
			if (list[j].get_frequency() == list[i].get_frequency()) {
				if(list[j].get_name()[0] < list[min_value].get_name()[0]) {
					swap(&list[j], &list[i]);
				}
			}
		}
        swap(&list[min_value], &list[i]); 
    } 
} 

int main() {
	cout << "Challenge 4 ...\n";
	
	ifstream infile("baskets.txt");
	char c;
	string word;
	vector<item> items;

	while (infile.get(c)) {
		if (c != ' ' && c != '\n') {
			word += c;
		}
		else {
			add_to_list(word, items);
			word = "";
		}
	}
	add_to_list(word, items);

	frequency_sort(items);
	cout << "Most Bought Item: " << items[items.size() - 1].get_name() << " (";
	cout << items[items.size() - 1].get_frequency() << " purchases)" << endl;

	cout << "Second Most Bought Item: " << items[items.size() - 2].get_name() << " (";
	cout << items[items.size() - 2].get_frequency() << " purchases)" << endl;

	cout << "Third Most Bought Item: " << items[items.size() - 3].get_name() << " (";
	cout << items[items.size() - 3].get_frequency() << " purchases)" << endl;
}
