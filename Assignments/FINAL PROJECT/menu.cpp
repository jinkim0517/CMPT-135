#include "menu.h"

// TO DO:
// Make ncurses work

void Menu::start_menu(Database& user_info) {
    if (user_info.is_init()) {
        user_info.start();
        user_info.set_init(false);
    }
    initscr();
    noecho();
    curs_set(0);

    int y_max = 0;
    int x_max = 0;

    getmaxyx(stdscr, y_max, x_max);

    WINDOW *menuwin = newwin(15, x_max - 12, y_max - 60, 5);
    box(menuwin, 0, 0);

    refresh();
    wrefresh(menuwin);

    keypad(menuwin, true);

    mvwprintw(menuwin, 2, 4, "Welcome to the Song Database");
    mvwprintw(menuwin, 3, 4, "----------------------------");

    mvwprintw(menuwin, 5, 4, "What would you like to do?");

    string menus[5] = {"- Add a Song", "- Delete a Song", "- Display Songs", "- Find a Song", 
    "- Quit"};

    int choice = 0;
    int highlight = 0;

    while(true) {
        for (int i = 0; i < 5; i++) {
            if (i == highlight) {
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i + 7, 5, menus[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }

        choice = wgetch(menuwin);

        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight < 0) {
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight > 4) {
                    highlight = 4;
                }
                break;
            default:
                break;
        }

        if (choice == 10) {
            break;
        }
    }

    switch (highlight) {
        case 0:
            endwin();
            user_info = add_menu(user_info);
            break;
        case 1:
            endwin();
            user_info = delete_menu(user_info);
            break;
        case 2:
            endwin();
            user_info = display_menu(user_info);
            break;
        case 3:
            endwin();
            find_menu(user_info);
            break;
        case 4:
            wclear(menuwin);
            mvwprintw(menuwin,  0, 0, "Goodbye!");
    }
    
    getch();
    endwin();
}


Database Menu::add_menu(Database& user_info) {
    system("clear");
    user_info.add_song();

    char main;
    cout << "Would you like to return to the main menu? (y)\n";
    cin >> main;

    if (main == 'y' || main == 'Y') {
        start_menu(user_info);
    }
    else {
        cout << "Goodbye\n";
        user_info.end();
    }
    return user_info;
}

Database Menu::delete_menu(Database& user_info) {
    system("clear");
    user_info.delete_song();

    char main;
    cout << "Would you like to return to the main menu? (y)\n";
    cin >> main;

    if (main == 'y' || main == 'Y') {
        start_menu(user_info);
    }
    else {
        cout << "Goodbye\n";
        user_info.end();
    }
    return user_info;
}

void Menu::find_menu(Database user_info) {
    system("clear");
    cout << "How would you like to find the songs?\n";
    cout << "----------------------------------------\n" << endl;

    cout << "(A) - By Name\n";
    cout << "(B) - By Artist\n";
    cout << "(C) - By Duration\n";
    cout << "(D) - By Release Year\n";
    cout << "(E) - By Single or Album Releases?\n";
    cout << endl;
    cout << "(F) - Return to lobby\n";

    char ans;

    while (!(cin >> ans)) {
        cout << "Please choose a valid option\n";
    }

    while (ans != 'a' && ans != 'A' && ans != 'b' && ans != 'B' && ans != 'c' && ans != 'C' &&
    ans != 'd' && ans != 'D' && ans != 'e' && ans != 'E' && ans != 'f' && ans != 'F') {
        cout << "Please choose a valid option\n";
        cin >> ans;
    }

    system("clear");
    
    if (ans == 'a' || ans == 'A') {
        string name;
        cout << "Name of Song: ";
        cin >> name;
        cout << endl;

        vector<Song> songs = user_info.find_by_name(name, true);
        print_songs(songs);

        songs.clear();
    }
    else if (ans == 'b' || ans == 'B') {
        string artist;
        cout << "Name of Artist: ";
        cin >> artist;
        vector<Song> songs = user_info.find_by_artist(artist, true);
        print_songs(songs);
        songs.clear();
    }
    else if (ans == 'c' || ans == 'C') {
        int duration;
        cout << "Song Length (in seconds): ";
        cin >> duration;
        cout << endl;
        vector<Song> songs = user_info.find_precise_duration(duration);
        print_songs(songs);
        songs.clear();
    }
    else if (ans == 'd' || ans == 'D') {
        int year;
        cout << "Year of Release: ";
        cin >> year;
        cout << endl;
        vector<Song> songs = user_info.find_precise_year(year);
        print_songs(songs);
        songs.clear();
    }
    else if (ans == 'e' || ans == 'E') {
        char ans;
        cout << "Singles only? (y): ";
        cin >> ans;
        cout << endl;

        vector<Song> songs;

        if (ans == 'y') {
            songs = user_info.find_singles_only();
        }
        else {
            songs = user_info.find_album_only();
        }

        print_songs(songs);

        songs.clear();
    }
    else if (ans == 'f' || ans == 'F') {
        start_menu(user_info);
    }
    else {
        cout << "ERROR\n";
    }

    char main;
    cout << "Would you like to return to the main menu? (y)\n";
    cin >> main;

    if (main == 'y' || main == 'Y') {
        start_menu(user_info);
    }
    else {
        cout << "Goodbye\n";
        user_info.end();
    }
}

