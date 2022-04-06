#ifndef DATABASE_H
#define DATABASE_H

#include "songs.h"
#include "cmpt_error.h"
#include "cmpt_trace.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <limits>

class Database {
private:
    vector<Song> song_list;
public:
    Database();

    // void print_names_alpha(const vector<Song>& songs, bool reversed);

    // void print_artists_alpha(bool reversed);

    void sort_by_year(vector<Song>& songs, bool desc);

    vector<Song> find_singles_only();

    vector<Song> find_by_name(string name, bool reversed);

    vector<Song> find_precise_duration(int duration);

    vector<Song> find_range_duration(int begin, int end, bool desc);

    vector<Song> find_precise_year(int year);

    vector<Song> find_range_year(int begin, int end, bool desc);

    vector<Song> find_by_artist(string artist, bool reversed);

    bool name_check(string name);

    bool artist_check(string artist);

    void add_song();
    
    void delete_song(int index);
};

#endif