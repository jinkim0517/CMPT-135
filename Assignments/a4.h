// a4.h

///////////////////////////////////////////////////////////////////////////////
//
// Do not change this file in any way!
//
// Implement the requested functions. Put your implementations of the given
// functions into a4.cpp.
// 
///////////////////////////////////////////////////////////////////////////////

#ifndef A4_H
#define A4_H

// Don't #include any other files.
#include "cmpt_error.h"
#include "cmpt_trace.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    n >= 0
// Post-condition:
//    Returns the sum of the first n squares, i.e.
//    1^2 + 2^2 + 3^2 + ... + n^2. If n is 0, then 0 is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write
//    helper functions if necessary.
// Note:
//    There's a well-known non-recursive formula to calculate this function.
//    But don't take that approach here: the point of this question is to
//    practice using recursion.
int sum_of_squares(int n);

void sum_of_squares_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    n > 0
// Post-condition:
//    Returns the count of how many numbers from 1 to n (inclusive) that are
//    are both odd and *not* a multiple of 5. In n is 1, then 1 is returned.
//
//    For example, count_strange(11) returns 5 because the odd numbers from 1
//    to 10 are: 1, 3, 5, 7, 9, 11. Since 5 is a multiple of 5, it is not
//    counted. Similarly, count_strange(15) is 6 because the odd multiples
//    from 1 to 15 are: 1, 3, 5, 7, 9, 11, 13, 15. Both 5 and 15 are multiples
//    of 5, so after removing those there are 6 numbers left. Thus
//    count_strange(15) is 6.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
// Note:
//    If you are mathematically-minded you can might be able to come up with a
//    simple non-recursive formula to calculate this function. But don't take
//    that approach here: the point of this question is to practice using
//    recursion.
int count_strange(int n);

void count_strange_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns true if every character in s is either 's', 'f', or 'u'.
//    Otherwise, false is returned. For example, all_sfu("susuf") and
//    all_sfu("uuu") return true, while all_sfu("suSuf") and all_sfu("uuu ")
//    return false.
//
//    If s is the empty string, true is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
bool all_sfu(const string& s);

void all_sfu_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns true if s a valid string representation of an integer. For this
//    function a valid integer is defined to be a string of 1 or more digits
//    that, optionally, starts with a single '-'. No other characters are
//    allowed.
//
//    Here are some examples of strings is_int should return true for: "911",
//    "-23", "0", "000", "-007", "19346".
//
//    Here some strings it should return false for: "", "-", "--", "0 ", "
//    911", "24e5", "782 2", "+32", "3.14".
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
// Note:
//    When testing functions that return bool, make sure to use some test
//    cases that return true, and some that return false.
bool is_int(const string& s);

void is_int_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns a copy of s, but with all leading and trailing spaces removed.
//    No other characters are changed. For example, strip("  ab c  d ")
//    returns "ab c  d". If s is the empty string, or a string of all spaces,
//    then "" is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
string strip(const string& s);

void strip_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns the sum of just the negative numbers in v. If v is empty, 0 is
//    returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
int sum_neg(const vector<int>& v);

void sum_neg_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    a.size() == b.size(), and a.size() > 0
// Post-condition:
//    Returns a vector equal to {max(a[0],b[0]), max(a[1],b[1]),
//    max(a[2],b[2]), ..., max(a[n-1],b[n-1])}, where n == a.size().
//
//    For example, max_vec({3, 4, 1}, {2, 5, 2}) returns the new vector 
//    {3, 5, 2}.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
vector<int> max_vec(const vector<int>& a, const vector<int>& b);

void max_vec_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns the number of strings in v that are equal to s.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
int count(const vector<string>& v, const string& s);

void count_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    s.size() == t.size()
// Post-condition:
//    Returns a vector<string> where the first string is the first character
//    of s followed by the first character of t, the second string is the
//    second character of s followed by the second character of t, and so on.
//    For example, zip("abc", "xyz") returns {"ax", "by", "cz"}.
//
//    If both s and t are empty, then an empty vector<string> is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
vector<string> zip(const string& s, const string& t);

void zip_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns a string consisting of all the strings in v concatenated
//    together with sep after each string (except for the last). 
//
//    For example, join({"cat", "dog", "house"}, ", ") returns "cat, dog,
//    house", join({"he", "we", "see"}, "-") returns "he-we-see", and
//    join({"he", "we", "see"}, "") returns "hewesee".
//
//    For example:
//    - join({"one"}, ", ") returns "one"
//    - join({"up", "dog"}, ", ") returns "up, dog"
//    - join({"he", "we", "see"}, "-") returns "he-we-see"
//    - join({"he", "we", "see"}, "") returns "hewesee".
//
//    If v is empty, the empty string is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
string join(const vector<string>& v, const string& sep);

void join_test();

#endif
