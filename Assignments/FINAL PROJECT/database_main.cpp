#include "menu.h"

using namespace std;

int main() {
    Database test;
    test.add_song();
    test.add_song();
    test.add_song();

    vector<Song> s = test.find_range_duration(0, 360, true);
    for (int i = 0; i < s.size(); i++) {
        cout << s[i].get_duration() << endl;
    }

    cout << endl;

    s = test.find_range_year(2000, 2030, true);
    for (int i = 0; i < s.size(); i++) {
        cout << s[i].get_year() << endl;
    }

    cout << endl;  

    s = test.find_by_name("abc", false);

    for (int i = 0; i < s.size(); i++) {
        cout << s[i].get_name() << endl;
    }

    cout << endl;

    s = test.find_by_artist("jin", true);

    for (int i = 0; i < s.size(); i++) {
        cout << s[i].get_artist() << endl;
    }
}