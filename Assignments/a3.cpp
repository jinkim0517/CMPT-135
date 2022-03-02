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

//
// ... put your classes here ...
//
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

  void reverse_order() { // fix
    vector<string> temp_lst;
    for (int i = lst.size(); i >= 0; i--) {
      temp_lst.push_back(lst[i]);
    }
    lst = temp_lst;
  }

  string to_html_str() const {
    string result;
    result += "<ul>\n";
    for (int i = 0; i < lst.size(); i++) {
      result += " <li>" + lst[i] + "<li>\n";
    }
    result += "</ul>";
    return result;
  }

  ~Bulleted_list() 
  {  }
};

void demo1() {
    Bulleted_list lst;

    lst.add_to_end("oranges");
    lst.add_to_end("pears");
    lst.add_to_end("grapes");
    lst.add_to_start("apples");

    cout << "\n";
    cout << lst.to_str();

    lst.set_indent(3);
    cout << "\n";
    cout << lst.to_str();

    lst.set_indent(0);
    lst.set_bullet("** ");
    cout << "\n";
    cout << lst.to_str();

    lst.set_bullet("- ");
    lst.reverse_order();
    cout << "\n";
    cout << lst.to_str();

    lst.reverse_order();
    cout << "\n";
    cout << lst.to_html_str();
}

int main() {
  // Bulleted_list l;

  // l.add_to_end("hi");
  // l.add_to_end("hey!");
  // l.add_to_start("yo");

  // l.set_indent(5);
  // l.set_bullet("**********");
  // cout << l.to_str();

  demo1();
}


/*

Below is the code used in the assignment description, along with its output.

void demo1() {
    Bulleted_list lst;

    lst.add_to_end("oranges");
    lst.add_to_end("pears");
    lst.add_to_end("grapes");
    lst.add_to_start("apples");

    cout << "\n";
    cout << lst.to_str();

    lst.set_indent(3);
    cout << "\n";
    cout << lst.to_str();

    lst.set_indent(0);
    lst.set_bullet("** ");
    cout << "\n";
    cout << lst.to_str();

    lst.set_bullet("- ");
    lst.reverse_order();
    cout << "\n";
    cout << lst.to_str();

    lst.reverse_order();
    cout << "\n";
    cout << lst.to_html_str();
}

Output for demo1():

- apples
- oranges
- pears
- grapes

   - apples
   - oranges
   - pears
   - grapes

** apples
** oranges
** pears
** grapes

- grapes
- pears
- oranges
- apples

<ul>
  <li>apples</li>
  <li>oranges</li>
  <li>pears</li>
  <li>grapes</li>
</ul>


void demo2() {
    Numbered_list lst;

    lst.add_to_end("oranges");
    lst.add_to_end("pears");
    lst.add_to_end("grapes");
    lst.add_to_start("apples");

    cout << lst.to_str();

    lst.set_num_sep(") ");
    cout << "\n";
    cout << lst.to_str();

    lst.set_start_num(3);
    cout << "\n";
    cout << lst.to_str();

    lst.set_start_num(1);
    lst.reverse_order();
    cout << "\n";
    cout << lst.to_str();

    lst.set_start_num(3);
    cout << "\n";
    cout << lst.to_str();

    lst.reverse_order();
    cout << "\n";
    cout << lst.to_html_str();

    lst.reverse_order();
    cout << "\n";
    cout << lst.to_html_str();
}

Output for demo2():

1. apples
2. oranges
3. pears
4. grapes

1) apples
2) oranges
3) pears
4) grapes

3) apples
4) oranges
5) pears
6) grapes

4) grapes
3) pears
2) oranges
1) apples

6) grapes
5) pears
4) oranges
3) apples

<ol>
  <li>apples</li>
  <li>oranges</li>
  <li>pears</li>
  <li>grapes</li>
</ol>

<ol reversed>
  <li>grapes</li>
  <li>pears</li>
  <li>oranges</li>
  <li>apples</li>
</ol>

*/
