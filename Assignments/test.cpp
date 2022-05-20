#include <iostream>
#include <string>
#include <vector>

using namespace std;

// string repeat(const string& s, const int& n) {
//     string  result;
//     if (n == 0) {
//         return result;
//     }
//     result += s + repeat(s, n - 1);
//     return result;
// }

int main() {
    // vector<int> a;
    // for (int i = 0; i < 10; i++) {
    //     a.push_back(i);
    //     cout << i << " ";
    // }
    // cout << endl;
    // a.erase(a.begin() + 2);
    // for (int i = 0; i < a.size(); i++) {
    //     cout << a[i] << " ";
    // }

    string a = "123456";
    cout << a.substr(3);
}