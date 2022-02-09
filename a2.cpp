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
  // Default constructor
  str_vec()
  : arr_capacity(10), arr_size(0), arr(new string[arr_capacity])

  { }

  // Creates a new str_vec of size n and values all of string s
  str_vec(int n, string s) 
  // Double capacity and add one to ensure that a non-exsiting array is never initialized
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

  // Copy constructor
  str_vec(const str_vec& other)
  : arr_capacity(other.arr_capacity), arr_size(other.arr_size), arr(new string[arr_capacity])
  { 
    for (int i = 0; i < arr_size; i++) {
      arr[i] = other.arr[i];
    }
  }

  // Joins values of str_vec with string sep and returns the string value
  string join(string sep) {
    string result;
    for (int i = 0; i < arr_size; i++) {
      // Does not add sep to the last index
      if (i == arr_size - 1) {
        result += arr[i];
      }
      else {
      result += arr[i] + sep;
      }
    }
    return result;
  }

  // Returns the string representation of str_vec
  string to_string() const {
    string result = "{";

    // Empty array returns string skeleton
    if (arr_size == 0) {
      result += "}";
    }
    else {
      result += "\"";
      for (int i = 0; i < arr_size; i++) {
        if (i == arr_size - 1) {
          result += arr[i] + "\"}";
        }
        else {
          result += arr[i] + "\", \"";
        }
      }
    }
    return result;
  }

  // Returns the value of str_vec at index i
  string get(int i) const {
    if (arr_size != 0){
      if (i < 0 || i > arr_size - 1) {
        cmpt::error("get(): index must be within boundaries");
      }
    }
    return arr[i];
  }

  // Sets string s to str_vec's index i
  void set(int i, string s) {
    if (i < 0 || i > arr_size - 1) {
      cmpt::error("set(): index must be within boundaries");
    }
    arr[i] = s;
  }

  // Adds a string to the end of str_vec
  void append(string s) {
    if (arr_size >= arr_capacity) {
      arr_capacity *= 2 + 1;

      // Creates a new string pointer and initializes it with new size and 
      // capacity while adding s to the end.
      string* temp_arr = new string[arr_capacity];

      for (int i = 0; i < arr_size; i++) {
        temp_arr[i] = arr[i];
      }

      // Old array is deleted with the destructor
      arr = temp_arr;
    }

    arr[arr_size] = s;
    arr_size++;
  }

  // Adds a string to the end of str_vec only if it is a unique value
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

  // Checks if a string only contains spaces
  bool space_only_check (string s) {
    bool space_only = false;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        space_only = true;
      }
      else {
        return false;
      }
    }
    return space_only;
  }
  
  void remove_space(string& s) {
    if (s.size() != 0 && !space_only_check(s)) {
        // Creates an index of the orignal string between the first and last 
        // non ' ' character that a new string can be bound between
        int beginning = s.find_first_not_of(' ');
        int ending = s.find_last_not_of(' ');
        string new_string;

        for (int i = beginning; i <= ending; i++) {
          // Initial new_string to the values between the indexes
          new_string += s[i];
        }
        s = new_string;
    }
    else {
      s = "";
    }
  }

  // Removes all leading and following spaces
  void trim_all() { 
    for (int i = 0; i < arr_size; i++) {
      remove_space(arr[i]);
    }
  }

  // Removes a value at index i
  void remove(int i) {
    if (i < 0 || i >= arr_size) {
      cmpt::error("remove(): index must be within boundaries");
    }

    arr[i] = "";

    // Shift the array down 1 index and assign the end value to "".
    for (int x = i; x < arr_size - 1; x++) {
      arr[x] = arr[x + 1];
    }

    arr[arr_size - 1] = "";
    arr_size = arr_size - 1;
  }

  // Removes all characters that start with the character 'c'
  void keep_all_starts_with(char c) {
    string* temp_arr = new string[arr_capacity];
    string word;
    int temp_index = 0;
    int temp_size = arr_size;

    for (int i = 0; i < arr_size; i++) {
      word = arr[i];
      if (word[0] == c) {
        temp_arr[temp_index] = arr[i];
        temp_index++;
      }
      else {
        temp_size--;
      }
    }

    if (temp_index > 0) {
      arr = temp_arr;
      arr_size = temp_size;
    }
    else {
      delete[] temp_arr;
    }
  }

  // Resets the str_vec
  void clear() {
    arr = new string[arr_capacity];
    arr_size = 0;
  }

  // Assigns the str_vec's capacity to its size
  void squish() {
    arr_capacity = arr_size;
    string* temp_arr = arr;

    // arr points to an empty array with the capacity of the original size
    arr = new string[arr_capacity];
    
    for (int i = 0; i < arr_capacity; i++) {
      // arr is initialized with the original values
      arr[i] = temp_arr[i];
    }
  }

  // Prints the string version of the str_vec
  void print() const {
    cout << to_string();
  }

  // Prints the string version of the str_vec with an endline character at the end
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

// Checks if two str_vecs are identical
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

// Checks if two str_vecs are different
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

