// a4.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Jinsung Kim
// St.# : 301539203
// Email: jka287@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough detail
// so that someone can see the exact source and extent of the borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have not
// seen solutions from other students, tutors, websites, books, etc.
//
/////////////////////////////////////////////////////////////////////////

#include "a4.h"  // no other includes are allowed!

using namespace std;

int sum_of_squares(int n) {
    assert(n >= 0);
    int result = 0;
    if (n == 0) {
        return result;
    }
    else {
        result += (n * n) + sum_of_squares(n - 1);
    }
    return result;
}

void sum_of_squares_test() {
    assert(sum_of_squares(0) == 0);
    cout << "Sum of Squares Test 1 Passed...\n";

    assert(sum_of_squares(100) == 338350);
    cout << "Sum of Squares Test 2 Passed...\n";

    assert(sum_of_squares(1) == 1);
    cout << "Sum of Squares Test 3 Passed!\n";

    cout << "--------------------------------\n";
}

int count_strange(int n) {
    assert(n > 0);
    int count = 0;
    if (n == 1) {
        count++;
        return count;
    }
    else {
        // If even, change to odd
        if (n % 2 == 0) {
            n--;
			}
        else {
			if (!(n % 5 == 0)) {
            	count++;
			}
            // If odd, keep odd
			n -= 2;
        }
		count += count_strange(n);
    }
    return count;
}

void count_strange_test() {
    assert(count_strange(15) == 6);
    cout << "Count Strange Test 1 Passed...\n";

    assert(count_strange(1) == 1);
    cout << "Count Strange Test 2 Passed...\n";

    assert(count_strange(24) == 10);
    cout << "Count Strange Test 3 Passed!\n";

    cout << "--------------------------------\n";
}

bool all_sfu(const string& s) {
    bool result = false;
    if (s.size() == 0) {
        return true;
    }
    if (s[0] == 's' || s[0] == 'f' ||s[0] == 'u') {
        result = true;
    }
    if (!result) {
        return false;
    }
    return all_sfu(s.substr(1));
}

void all_sfu_test() {
    assert(all_sfu("sfusfuuuuu"));
    cout << "All SFU Test 1 Passed...\n";

    assert(all_sfu(""));
    cout << "All SFU Test 2 Passed...\n";

    assert(!all_sfu("HELLO"));
    cout << "All SFU Test 3 Passed...\n";

    assert(!all_sfu("                         "));
    cout << "All SFU Test 4 Passed...\n";

    assert(!all_sfu("Sfuuuuuu"));
    cout << "All SFU Test 5 Passed!\n";

    cout << "--------------------------------\n";
}

bool is_int(const string& s) {
    bool result = false;
    if (s == "") {
        return false;
    }

    if (s[0] == '-' || s[0] == '0' || s[0] == '1' ||s[0] == '2' || s[0] == '3' || s[0] == '4' ||
    s[0] == '5' || s[0] == '6' ||s[0] == '7' || s[0] == '8' || s[0] == '9') {
        result = true;
    }
    else {
        return false;
    }

    // Checks next character in the string when size is 2 instead of checking first character when
    // size is 0 (returns false)
    if (s.size() == 2) {
        if ((s[1] == '-' || s[1] == '0' || s[1] == '1' ||s[1] == '2' || s[1] == '3' || s[1] == '4'
        || s[1] == '5' || s[1] == '6' ||s[1] == '7' || s[1] == '8' || s[1] == '9') && result) {
            return true;
        }
    }

    if (!result) {
        return false;
    }
    return is_int(s.substr(1));
}

void is_int_test() {
    assert(is_int("123456789"));
    cout << "Is Int Test 1 Passed...\n";

    assert(!is_int("   1234 56"));
    cout << "Is Int Test 2 Passed...\n";

    assert(!is_int(""));
    cout << "Is Int Test 3 Passed...\n";

    assert(is_int("-543"));
    cout << "Is Int Test 4 Passed!\n";

    cout << "--------------------------------\n";
}

string strip(const string& s) {
    string temp = s;
	bool change = false;
    if (temp[0] == ' ') {
        temp = temp.substr(1);
		change = true;
    }
	if (temp[temp.size() - 1] == ' ') {
        temp = temp.substr(0, temp.size() - 1);
		change = true;
    }
	if (change) {
    	return strip(temp);
	}
	else {
		return temp;
	}
}

void strip_test() {
    string test1 = "   three spaces   ";
    assert(strip(test1) == "three spaces");
    cout << "Strip Test 1 Passed...\n";

    string test2 = "   ";
    assert(strip(test2) == "");
    cout << "Strip Test 2 Passed...\n";

    string test3 = "";
    assert(strip(test3) == "");
    cout << "Strip Test 3 Passed...\n";

    string test4 = "   \nhello";
    assert(strip(test4) == "\nhello");
    cout << "Strip Test 4 Passed!\n";

    cout << "--------------------------------\n";
}

int sum_neg(const vector<int>& v) {
    int sum = 0;
    if (v.size() != 0 && v[0] < 0) {
        sum += v[0];
    }
    if (v.size() == 0) {
        return sum;
    }
    else {
        vector<int> temp = v;
        temp.erase(temp.begin());
        sum += sum_neg(temp);
    }
    return sum;
}

