// a3.cpp

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

#include "cmpt_error.h"    //
#include "List_base.h"     // These are the only permitted #includes!
#include <iostream>        //
#include <string>          // Don't #include anything else.
#include <vector>          //
#include <cassert>

using namespace std;

class Bulleted_list : public List_base  {
  private:
  vector<string> lst;
  string bullet;

  public:
  Bulleted_list()
  : lst(), bullet(" - ")
  { }

  string to_str() const{
    string result;
    for (int i = 0; i < lst.size(); i++) {
      result += get_indent() + bullet + lst[i] + '\n';
    }
    return result;
  }

  string get(int i) const {
    return lst[i];
  }

  int size() const {
    return lst.size();
  }

  void add_to_end(const string& s) {
    lst.push_back(s);
  } 

  void add_to_start(const string& s) {
    lst.insert(lst.begin(), s);
  }

  void set_bullet(string s) {
    bullet = s;
  }

  string get_bullet() {
    return bullet;
  }

  void reverse_order() {
    reverse(lst.begin(), lst.end());
  }

  string to_html_str() const {
    string result;
    result += "<ul>\n";
    for (int i = 0; i < lst.size(); i++) {
      result += "  <li>" + lst[i] + "<li>\n";
    }
    result += "</ul>\n";
    return result;
  }

  ~Bulleted_list() 
  {  }
};

class Numbered_list : public List_base {
private:
  int start;
  bool reversed;
  string num_sep;
  vector<string> lst;
public:
  Numbered_list() 
  : start(1), reversed(false), num_sep(". "), lst()
  { }

  string to_str() const{
    vector<string> numbers;
    string s_result;
    
    // Create a vector of numbers that will be the index for the list
    for (int i = start; i < start + lst.size(); i++) {
      numbers.push_back(to_string(i));
    }

    // Reverse the numbers if the list is reversed
    if (reversed) {
      reverse(numbers.begin(), numbers.end());
    }
    
    for (int i = 0; i < lst.size(); i++) {
      s_result += get_indent() + numbers[i] + num_sep + lst[i] + '\n';
    }

    return s_result;
  }

  void add_to_end(const string& s) {
    lst.push_back(s);
  } 

  void add_to_start(const string& s) {
    lst.insert(lst.begin(), s);
  }

  void set_num_sep(string s) {
    num_sep = s;
  }

  string get_num_sep() const {
    return num_sep;
  }

  string get(int i) const{
    return lst[i];
  }

  int get_start() const{
    return start;
  }

  int size() const {
    return lst.size();
  }

  void set_start_num(int s) {
    if (s >= 0) {
      start = s;
    }
    else {
      start = 0;
    }
  }

  void reverse_order() {
    reverse(lst.begin(), lst.end());
    if (reversed) {
      reversed = false;
    }
    else {
      reversed = true;
    }
  }

  string to_html_str() const {
    string result;
    if (reversed) {
      result += "<ol reversed>\n";
    }
    else {
      result += "<ol>\n";
    }
    for (int i = 0; i < lst.size(); i++) {
      result += "  <li>" + lst[i] + "<li>\n";
    }
    result += "</ol>\n";
    return result;
  }

  ~Numbered_list() 
  { }
};

// Bulleted class test function
void bullet_lst_test() {
  Bulleted_list test1;
  Bulleted_list test3;
  Bulleted_list test4;

  test1.add_to_end("hey");
  test1.add_to_end("hi");
  test1.add_to_end("hello");
  test1.add_to_end("wassup");
  test1.add_to_start("yo!");

  assert(test1.to_str() == " - yo!\n - hey\n - hi\n - hello\n - wassup\n");
  cout << "Bulleted List Test 1 Passed...\n";

  test1.reverse_order();

  assert(test1.to_str() == " - wassup\n - hello\n - hi\n - hey\n - yo!\n");
  cout << "Bulleted List Test 2 Passed...\n";

  for (int i = 0; i < 5; i++) {
    test3.add_to_end("");
  }

  assert(test3.to_str() == " - \n - \n - \n - \n - \n");
  cout << "Bulleted List Test 3 Passed...\n";

  test4.add_to_end("apple");
  test4.add_to_end("orange");

  assert(test4.to_html_str() == "<ul>\n  <li>apple<li>\n  <li>orange<li>\n</ul>\n");
  cout << "Bulleted List Test 4 Passed...\n";

  test4.reverse_order();

  assert(test4.to_html_str() == "<ul>\n  <li>orange<li>\n  <li>apple<li>\n</ul>\n");
  cout << "Bulleted List Test 5 Passed!\n";

  cout << "--------------------------------\n";
}

// Numbered class test function
void num_lst_test() {
  Numbered_list test1;
  Numbered_list test3;
  Numbered_list test4;

  test1.set_start_num(0);
  test1.add_to_end("hey");
  test1.add_to_end("hi");
  test1.add_to_end("hello");
  test1.add_to_end("wassup");
  test1.add_to_start("yo!");

  assert(test1.to_str() == "0. yo!\n1. hey\n2. hi\n3. hello\n4. wassup\n");
  cout << "Numbered List Test 1 Passed...\n";

  test1.reverse_order();

  assert(test1.to_str() == "4. wassup\n3. hello\n2. hi\n1. hey\n0. yo!\n");
  cout << "Numbered List Test 2 Passed...\n";

  for (int i = 0; i < 5; i++) {
    test3.add_to_end("");
  }

  assert(test3.to_str() == "1. \n2. \n3. \n4. \n5. \n");
  cout << "Numbered List Test 3 Passed...\n";

  test4.add_to_end("apple");
  test4.add_to_end("orange");

  assert(test4.to_html_str() == "<ol>\n  <li>apple<li>\n  <li>orange<li>\n</ol>\n");
  cout << "Numbered List Test 4 Passed...\n";

  test4.reverse_order();

  assert(test4.to_html_str() == "<ol reversed>\n  <li>orange<li>\n  <li>apple<li>\n</ol>\n");
  cout << "Numbered List Test 5 Passed!\n";

  cout << "--------------------------------\n";
}

int main() {
  bullet_lst_test();
  num_lst_test();
}