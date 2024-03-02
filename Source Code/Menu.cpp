#include "Menu.h"
#include <iostream>
#include <cassert>

using namespace std;

Menu::Menu() :
    choice(0) {

        disk.setCollection(&collection);

        greeting();

        while (choice >= 0)
            mainMenu();
    }

void Menu::mainMenu() {

    cout
        << "Select an operation to perform:\n"
        << "1: View Collection\n"
        << "2: Edit Collection\n"
        << "3: Exit Program"
        << endl
        << ">> ";

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
    cout << "------------ View Collection ------------" << endl;

    if (collection.size() > 0) {

        cout
            << "How would you like to view your collection?\n"
            << "1: View by year, ascending\n"
            << "2: View by year, descending\n"
            << "3: View by name, ascending\n"
            << "4: View by name, descending\n"
            << "5: Return to the main menu"
            << endl
            << ">> ";

        cin >> choice;

        switch (choice) {

            case 1:
                collection.sortByYear(true);
                collection.print();
                break;
            case 2:
                collection.sortByYear(false);
                collection.print();
                break;
            case 3:
                collection.sortByName(true);
                collection.print();
                break;
            case 4:
                collection.sortByName(false);
                collection.print();
                break;
            case 5:
                break;
        }
    }

    else {

        cout
            << "There are no items in your collection!\n"
            << "Try editing your collection and adding an item"
            << endl;
    }
}

void Menu::editCollection() {

    cout
        << "------------ Edit Collection ------------" << endl
        << "Choose how you would like to edit your collection:\n"
        << "1: Add Console\n"
        << "2: Remove Console\n"
        << "3: Load Collection From File\n"
        << "4: Save Collection To File\n"
        << "5: Return to Main Menu"
        << endl
        << ">> ";

    cin >> choice;

    switch (choice) {

        case 1:
            addToCollection();
            break;

        case 2:
            removeFromCollection();
            break;

        case 3:
            cout << "Loading Collection From Disk..." << endl;
            disk.readCollection();
            break;

        case 4:
            cout << "Saving Collection To Disk..." << endl;
            disk.storeCollection();
            break;

        case 5:
            break;

        default:
            cout << "ERROR" << endl;
            break;
    }

}

void Menu::addToCollection() {

    string
        manufacturer,
        name;
    int year = 0;

    cout << "Enter the manufacturer of the console: ";
    cin >> manufacturer;

    cout << "Enter the name of the console: ";
    cin >> name;

    cout << "If you know the year of release, enter it here. Otherwise enter zero: ";
    cin >> year;

    collection.addItem(
        new Console(
            manufacturer,
            name,
            year
        )
    );
}

void Menu::removeFromCollection() {


}


