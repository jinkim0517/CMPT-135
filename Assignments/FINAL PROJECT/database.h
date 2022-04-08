#ifndef DATABASE_H
#define DATABASE_H

#include "songs.h"
#include "cmpt_error.h"
#include "cmpt_trace.h"
#include "curses.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <limits>
#include <fstream>

class Database {
private:
    vector<Song> song_list;
    bool init;
public:
    Database();

    void sort_by_year(vector<Song>& songs, bool desc);

    vector<Song> find_singles_only();

    vector<Song> find_album_only();

    vector<Song> find_by_name(string name, bool reversed);

    vector<Song> find_precise_duration(int duration);

    vector<Song> find_range_duration(int begin, int end, bool desc);

    vector<Song> find_precise_year(int year);

    vector<Song> find_range_year(int begin, int end, bool desc);

    vector<Song> find_by_artist(string artist, bool reversed);

    bool name_check(string name);

    bool artist_check(string artist);

    void add_song();
    
    void delete_song();

    void start();

    void end();

    void get_size();

    bool is_init();

    void set_init(bool ans);
};

#endif