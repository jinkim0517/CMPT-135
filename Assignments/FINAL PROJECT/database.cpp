#include "database.h"

Database::Database()
:song_list()
{ }

bool operator<(Song song1, Song song2) {
    if (song1.get_name() < song2.get_name()) {
        return true;
    }
    else {
        return false;
    }
}

bool compare_durations(Song song1, Song song2) {
    if (song1.get_duration() < song2.get_duration()) {
        return true;
    }
    else {
        return false;
    }
}

bool compare_dates(Song song1, Song song2) {
    if (song1.get_year() < song2.get_year()) {
        return true;
    }
    else {
        return false;
    }
}

bool compare_artists(Song song1, Song song2) {
    if (song1.get_artist() < song2.get_artist()) {
        return true;
    }
    else {
        return false;
    }
}

vector<Song> Database::find_singles_only() {
    vector<Song> songs;
    for (int i = 0; i < song_list.size(); i++) {
        if (song_list[i].is_single()) {
            songs.push_back(song_list[i]);
        }
    }

    if (songs.size() == 0) {
        cout << "No matching songs.\n";
    }

    return songs;
}

vector<Song> Database::find_by_name(string name, bool reversed) {
    vector<Song> songs;
    for (int i = 0; i < song_list.size(); i++) {
        if ((song_list[i].get_name() == name) || 
        (song_list[i].get_name().find(name) != string::npos)) {
            songs.push_back(song_list[i]);
        }
    }

    if (songs.size() == 0) {
        cout << "No matching songs.\n";
        return songs;
    }

    sort(songs.begin(), songs.end());

    if (!reversed) {
        reverse(songs.begin(), songs.end());
    }

    return songs;
}

vector<Song> Database::find_precise_duration(int duration) {
    vector<Song> songs;
    for (int i = 0; i < song_list.size(); i++) {
        if (song_list[i].get_duration() == duration) {
            songs.push_back(song_list[i]);
        }
    }

    if (songs.size() == 0) {
        cout << "No matching songs.\n";
    }

    return songs;
}

vector<Song> Database::find_range_duration(int begin, int end, bool desc) {
    vector<Song> songs;
    for (int i = 0; i < song_list.size(); i++) {
        if ((song_list[i].get_duration() >= begin) && (song_list[i].get_duration() <= end)) {
            songs.push_back(song_list[i]);
        }
    }

    if (songs.size() == 0) {
        cout << "No matching songs.\n";
        return songs;
    }

    sort(songs.begin(), songs.end(), compare_durations);

    if (desc) {
        reverse(songs.begin(), songs.end());
    }
    return songs;
}

vector<Song> Database::find_precise_year(int year) {
    vector<Song> songs;
    for (int i = 0; i < song_list.size(); i++) {
        if (song_list[i].get_year() == year) {
            songs.push_back(song_list[i]);
        }
    }

    if (songs.size() == 0) {
        cout << "No matching songs.\n";
    }

    return songs;
}

vector<Song> Database::find_range_year(int begin, int end, bool desc) {
    vector<Song> songs;
    for (int i = 0; i < song_list.size(); i++) {
        if ((song_list[i].get_year() >= begin) && (song_list[i].get_year() <= end)) {
            songs.push_back(song_list[i]);
        }
    }

    if (songs.size() == 0) {
        cout << "No matching songs.\n";
        return songs;
    }

    sort(songs.begin(), songs.end(), compare_dates);

    if (desc) {
        reverse(songs.begin(), songs.end());
    }

    return songs;
}

vector<Song> Database::find_by_artist(string artist, bool reversed) {
    vector<Song> songs;
    for (int i = 0; i < song_list.size(); i++) {
        if (song_list[i].get_artist() == artist || 
        (song_list[i].get_artist().find(artist) != string::npos)) {
            songs.push_back(song_list[i]);
        }
    }

    if (songs.size() == 0) {
        cout << "No matching songs.\n";
        return songs;
    }

    sort(songs.begin(), songs.end(), compare_artists);

    if (reversed) {
        reverse(songs.begin(), songs.end());
    }

    return songs;
}

bool Database::name_check(string name) {
    if (song_list.size() == 1 || song_list.size() == 0) {
        return false;
    }
    for (int i = 0; i < song_list.size(); i++) {
        if (song_list[i].get_name() == name) {
            return true;
        }
    }
    return false;
}

bool Database::artist_check(string artist) {
    if (song_list.size() == 1 || song_list.size() == 0) {
        return false;
    }
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
    getline(cin, name);

    cout << "Who made the song?" << endl;
    getline(cin, artist);

    while (artist_check(artist) && name_check(name)) {
        cout << "This song has already been added! Please enter a different song.\n";
        cout << "What's the name of the song?" << endl;
        getline(cin, name);

        cout << "Who made the song?" << endl;
        getline(cin, artist);
    }

    new_song.set_name(name);
    new_song.set_artist(artist);

    cout << "How long is the song? (Please give in seconds)" << endl;

    while (!(cin >> int_ans)) {
		cout << "Please give a valid duration in seconds.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

    new_song.set_duration(int_ans);
    int_ans = 0;


    cout << "What year was it released?" << endl;

    while (!(cin >> int_ans)) {
		cout << "Please give a valid year.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

    new_song.set_release(int_ans);
    int_ans = 0;

    cout << "Is it a single? (y/n)" << endl;

    while (!(cin >> char_ans)) {
        cout << "Please give a valid answer.\n";
        cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (char_ans == 'y') {
        new_song.set_single(true);
    }
    else if (char_ans == 'n') {
        new_song.set_single(false);
    }
    else {
        while (char_ans != 'y' && char_ans != 'n') {
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
    cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Database::delete_song(int index) {
    song_list.erase(song_list.begin() + index);
}