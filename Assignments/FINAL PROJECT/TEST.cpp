#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// template <typename T>
// T join (const vector<T>& v, string sep) {
// 	string result;
// 	if (v.size() != 0) {
// 		for (int i = 0; i < v.size() - 1; i++) {
// 			result += to_string(v[i]) + sep;
// 		}
// 		result += to_string(v[v.size() - 1]);
// 	}
// 	return result;
// }

template <typename T>
string join(const vector<T>& v, const string& sep = ", ") {
    if (v.empty()) return "";
    string result = to_string(v[0]);
    for(int i = 1; i < v.size(); i++) {
        result += sep + to_string(v[i]);
    }
    return result;
}

int main() {
    vector<string> a;
    a.push_back("Hello");
    a.push_back("My");
    a.push_back("Name");
    a.push_back("Is Jin KIM!!!");
	cout << join(a, "~");
}