void sum_neg_test() {
    vector<int> test;
    test.push_back(-1);
    test.push_back(10);
    test.push_back(4);
    test.push_back(-10);
    test.push_back(-4);
    test.push_back(0);
    assert(sum_neg(test) == -15);
    cout << "Sum of Negatives Test 1 Passed...\n";

    test.push_back(-7);
    assert(sum_neg(test) == -22);
    cout << "Sum of Negatives Test 2 Passed...\n";

    test.push_back(5);
    assert(sum_neg(test) == -22);
    cout << "Sum of Negatives Test 3 Passed...\n";

    vector<int> test4;
    assert(sum_neg(test4) == 0);
    cout << "Sum of Negatives Test 4 Passed!\n";

    cout << "--------------------------------\n";
}

vector<int> max_vec(const vector<int>& a, const vector<int>& b) { 
    assert(a.size() == b.size());
    vector<int> result;
    int max = 0;
    if (a[0] > b[0]) {
        max = a[0];
    }
    else {
        max = b[0];
    }
	
    if (a.size() <= 1) {
        result.push_back(max);
        return result;
    }
	else {
		vector<int> temp_a = a;
    	vector<int> temp_b = b;
		temp_a.erase(temp_a.begin());
	    temp_b.erase(temp_b.begin());
		result = max_vec(temp_a, temp_b);
	    result.insert(result.begin(), max);
	}

    return result;
}

void max_vec_test() {
    vector<int> test_a;
    vector<int> test_b;
    test_a.push_back(-1);
    test_a.push_back(10);
    test_a.push_back(3);
    test_a.push_back(0);

    test_b.push_back(-1);
    test_b.push_back(2);
    test_b.push_back(17);
    test_b.push_back(-10);

    vector<int> test_c = max_vec(test_a, test_b);

    assert(test_c[0] == -1);
    cout << "Max Vector Test 1 Passed...\n";

    assert(test_c[1] == 10);
    cout << "Max Vector Test 2 Passed...\n";

    assert(test_c[2] == 17);
    cout << "Max Vector Test 3 Passed...\n";

    assert(test_c[3] == 0);
    cout << "Max Vector Test 4 Passed...\n";

    assert(test_c.size() == 4);
    cout << "Max Vector Test 5 Passed!\n";

    cout << "--------------------------------\n";
}

int count(const vector<string>& v, const string& s) {
    int count_s = 0;
    if (v.size() == 0) {
        return count_s;
    }
    else if (v[0] == s) {
        count_s++;
        vector<string> temp_v = v;
        temp_v.erase(temp_v.begin());
        count_s += count(temp_v, s);
    }
    else {
        vector<string> temp_v = v;
        temp_v.erase(temp_v.begin());
        count_s += count(temp_v, s);
    }
    return count_s;
}

void count_test() {
    vector<string> test;
    test.push_back("Hello");
    test.push_back("hi");
    test.push_back("apple");
    test.push_back("Hello");
    test.push_back("Hello");

    assert(count(test, "Hello") == 3);
    cout << "Count Test 1 Passed...\n";

    assert(count(test, "hi") == 1);
    cout << "Count Test 2 Passed...\n";

    assert(count(test, "") == 0);
    cout << "Count Test 3 Passed...\n";

    assert(count(test, "APPLE") == 0);
    cout << "Count Test 4 Passed...\n";

    vector<string> test5;
    assert(count(test5, "") == 0);
    cout << "Count Test 5 Passed!\n";

    cout << "--------------------------------\n";
}

vector<string> zip(const string& s, const string& t) {
    assert(s.size() == t.size());
    vector<string> result;

    if (s.size() == 0) {
        return result;
    }
    else {
		string temp_s = s;
		string temp_t = t;
        string sum = temp_s.substr(0, 1) + temp_t.substr(0, 1);
		result = zip(temp_s.substr(1), temp_t.substr(1));
		result.insert(result.begin(), sum);
    }
	return result;
}

void zip_test() {
	string test1_a = "hlo";
	string test1_b = "el!";
	vector<string> test1_c = zip(test1_a, test1_b);

	assert(test1_c[0] == "he");
    assert(test1_c[1] == "ll");
    assert(test1_c[2] == "o!");
    cout << "Zip Test 1 Passed...\n";

    string test2_a;
	string test2_b;
	vector<string> test2_c = zip(test2_a, test2_b);

	assert(test2_c.size() == 0);
    cout << "Zip Test 2 Passed...\n";

	string test3_a = " 1 ";
	string test3_b = "2 4";
	vector<string> test3_c = zip(test3_a, test3_b);

	assert(test3_c[0] == " 2");
    assert(test3_c[1] == "1 ");
    assert(test3_c[2] == " 4");
    cout << "Zip Test 3 Passed!\n";

    cout << "--------------------------------\n";
}

string join(const vector<string>& v, const string& sep) {
    string result;
    if (v.size() == 0) {
        return result;
    }
    else if (v.size() != 1) {
        result += v[0] + sep;
    }
    else {
        result += v[0];
    }
    vector<string> temp = v;
    temp.erase(temp.begin());

    result += join(temp, sep);

    return result;
}

void join_test() {
    vector<string> test;
    test.push_back("Hello,");
    test.push_back("I");
    test.push_back("am");
    test.push_back("JIN");
    test.push_back("KIM!!!!");

    assert(join(test, " ") == "Hello, I am JIN KIM!!!!");
    cout << "Join Test 1 Passed...\n";

    assert(join(test, "-") == "Hello,-I-am-JIN-KIM!!!!");
    cout << "Join Test 2 Passed...\n";

    assert(join(test, "") == "Hello,IamJINKIM!!!!");
    cout << "Join Test 3 Passed...\n";

    vector<string> test4;
    assert(join(test4, "-") == "");
    cout << "Join Test 4 Passed!\n";
}