// Test Functions
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
  str_vec test2(10, "");
  str_vec test3(0, "hello");
  str_vec test4(100000, "\n");

  for (int i = 0; i < test1.size(); i++) {
    assert(test1.get(i) == "hello");
  }
  cout << "Input Initialization Test 1 Passed...\n";

  for (int i = 0; i < test2.size(); i++) {
    assert(test2.get(i) == "");
  }
  cout << "Input Initialization Test 2 Passed...\n";

  assert(test3.get(0) == "");
  cout << "Input Initialization Test 3 Passed...\n";

  for (int i = 0; i < test4.size(); i++) {
    assert(test4.get(i) == "\n");
  }
  cout << "Input Initialization Test 4 Passed!\n";

  cout << "--------------------------------------\n";
}

void copy_test() {
  str_vec test1_vec1(20, "test!");
  str_vec test1_vec2(test1_vec1);
  str_vec test2_vec1(0, "test!");
  str_vec test2_vec2(test2_vec1);
  str_vec test3_vec1(20, "");
  str_vec test3_vec2(test3_vec1);
  str_vec test4_vec1(10000, "test!");
  str_vec test4_vec2(test4_vec1);

  for (int i = 0; i < test1_vec1.size(); i++) {
    assert(test1_vec2.get(i) == test1_vec1.get(i));
  }

  cout << "Copy Test 1 Passed...\n";

  for (int i = 0; i < test2_vec1.size(); i++) {
    assert(test2_vec2.get(i) == test2_vec1.get(i));
  }

  cout << "Copy Test 2 Passed...\n";

  for (int i = 0; i < test3_vec1.size(); i++) {
    assert(test3_vec2.get(i) == test3_vec1.get(i));
  }

  cout << "Copy Test 3 Passed...\n";

  for (int i = 0; i < test4_vec1.size(); i++) {
    assert(test4_vec2.get(i) == test4_vec1.get(i));
  }

  cout << "Copy Test 4 Passed!\n";

  cout << "--------------------------------------\n";
  }

void join_test() {
  str_vec test(5, "test");
  str_vec test2;
  str_vec test3(1, "test");
  
  assert(test.join("/") == "test/test/test/test/test");
  cout << "Join Test 1 Passed...\n";

  assert(test.join("") == "testtesttesttesttest");
  cout << "Join Test 2 Passed...\n";

  assert(test.join("\n") == "test\ntest\ntest\ntest\ntest");
  cout << "Join Test 3 Passed...\n";


  assert(test2.join("/") == "");
  cout << "Join Test 4 Passed...\n";

  
  assert(test3.join("/") == "test");
  cout << "Join Test 5 Passed!\n";
  
  cout << "--------------------------------------\n";
}

void to_string_test() {
  str_vec test1(5, "test");
  str_vec test3;
  str_vec test4(5, "");

  assert(test1.to_string() == "{\"test\", \"test\", \"test\", \"test\", \"test\"}");
  cout << "To-String Test 1 Passed...\n";

  test1.set(2, "apple");
  assert(test1.to_string() == "{\"test\", \"test\", \"apple\", \"test\", \"test\"}");
  cout << "To-String Test 2 Passed...\n";

  assert(test3.to_string() == "{}");
  cout << "To-String Test 3 Passed...\n";

  assert(test4.to_string() == "{\"\", \"\", \"\", \"\", \"\"}");
  cout << "To-String Test 4 Passed!\n";

  cout << "--------------------------------------\n";
}

void append_test() {
  str_vec test1(5, "test");
  str_vec test2(0, "");

  test1.append("test");
  assert(test1.size() == 6);
  assert(test1.get(5) == "test");
  cout << "Append Test 1 Passed...\n";

  test1.append("");
  assert(test1.size() == 7);
  assert(test1.get(6) == "");
  cout << "Append Test 2 Passed...\n";

  test1.append_new("test");
  assert(test1.size() == 7);
  assert(test1.to_string() == "{\"test\", \"test\", \"test\", \"test\", \"test\", \"test\", \"\"}");
  cout << "Append Test 3 Passed...\n";

  test1.append_new("test2");
  assert(test1.size() == 8);
  assert(test1.get(7) == "test2");
  cout << "Append Test 4 Passed...\n";

  test2.append("test");
  assert(test2.to_string() == "{\"test\"}");
  assert(test2.size() == 1);
  cout <<"Append Test 5 Passed!\n";

  cout << "--------------------------------------\n";
}

void trim_test() {
  str_vec test1(5, "  test  ");
  str_vec test2(5, "");
  str_vec test3(5, "     ");
  str_vec test4(5, "  test  4   ");

  test1.trim_all();
  assert(test1.to_string() == "{\"test\", \"test\", \"test\", \"test\", \"test\"}");
  cout << "Trim Test 1 Passed...\n";

  test2.trim_all();
  assert(test2.to_string() == "{\"\", \"\", \"\", \"\", \"\"}");
  cout << "Trim Test 2 Passed...\n";

  test3.trim_all();
  assert(test3.to_string() == "{\"\", \"\", \"\", \"\", \"\"}");
  cout << "Trim Test 3 Passed...\n";

  test4.trim_all();
  assert(test4.to_string() == "{\"test  4\", \"test  4\", \"test  4\", \"test  4\", \"test  4\"}");
  cout << "Trim Test 4 Passed!\n";

  cout << "--------------------------------------\n";
}