Database Menu::display_menu(Database& user_info) {
    system("clear");
    cout << "How would you like to display your songs?\n";
    cout << "----------------------------------------\n" << endl;

    cout << "(A) - Alphabetically by Name\n";
    cout << "(B) - Alphabetically by Artist\n";
    cout << "(C) - Sorted by Duration\n";
    cout << "(D) - Sorted by Release Year\n";
    cout << "(E) - Singles or Albums Only\n";
    cout << endl;
    cout << "(F) - Return to lobby\n";

    char ans;

    while (!(cin >> ans)) {
        cout << "Please choose a valid option\n";
    }

    while (ans != 'a' && ans != 'A' && ans != 'b' && ans != 'B' && ans != 'c' && ans != 'C' &&
    ans != 'd' && ans != 'D' && ans != 'e' && ans != 'E' && ans != 'f' && ans != 'F') {
        cout << "Please choose a valid option\n";
        cin >> ans;
    }

    system("clear");
    
    if (ans == 'a' || ans == 'A') {
        vector<Song> songs;

        songs = user_info.find_by_name("", false);

        
        print_songs(songs);
        songs.clear();

        char reverse;
        cout << "Press 'r' to reverse the order! ";
        cin >> reverse;

        if (reverse == 'r') {
            songs = user_info.find_by_name("", true);
            print_songs(songs);
            songs.clear();
        }
    }
    else if (ans == 'b' || ans == 'B') {
        vector<Song> songs;

        songs = user_info.find_by_artist("", false);

        
        print_songs(songs);
        songs.clear();

        char reverse;
        cout << "Press 'r' to reverse the order! ";
        cin >> reverse;

        if (reverse == 'r') {
            system("clear");
            songs = user_info.find_by_artist("", true);
            print_songs(songs);
            songs.clear();
        }
    }
    else if (ans == 'c' || ans == 'C') {
        vector<Song> songs;

        songs = user_info.find_range_duration(0, 0, false);

        print_songs(songs);
        songs.clear();

        char reverse;
        cout << "Press 'r' to reverse the order! ";
        cin >> reverse;
        
        if (reverse == 'r') {
            songs = user_info.find_range_duration(0, 0, true);
            print_songs(songs);
            songs.clear();
        }
        
        print_songs(songs);
        songs.clear();
    }
    else if (ans == 'd' || ans == 'D') {
        vector<Song> songs;

        songs = user_info.find_range_year(0, 0, false);

        print_songs(songs);
        songs.clear();

        char reverse;
        cout << "Press 'r' to reverse the order! ";
        cin >> reverse;

        if (reverse == 'r') {
            songs = user_info.find_range_year(0, 0, true);
            print_songs(songs);
            songs.clear();
        }
    
    }
    else if (ans == 'e' || ans == 'E') {
        vector<Song> songs;

        songs = user_info.find_singles_only();

        print_songs(songs);
        songs.clear();

        char ans;
        cout << "Press 'r' to show only album releases! ";
        cin >> ans;
        cout << endl;
        
        if (ans == 'r') {
            songs = user_info.find_album_only();
            print_songs(songs);
            songs.clear();
        }
    }
    else if (ans == 'f' || ans == 'F') {
        start_menu(user_info);
        return user_info;
    }
    else {
        cout << "ERROR\n";
    }

    char main;
    cout << "Would you like to return to the main menu? (y)\n";
    cin >> main;

    if (main == 'y' || main == 'Y') {
        start_menu(user_info);
    }
    else {
        cout << "Goodbye\n";
        user_info.end();
    }
    return user_info;
}

void Menu::print_songs(vector<Song>& user_songs) {
    if (user_songs.size() != 0) {
        for (int i = 0; i < user_songs.size(); i++) {
            cout << "\"" << user_songs[i].get_name() << "\"" << ", by " 
            << user_songs[i].get_artist() << ", " << user_songs[i].get_duration() << " seconds, " 
            << user_songs[i].get_year() << ", ";

            if (user_songs[i].is_single()) {
                cout << "Single Release.\n";
                cout << endl;
            }
            else {
                cout << "Album Release.\n";
                cout << endl;
            }
        }
        cout << "------------------------------------------\n";
    }
}