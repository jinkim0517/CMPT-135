// challenge_10.cpp

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

//
bool prime_check(const int& num) {
	if (num == 1) {
		return false;
	}
	for (int i = 2; i < num; i++) {
    	if (num % i == 0) {
      		return false;
		}

		if (i * i >= num) {
			break;
		}
    }
	return true;
}


bool productive_check(const int& num) {
	int product = 1;
	string s = to_string(num);
	for (int i = 0; i < s.size(); i++) {
		product *= (s[i] - '0');
	}
	if (prime_check(product + 1)) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	cout << "Challenge 10 ...\n";

	long sum = 0;
	int prod = 0;

	for (int i = 1; i <= 1000000; i++) {
		if (productive_check(i)) {
			prod++;
		}
		if (prime_check(i) && productive_check(i)) {
			sum += i;
		}
	}

	cout << "Sum of all productive primes is: " << sum << endl;
}
