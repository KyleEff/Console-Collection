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
        << "\n------------ Main Menu ------------\n"
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
            cout << "!!! Program exiting... !!!" << endl;
            exit(0);
            break;

        default:
            cout << "Invaid Input! Try again." << endl;
            break;
    }
}

void Menu::viewCollection() {

    try {

        collection.size(); // Throws an exception

        while (choice >= 0) {

            cout
                << "\n------------ View Collection ------------\n"
                << "How would you like to view your collection?\n"
                << "1: View by year, ascending\n"
                << "2: View by year, descending\n"
                << "3: View by name, ascending\n"
                << "4: View by name, descending\n"
                << "5: Search Collection\n"
                << "6: Return to the main menu"
                << endl
                << ">> ";

            cin >> choice;

            switch (choice) {

                case 1:
                    collection.sortByYear(true);
                    cout << "\n------------ Collection By Year, Ascending ------------" << endl;
                    collection.print();
                    break;

                case 2:
                    collection.sortByYear(false);
                    cout << "\n------------ Collection By Year, Descending ------------" << endl;
                    collection.print();
                    break;

                case 3:
                    collection.sortByName(true);
                    cout << "\n------------ Collection By Name, Ascending ------------" << endl;
                    collection.print();
                    break;

                case 4:
                    collection.sortByName(false);
                    cout << "\n------------ Collection By Name, Descending ------------" << endl;
                    collection.print();
                    break;

                case 5:
                    searchCollection();
                    break;

                case 6:
                    return;

                default:
                    cout << "Invalid Input. Try again.\n" << endl;
                    break;
            }
        }
    }

    catch (Collection::EmptyCollection e)
        { cout << e.what() << endl; }
    
}

void Menu::editCollection() {

    while (choice >= 0) {

        cout
            << "\n------------ Edit Collection ------------" << endl
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
                try
                    { disk.readCollection(); }
                catch (Storage::InvalidFile e)
                    { cout << e.what() << endl; }
                break;

            case 4:
                try
                    { disk.storeCollection(); }
                catch (Storage::InvalidFile e)
                    { cout << e.what() << endl; }
                break;

            case 5:
                return;

            default:
                cout << "ERROR" << endl;
                break;
        }
    }
}

void Menu::addToCollection() {

    string
        manufacturer,
        name;

    int year = 0;
    Console* temp{ nullptr };

    cout << "Enter the manufacturer of the console\n>> ";
    cin.ignore();
    getline(cin, manufacturer);

    cout << "Enter the name of the console\n>> ";
    getline(cin, name);

    cout << "If you know the year of release, enter it here. Otherwise enter zero\n>> ";
    cin >> year;

    temp = new Console(manufacturer, name, year);

    if (collection.search(temp))
        cout << "!!! Item already exists inside collection !!!" << endl;
    else
        collection.addItem(temp);

    collection.print();

    delete temp; // garbage collection
}

void Menu::removeFromCollection() {

    collection.print();

    cout << "Enter the list number of the item to remove\n>> ";
    cin >> choice;

    collection.removeItem(choice); // FIGURE THIS SHIT OUT

    cout << "\n------------ Edited Collection ------------" << endl;
    collection.print();
}

void Menu::searchCollection() {

    string nameSearch;
    choice = 0;

    while (choice >= 0) {
        cout
            << "\n------------ Search Collection ------------\n"
            << "How would you like to search?\n"
            << "1: By Name\n"
            << "2: By Year (UNDER CONSTRUCTION)\n"
            << "3: Back to Main Menu"
            << endl
            << ">> ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter the name\n>> ";
                cin >> nameSearch;

                try {

                    cout
                        << "Searching...\n"
                        << endl;

                    collection.searchByName(nameSearch).print();
                }
                catch (Collection::ItemNotFound e)
                    { cout << e.what() << endl; }
                break;

            case 2: // NEED TO SET UP THE NEW DATA STRUCTURE
                cout << "Enter the year\n>> (UNDER CONSTRUCTION)";
                cin >> choice;
            
            case 3:
                return;
        }
    }
}
