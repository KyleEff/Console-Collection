#include "Menu.h"
#include <iostream>
#include <cassert>

using namespace std;

void Menu::greeting() const {

    cout
        << "Welcome to the Console Collection Manager!\n"
        << "This software is used to manage the user's collection of video game consoles.\n"
        << "Feel free to have a look around."
        << endl;
}

void Menu::mainMenu() {

    choice = 0;

    cout
        << "Select an operation to perform:\n"
        << "1: View Collection\n"
        << "2: Edit Collection\n"
        << "3: Exit Program"
        << endl;

    cin >> choice;

    while (choice != 3)
    switch(choice) {

        case 1:
            viewCollection();
            break;
        case 2:
            editCollection();
            break;
        case 3:
            assert(false);
        default:
            break;
    }

}

void Menu::viewCollection() const {}

void Menu::editCollection() {}
