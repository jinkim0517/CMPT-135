// a2.cpp

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

//
// These are the only permitted includes: don't include anything else.
//
#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class str_vec {
private:
  int arr_capacity;
  int arr_size;
  string* arr;

public:
  str_vec()
  : arr_capacity(10), arr_size(0), arr(new string[arr_capacity])
  { }

  str_vec(int n, string s) 
  : arr_capacity(2 * n + 1), arr_size(n)
  {
    if (n < 0) {
      cmpt::error("str_vec: n must be 0 or greater");
    }
    arr = new string[arr_capacity];
    for (int i = 0; i < n; i++) {
      arr[i] = s;
    }
  }

  str_vec(const str_vec& other)
  : arr_capacity(other.arr_capacity), arr_size(other.arr_size), arr(new string[arr_capacity])
  { 
    for (int i = 0; i < arr_size; i++) {
      arr[i] = other.arr[i];
    }
  }

  string join(string sep) {
    string result;
    for (int i = 0; i < arr_size; i++) {
      if (i == arr_size - 1) {
        result += arr[i];
      }
      else {
      result += arr[i] + sep;
      }
    }
    return result;
  }

  string to_string() const {
    string result = "{\"";
    if (arr_size == 0) {
      result += "\"}";
    }
    for (int i = 0; i < arr_size; i++) {
      if (i == arr_size - 1) {
        result += arr[i] + "\"}";
      }
      else {
        result += arr[i] + "\", \"";
      }
    }
    return result;
  }

  string get(int i) const {
    if (arr_size != 0){
      if (i < 0 || i > arr_size - 1) {
        cmpt::error("get(): index must be within boundaries");
      }
    }
    return arr[i];
  }

  void set(int i, string s) {
    if (i < 0 || i > arr_size - 1) {
      cmpt::error("set(): index must be within boundaries");
    }
    arr[i] = s;
  }

  void append(string s) {
    if (arr_size >= arr_capacity) {
      arr_capacity *= 2;
      string* temp_arr = new string[arr_capacity];

      for (int i = 0; i < arr_size; i++) {
        temp_arr[i] = arr[i];
      }
      arr = temp_arr;
    }

    arr[arr_size] = s;
    arr_size++;
  }

  void append_new(string s) {
    bool repeat_check = false;
    for (int i = 0; i < arr_size; i++) {
      if (arr[i] == s) {
        repeat_check = true;
      }
    }
    if (!repeat_check) {
      append(s);
    }
  }

  void remove_white_space(string& s) {
    int beginning = s.find_first_not_of(' ');
    int ending = s.find_last_not_of(' ');
    string new_string;

    for (int i = beginning; i <= ending; i++) {
      new_string += s[i];
    }
    s = new_string;
  }

  void trim_all() { 
    for (int i = 0; i < arr_size; i++) {
      remove_white_space(arr[i]);
    }
  }

  void remove(int i) {
    if (i < 0 || i >= arr_size) {
      cmpt::error("remove(): index must be within boundaries");
    }

    arr[i] = "";
    for (int x = i; x < arr_size - 1; x++) {
      arr[x] = arr[x + 1];
    }

    arr[arr_size - 1] = "";
    arr_size = arr_size - 1;
  }

  void keep_all_starts_with(char c) {
    string word;
    for (int i = 0; i < arr_size; i++) {
      word = arr[i];
      if (word[0] != c) {
        remove(i);
      }
    }
  }

  void clear() {
    arr = new string[arr_capacity];
  }

  void squish() {
    arr_capacity = arr_size;
    string* temp_arr = arr;
    arr = new string[arr_capacity];
    
    for (int i = 0; i < arr_capacity; i++) {
      arr[i] = temp_arr[i];
    }
  }

  void print() const {
    cout << to_string();
  }

  void println() const {
    cout << to_string() << "\n";
  }

  int size() const {return arr_size;}
  int capacity() const {return arr_capacity;}
  double pct_used() const {return (arr_size * 1.0) / (arr_capacity * 1.0);}

  ~str_vec() {
    delete[] arr;
  }
}; // class str_vec

bool operator==(str_vec a, str_vec b) {
  bool result = false;
  if (a.size() == b.size()) {
    for (int i = 0; i < a.size(); i++) {
      if (a.get(i) == b.get(i)) {
        result = true;
      }
      else {
        return false;
      }
    }
  }
  else {
    return false;
  }
  return result;
}