void remove_test() {
  str_vec test(5, "");
  str_vec test3(5, "");

  test.set(0, "apple");
  test.set(1, "pear");
  test.set(2, "orange");
  test.set(3, "grape");
  test.set(4, "banana");

  test.remove(0);
  assert(test.to_string() == "{\"pear\", \"orange\", \"grape\", \"banana\"}");
  assert(test.size() == 4);
  cout << "Remove Test 1 Passed...\n";

  test.remove(3);
  assert(test.to_string() == "{\"pear\", \"orange\", \"grape\"}");
  assert(test.size() == 3);
  cout << "Remove Test 2 Passed...\n";

  test3.remove(3);
  assert(test3.to_string() == "{\"\", \"\", \"\", \"\"}");
  cout << "Remove Test 3 Passed...\n";

  cout << "--------------------------------------\n";
}

void set_and_get_test() {
  str_vec test(5, "test");
  str_vec test2(5, "");
  str_vec test3(1, "test");

  test.set(1, "set");
  assert(test.get(1) == "set");
  cout << "Set Test 1 Passed...\n";

  test2.set(2, "set");
  assert(test2.get(2) == "set");
  cout << "Set Test 2 Passed...\n";

  test3.set(0, "");
  assert(test3.get(0) == "");
  cout << "Set Test 3 Passed!\n";

  cout << "--------------------------------------\n";
}

void keep_all_starts_with_test() {
  str_vec test(5, "");

  test.set(0, "apple");
  test.set(1, "pear");
  test.set(2, "andrew");
  test.set(3, "banana");
  test.set(4, "baker");

  str_vec test1(test);
  str_vec test2(test);
  str_vec test3(test);
  str_vec test4(5, "");

  test1.keep_all_starts_with('a');
  assert(test1.to_string() == "{\"apple\", \"andrew\"}");
  assert(test1.size() == 2);
  cout << "Keep All That Starts With Test 1 Passed...\n";

  test2.keep_all_starts_with('f');
  assert(operator==(test, test2));
  cout << "Keep All That Starts With Test 2 Passed...\n";

  test3.keep_all_starts_with(' ');
  assert(operator==(test, test3));
  cout << "Keep All That Starts With Test 3 Passed...\n";

  test4.keep_all_starts_with('a');
  assert(test4.to_string() == "{\"\", \"\", \"\", \"\", \"\"}");
  assert(test4.size() == 5);
  cout << "Keep All That Starts With Test 4 Passed!\n";

  cout << "--------------------------------------\n";
}

void clear_test() {
  str_vec test(5, "");
  str_vec test3(500, "//");
  test.set(0, "apple");
  test.set(1, "pear");
  test.set(2, "andrew");
  test.set(3, "banana");
  test.set(4, "baker");

  test.clear();
  assert(test.size() == 0);
  assert(test.to_string() == "{}");
  cout << "Clear Test 1 Passed...\n";

  test.clear();
  assert(test.size() == 0);
  assert(test.to_string() == "{}");
  cout << "Clear Test 2 Passed...\n";

  assert(test.size() == 0);
  assert(test.to_string() == "{}");
  cout << "Clear Test 3 Passed!\n";

  cout << "--------------------------------------\n";
}

void squish_test() {
  str_vec test(10, "test");
  str_vec test1(test);
  str_vec test3(0, "");

  test.squish();
  assert(test.size() == test.capacity());
  cout << "Squish Test 1 Passed...\n";

  assert(test.to_string() == test1.to_string());
  cout << "Squish Test 2 Passed...\n";

  test3.squish();
  assert(test3.to_string() == "{}");
  cout << "Squish Test 3 Passed!\n";

  cout << "--------------------------------------\n";  
}

void operator_test() {
  str_vec test(10, "test");
  str_vec test2(test);
  str_vec test3(test);
  test3.set(9, "Not Test");

  assert(operator==(test, test2));
  cout << "Operator Test 1 Passed...\n";

  assert(!operator!=(test, test2));
  cout << "Operator Test 2 Passed...\n";

  assert(!operator==(test, test3));
  cout << "Operator Test 3 Passed...\n";

  assert(operator!=(test, test3));
  cout << "Operator Test 4 Passed!\n";

  cout << "--------------------------------------\n";  
}

void str_vec_test() {
  default_initialization_test();
  input_initialization_test();
  copy_test();
  join_test();
  to_string_test();
  append_test();
  trim_test();
  remove_test();
  set_and_get_test();
  keep_all_starts_with_test();
  clear_test();
  squish_test();
  operator_test();

  cout << "|ALL TESTS PASSED|\n";
}

int main() {
  cout << "Assignment 2 ... \n";
  str_vec_test();
}