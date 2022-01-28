// evenwins.cpp
/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Jinsung Kim
// St.# : 301539203
// Email: jka287@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough detail
// so that someone can see the exact source and extent of the borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have not
// seen solutions from other students, tutors, websites, books, etc.
//
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

enum class Player {
    human,
    computer
};

struct Gamestate {
    Player whose_turn;
    int marbles_in_middle = -1;
    int human_marbles     = -1;
    int computer_marbles  = -1;
    int computer_wins = 0;
    int player_wins = 0;
    int human_take = 0;
    bool first_turn = false;
};

void welcome_screen() {
    cout << "+--------------------------+\n";
    cout << "|  Welcome to Even Wins!   |\n";
    cout << "+--------------------------+\n";
    cout << "Even Wins is a two-person game. You start with\n";
    cout << "27 marbles in the middle of the table.\n";
    cout << "\n";
    cout << "Players alternate taking marbles from the middle.\n";
    cout << "A player can take 1 to 4 marbles on their turn, and\n";
    cout << "turns cannot be skipped. The game ends when there are\n";
    cout << "no marbles left, and the winner is the one with an even\n";
    cout << "number of marbles.";
    cout << "\n";
}

string marbles_str(int n) {
    if (n == 1) return "1 marble";
    return to_string(n) + " marbles";
}

void choose_first_player(Gamestate &variables) {
   for (;;) {
        cout << "\nDo you want to play first? (y/n) --> ";
        string ans;
        cin >> ans;
        if (ans == "y") {
            variables.whose_turn = Player::human;
            variables.first_turn = true;
            return;
        } else if (ans == "n") {
            variables.whose_turn = Player::computer;
            return;
        } else {
            cout << "\nPlease enter 'y' if you want to play first,\n";
            cout << "or 'n' if you want to play second.\n";
        }
    }
} // choose_first_player

void next_player(Gamestate &variables) {
    variables.whose_turn = (variables.whose_turn == Player::human) ? Player::computer :
    (variables.whose_turn == Player::computer) ? Player::human : Player::computer;
}

void print_board(Gamestate &variables) {
    cout << "\n";
    cout << " marbles in the middle: " << variables.marbles_in_middle 
         << " " << string(variables.marbles_in_middle, '*') << "\n";
    cout << "    # marbles you have: " << variables.human_marbles << "\n";
    cout << "# marbles computer has: " << variables.computer_marbles << "\n";
    cout <<  "\n";
}

// returns true if s is an int, and false otherwise
// https://www.cplusplus.com/reference/string/stoi/
bool is_int(const string& s) {
    try {
        stoi(s); // throws an invalid_argument exception if conversion fails
        return true;
    } catch (...) {
        return false;
    }
}

void human_turn(Gamestate &variables) {
    // get number in range 1 to min(4, marbles_in_middle)
    int max_choice = min(4, variables.marbles_in_middle);
    cout << "It's your turn!\n";
    for(;;) {
        cout << "Marbles to take? (1 - " << max_choice << ") --> ";
        string s;
        cin >> s;
        if (!is_int(s)) {
            cout << "\n  Please enter a whole number from 1 to " << max_choice
                 << "\n";
            continue;
        }

        // convert s to an int so it can be compared
        int n = stoi(s);
        if (n < 1) {
            cout << "\n  You must take at least 1 marble\n";
            continue;
        }
        if (n > max_choice) {
            cout << "\n  You can take at most " << marbles_str(max_choice)
                 << "\n";
            continue;
        }

        variables.human_take = n;

        cout << "\nOkay, taking " << marbles_str(n) << " ...\n";
        variables.marbles_in_middle -= n;
        variables.human_marbles += n;

        return;
    }
} // human_turn

int mirror_play(int max_choice, Gamestate &variables){
    int computer_take = rand() % (max_choice + 1);
    while (computer_take == 0){
        computer_take = rand() % (max_choice + 1);
    }

    // If the player takes and even number of marbles, take an even number
    if (variables.human_take % 2 == 0){
        while ((computer_take % 2) != 0) {
            computer_take = rand() % (max_choice + 1);
            while (computer_take == 0){
                computer_take = rand() % (max_choice + 1);
            }
        }
    }
    // If the player takes and odd number of marbles, take an odd number
    else {
        while ((computer_take % 2) == 0) {
            computer_take = rand() % (max_choice + 1);
            while (computer_take == 0){
                computer_take = rand() % (max_choice + 1);
            }
        }
    }
    return computer_take;
} // mirror_play

