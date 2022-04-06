#ifndef MENU_H
#define MENU_H

#include "cmpt_error.h"
#include "cmpt_trace.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include "songs.h"
#include "database.h"
#include <curses.h>

class Menu {
public:
    void start_menu();

    void add_menu();

    void display_all_menu(string displayed);

    void find_menu();
};

#endif