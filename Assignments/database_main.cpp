#include "menu.h"

using namespace std;

int main() {
    Database test;

    test.add_song();
    test.print_artists_alpha();
    test.print_duration(true);
    test.add_song();
    test.print_artists_alpha();
    test.print_duration(true);
    test.delete_song();
}