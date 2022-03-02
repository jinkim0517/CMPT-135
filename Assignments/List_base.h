// List_base.h

//
// Don't make any changes to this file!
//

#include <string>

using namespace std;

class List_base {
private:
    string indent = "";
public:
    // Always provide a virtual destructor in a base class so that extending
    // classes can override it if need be.
    virtual ~List_base() { }

    // Returns a copy of the indentation string.
    virtual string get_indent() const {
        return indent;
    }

    // Sets the indentation string to be i spaces. If i < 0, then i is set to
    // 0 and the string is set to the empty string.
    virtual void set_indent(int i) {
        if (i < 0) i = 0;
        indent = string(i, ' ');
    }

    // Returns the number of items in this list.
    virtual int size() const = 0;

    // Returns item i of this list (the first item is 0, the second is 1,
    // ...). If there is a bullet-point or number, it's not included. Does
    // bounds-checking: if i < 0, or i >= size(), then it calls cmpt::error
    // with a helpful error message.
    virtual string get(int i) const = 0;

    // Inserts a new item s at the start of the list.
    virtual void add_to_start(const string& s) = 0;

    // Inserts a new item s at the end of the list.
    virtual void add_to_end(const string& s) = 0;

    // Reverses the order of a list. For numbered list, the numbers are also
    // reversed.
    virtual void reverse_order() = 0;

    // Returns a string representation of this list suitable for printing to
    // cout.
    virtual string to_str() const = 0;

    // Returns an HTML string representation of this list suitable for putting
    // in a web page. Ignores the space separator, the bullet string, and
    // identation string. A numbered HTML list should start with "<ol
    // reversed>" and the items should appear in reverse order.
    virtual string to_html_str() const = 0;
}; // class List
