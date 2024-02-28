#include "Menu.h"
#include <iostream>
#include <cassert>

using namespace std;

Menu::Menu() : choice(0) {

    disk.setCollection(&collection);

    greeting();

    while (choice >= 0)
        mainMenu();
}

void Menu::greeting() const {

    cout
        << "Welcome to the Console Collection Manager!\n"
        << "This software is used to manage the user's collection of video game consoles.\n"
        << "Feel free to have a look around."
        << endl;
}

void Menu::mainMenu() {

    cout
        << "Select an operation to perform:\n"
        << "1: View Collection\n"
        << "2: Edit Collection\n"
        << "3: Exit Program"
        << endl;

    cin >> choice;

    switch(choice) {

        case 1:
            viewCollection();
            break;
        case 2:
            editCollection();
            break;
        case 3:
            cout << "Program exiting..." << endl;
            exit(0);
            break;
        default:
            cout << "Invaid Input! Try again." << endl;
            break;
    }

}

void Menu::viewCollection() {
    cout << "Hey look its your collection" << endl;

    if (collection.size() > 0) {

        cout
            << "How would you like to view your collection?\n"
            << "1: View by year, ascending\n"
            << "2: View by year, descending\n"
            << "3: View by name, ascending\n"
            << "4: View by name, descending\n"
            << "5: Return to the main menu"
            << endl;

        cin >> choice;

        switch (choice) {

            case 1:
                collection.sortByYear(0);
                collection.print();
                break;
            case 2:
                collection.sortByYear(1);
                collection.print();
                break;
            case 3:
                collection.sortByName(0);
                collection.print();
                break;
            case 4:
                collection.sortByName(1);
                collection.print();
                break;
            case 5:
                return;
                break;
        }
    }

    else {

        cout
            << "There are no items in your collection!\n"
            << "Try editing your collection and adding an item"
            << endl;

        return;
    }

}

void Menu::editCollection() { cout << "You're editing your collection rn" << endl; }
