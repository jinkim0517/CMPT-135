#include "database.h"

Database::Database()
:song_list()
{ }

void print_int(const vector<int>& s) {
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
}

void Database::print_names_alpha() {
    vector<string> name_list;
    for (int i = 0; i < song_list.size(); i++) {
        name_list.push_back(song_list[i].get_name());
    }
    sort(name_list.begin(), name_list.end());

    for (int i = 0; i < name_list.size(); i++) {
        cout << name_list[i] << endl;
    }
}

void Database::print_artists_alpha() {
    vector<string> artist_list;
    for (int i = 0; i < song_list.size(); i++) {
        artist_list.push_back(song_list[i].get_artist());
    }
    sort(artist_list.begin(), artist_list.end());
    
    for (int i = 0; i < artist_list.size(); i++) {
        cout << artist_list[i] << endl;
    }
}

void Database::print_duration(bool desc) {
    vector<int> duration_list;
    for (int i = 0; i < song_list.size(); i++) {
        duration_list.push_back(song_list[i].get_duration());
    }
    sort(duration_list.begin(), duration_list.end());
    if (desc) {
        reverse(duration_list.begin(), duration_list.end());
    }
    for (int i = 0; i < duration_list.size(); i++) {
        cout << duration_list[i] << endl;
    }
}

void Database::print_singles_only() {
    for (int i = 0; i < song_list.size(); i++) {
        if (song_list[i].is_single()) {
            cout << song_list[i].get_name() << endl;
        }
    }
}

bool Database::name_check(string name) {
    for (int i = 0; i < song_list.size(); i++) {
        if (song_list[i].get_name() == name) {
            return false;
        }
    }
    return true;
}

bool Database::artist_check(string artist) {
    for (int i = 0; i < song_list.size(); i++) {
        if (song_list[i].get_artist() == artist) {
            return false;
        }
    }
    return true;
}

void Database::add_song() {
    string name;
    string artist;
    int int_ans;
    char char_ans;
    Song new_song;

    cout << "What's the name of the song?" << endl;
    cin >> name;

    cout << "Who made the song?" << endl;
    cin >> artist;

    if (artist_check(artist) && name_check(name)) {
        cout << "This song has already been added!\n";
    }
    else {
        new_song.set_name(name);
        new_song.set_artist(artist);
    }

    cout << "How long is the song? (Please give in seconds)" << endl;
    cin >> int_ans;
    new_song.set_duration(int_ans);
    int_ans = 0;

    cout << "What year was it released?" << endl;
    cin >> int_ans;
    new_song.set_release(int_ans);
    int_ans = 0;

    cout << "Is it a single? (y/n)" << endl;
    cin >> char_ans;
    if (char_ans == 'y') {
        new_song.set_single(true);
    }
    else if (char_ans == 'n') {
        new_song.set_single(false);
    }
    else {
        while (char_ans != 'y' || char_ans != 'n') {
            cout << "Is it a single? (y/n)" << endl;
            cin >> char_ans;

            if (char_ans == 'y') {
                new_song.set_single(true);
            }
            else if (char_ans == 'n') {
                new_song.set_single(false);
            }
        }
    }
    song_list.push_back(new_song);
}

void Database::delete_song() {
    string delete_name;
    cout << "What's the name of the song that you would like to delete?" << endl;
    cin >> delete_name;

    int index = song_list.size() + 1;

    while (index == song_list.size() + 1) {
        for (int i = 0; i < song_list.size(); i++) {
            if (song_list[i].get_name() == delete_name) {
                index = i;
                i = song_list.size();
            }
        }

        if (index == song_list.size() + 1) {
            cout << "There is no song with that name. Please try again!\n";
        }
    }

    song_list.erase(song_list.begin() + index);
}