/* 
My strategy to improving the computer's playstyle was to mirror what the player's take value's 
type, which means taking an even number of marbles when the player takes even, and an odd number 
of marbles when the player takes odd. This results in the first turn deciding the course of the game. 
The first turn directly relates to that last few turns when the number of marbles is less than or equal 
to 5, because whoever goes first gains the last turn to either take the single last marble or decide
to take a values from 1 to 4, which can change their number of marbles to even or odd. In addition,
the computer picks the opposite type of value compared to the player's take so that the two hands have 
opposite type of value throughout the game. My implementation is perfect because the "computer_turn" 
function accounts for every possible winning play when there are 5 or less marbles, and chooses the 
appropriate one.
*/
void computer_turn(Gamestate &variables) {
    cout << "It's the computer's turn ...\n";
    int max_choice = min(4, variables.marbles_in_middle);
    int computer_take = rand() % (max_choice + 1);

    while (computer_take == 0){
        computer_take = rand() % (max_choice + 1);
    }

    // If player goes first, pick the opposite type of integer than what they picked
    // so that the winning choices during last turns will be easier to program
    //(human: picks even    computer: picks odd)

    if (variables.first_turn == true) {
        // If the player takes and even number of marbles, take an odd number
        if (variables.human_take % 2 == 0){
            while ((computer_take % 2) == 0 ) {
                computer_take = rand() % (max_choice + 1);
                while (computer_take == 0){
                    computer_take = rand() % (max_choice + 1);
                }
            }
        }
        else {
            // If the player takes an odd number of marbles, take an even number
            while ((computer_take % 2) != 0) {
                computer_take = rand() % (max_choice + 1);
                while (computer_take == 0){
                    computer_take = rand() % (max_choice + 1);
                }
            }
        }
        variables.first_turn = false;
    }
    else if (variables.marbles_in_middle > 5){
        // Mirrors the player by taking the same type of integer of what player picked
        computer_take = mirror_play(max_choice, variables);
    }
    else {
        // Take the maximum number of marbles that wins you the game
        if (variables.marbles_in_middle > 3 && variables.computer_marbles % 2 == 0) {
            computer_take = 4;
        }
        // When there are 3 or less marbles, take the amount that wins you the game
        else if (variables.computer_marbles % 2 != 0 && variables.marbles_in_middle >= 3) {
            computer_take = 3;
        }
        else if (variables.computer_marbles % 2 == 0 && variables.marbles_in_middle >= 2){
            computer_take = 2;
        }
        else {
            computer_take = 1;
        }
    }
    cout << "Computer takes " << marbles_str(computer_take) << " ...\n";
    variables.marbles_in_middle -= computer_take;
    variables.computer_marbles += computer_take;
} // computer_turn

void game_over(Gamestate &variables) {
    string taunts[] = {
        "The computer wins: tremble before my mighty brain!\n", 
        "The computer wins: You are no match for my humongus brain!\n", 
        "The computer wins: This is too easy! I can do this forever... literally!\n", 
        "The computer wins: *Yawn* This is sooo boring! Are you even trying?!\n", 
        "The computer wins: Haha! Here's a tip, give up!\n"
    };
    cout << "\n";
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
         << "!! All the marbles are taken: Game Over !!\n"
         << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";

    print_board(variables);

    if (variables.human_marbles % 2 == 0) {
        cout << "You are the winner! Congratulations!\n";
        variables.player_wins++;
    } else {
        // Chooses random taunt
        cout << taunts[rand() % 5];
        variables.computer_wins++;
    }
}

void play_game(Gamestate &variables) {
    // initialize the game state
    variables.marbles_in_middle = 27;
    variables.human_marbles = 0;
    variables.computer_marbles = 0;
    print_board(variables);

    for (;;) {
        if (variables.marbles_in_middle == 0) {
            game_over(variables);
            return;
        } else if (variables.whose_turn == Player::human) {
            human_turn(variables);
            print_board(variables);
            next_player(variables);
        } else if (variables.whose_turn == Player::computer) {
            computer_turn(variables);
            print_board(variables);
            next_player(variables);
        }
    }
} // play_game

int main() {
    Gamestate play_info;
    srand(time(NULL));

    welcome_screen();

    for(;;) {
        choose_first_player(play_info);
        play_game(play_info);

        // ask if the user if they want to play again
        cout << "\nWould you like to play again? (y/n) --> ";
        string again;
        cin >> again;
        if (again == "y") {
            cout << "\nOk, let's play again ...\n";
        } else {
            cout << "\nOk, thanks for playing ... goodbye!\n";
            cout << "Statisctics:\n";
            cout << "------------\n";
            cout << "Total Games: "   << play_info.player_wins + play_info.computer_wins
                 << endl;
            cout << "Player Wins: "   << play_info.player_wins       << endl;
            cout << "Computer Wins: " << play_info.computer_wins     << endl;
            return 0;
        }
    }
} // main
