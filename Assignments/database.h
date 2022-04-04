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

class Database {
private:
    vector<Song> song_list;
public:
    Database();

    void print_names_alpha();

    void print_artists_alpha();

    void print_duration(bool desc);

    bool name_check(string name);

    bool artist_check(string artist);

    void print_singles_only();

    void add_song();
    
    void delete_song();
};

#endif