bool operator!=(str_vec a, str_vec b) {
  bool result = true;
  if (a.size() == b.size()) {
    for (int i = 0; i < a.size(); i++) {
      if (a.get(i) == b.get(i)) {
        result = false;
      }
      else {
        return true;
      }
    }
  }
  else {
    return true;
  }
  return result;
}

void default_initialization_test() {
  str_vec test;

  assert(test.size() == 0);
  cout << "Default Initilazation Test 1 Passed...\n";

  assert(test.capacity() == 10);
  cout << "Default Initilazation Test 2 Passed...\n";

  assert(test.pct_used() == 0);
  cout << "Default Initilazation Test 3 Passed!\n";

  cout << "--------------------------------------\n";
}

void input_initialization_test() {
  str_vec test1(100000, "hello");
  for (int i = 0; i < test1.size(); i++) {
    assert(test1.get(i) == "hello");
  }

  cout << "Input Initialization Test 1 Passed...\n";

  str_vec test2(10, "");
  for (int i = 0; i < test2.size(); i++) {
    assert(test2.get(i) == "");
  }

  cout << "Input Initialization Test 2 Passed...\n";

  str_vec test3(0, "hello");
  assert(test3.get(0) == "");

  cout << "Input Initialization Test 3 Passed...\n";

  str_vec test4(100000, "\n");
  for (int i = 0; i < test4.size(); i++) {
    assert(test4.get(i) == "\n");
  }

  cout << "Input Initialization Test 4 Passed!\n";

  cout << "--------------------------------------\n";
}

void copy_test() {
  str_vec test1_vec1(20, "test!");
  str_vec test1_vec2(test1_vec1);
  for (int i = 0; i < test1_vec1.size(); i++) {
    assert(test1_vec2.get(i) == test1_vec1.get(i));
  }

  cout << "Copy Test 1 Passed...\n";

  str_vec test2_vec1(0, "test!");
  str_vec test2_vec2(test2_vec1);
  for (int i = 0; i < test2_vec1.size(); i++) {
    assert(test2_vec2.get(i) == test2_vec1.get(i));
  }

  cout << "Copy Test 2 Passed...\n";

  str_vec test3_vec1(20, "");
  str_vec test3_vec2(test3_vec1);
  for (int i = 0; i < test3_vec1.size(); i++) {
    assert(test3_vec2.get(i) == test3_vec1.get(i));
  }

  cout << "Copy Test 3 Passed...\n";

  str_vec test4_vec1(10000, "test!");
  str_vec test4_vec2(test4_vec1);
  for (int i = 0; i < test4_vec1.size(); i++) {
    assert(test4_vec2.get(i) == test4_vec1.get(i));
  }

  cout << "Copy Test 4 Passed!\n";

  cout << "--------------------------------------\n";
  }

void join_test() {
  str_vec test(5, "test");
  
  assert(test.join("/") == "test/test/test/test/test");
  cout << "Join Test 1 Passed...\n";

  assert(test.join("") == "testtesttesttesttest");
  cout << "Join Test 2 Passed...\n";

  assert(test.join("\n") == "test\ntest\ntest\ntest\ntest");
  cout << "Join Test 3 Passed...\n";

  str_vec test2;

  assert(test2.join("/") == "");
  cout << "Join Test 4 Passed...\n";

  str_vec test3(1, "test");
  
  assert(test3.join("/") == "test");
  cout << "Join Test 5 Passed!\n";
  
  cout << "--------------------------------------\n";
}

void to_string_test() {
  str_vec test1(5, "test");
  assert(test1.to_string() == "{\"test\", \"test\", \"test\", \"test\", \"test\"}");
  cout << "To-String Test 1 Passed...\n";

  test1.set(2, "apple");
  assert(test1.to_string() == "{\"test\", \"test\", \"apple\", \"test\", \"test\"}");
  cout << "To-String Test 2 Passed...\n";

  str_vec test3;

  assert(test3.to_string() == "{\"\"}");
  cout << "To-String Test 3 Passed...\n";

  str_vec test4(5, "");
  assert(test4.to_string() == "{\"\", \"\", \"\", \"\", \"\"}");
  cout << "To-String Test 4 Passed!\n";

  cout << "--------------------------------------\n";
}
// ... put test functions here ...

int main() {
  cout << "Assignment 2 ... \n";
  default_initialization_test();
  input_initialization_test();
  copy_test();
  join_test();
  to_string_test();
  //str_vec test4(5, "");
  //cout << test4.to_string();
}
