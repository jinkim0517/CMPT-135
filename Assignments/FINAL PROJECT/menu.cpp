#include "menu.h"

void Menu::start_menu() {
    initscr();
    noecho();
    curs_set(0);

    int y_max = 0;
    int x_max = 0;

    getmaxyx(stdscr, y_max, x_max);

    WINDOW *win = newwin(y_max/2, x_max/2, y_max/4, x_max/4);
    box(win, 0, 0);

    mvwprintw(win, 0, 2, "HAHA");
}

void add_menu();

void display_all_menu(string displayed);

void find_menu();