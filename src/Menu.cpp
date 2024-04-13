#include "../include/Menu.h" // Including the header file for the Menu class
#include "../include/Console.h"
#include <iostream> // Input/output stream
#include <cassert> // Assertion support

using namespace std;

// Method to display the main menu
template <typename T>
void Menu<T>::mainMenu() {

    cout
        << "\n------------ Main Menu ------------\n"
        << "Select an operation to perform:\n"
        << "1: View Collection\n"
        << "2: Edit Collection\n"
        << "0: Exit Program"
        << endl
        << ">> ";

    cin >> choice;

    // Switch statement to handle user choice
    switch(choice) {

        case 1:
            viewCollection(); // View collection
            break;

        case 2:
            editCollection(); // Edit collection
            break;

        case 0:
            cout << "!!! Program exiting... !!!" << endl;
            exit(0); // Exit program
            break;

        default:
            cout << "Invalid Input! Try again." << endl;
            break;
    }
}

// Method to view information about the collection
template <typename T>
void Menu<T>::viewCollection() {
    try {

        collection.size(); // Throws an exception if the collection is empty

        // Display menu options until the user chooses to return to the main menu
        while (choice >= 0) {
            // Displaying the menu options for viewing the collection
            cout << "\n------------ View Collection ------------\n"
                 << "How would you like to view your collection?\n"
                 << "1: View by year, ascending\n"
                 << "2: View by year, descending\n"
                 << "3: View by name, ascending\n"
                 << "4: View by name, descending\n"
                 << "5: Search Collection\n"
                 << "0: Return to the main menu"
                 << endl
                 << ">> ";

            cin >> choice; // Get user's choice

            switch (choice) {
                
                case 1: // Sort and print the collection by year in ascending order
                    collection.sortByYear(true);
                    cout << "\n----------------------------------------- Collection By Year, Ascending ----------------------------------------" << endl;
                    collection.print();
                    break;

                case 2: // Sort and print the collection by year in descending order
                    collection.sortByYear(false);
                    cout << "\n---------------------------------------- Collection By Year, Descending ----------------------------------------" << endl;
                    collection.print();
                    break;

                case 3: // Sort and print the collection by name in ascending order
                    collection.sortByName(true);
                    cout << "\n---------------------------------------- Collection By Name, Ascending -----------------------------------------" << endl;
                    collection.print();
                    break;

                case 4: // Sort and print the collection by name in descending order
                    collection.sortByName(false);
                    cout << "\n---------------------------------------- Collection By Name, Descending ----------------------------------------" << endl;
                    collection.print();
                    break;

                case 5:
                    searchCollection(); // Call function to search the collection
                    break;

                case 0:
                    return; // Return to main menu

                default:
                    cout << "Invalid Input. Try again.\n" << endl;
                    break;
            }
        }
    }

    catch (EmptyCollection& e) // Catch and handle the exception if the collection is empty
        { cout << e.what() << endl; }
}


// Method to edit the collection
template <typename T>
void Menu<T>::editCollection() {

    while (choice >= 0) {

        cout
            << "\n------------ Edit Collection ------------" << endl
            << "Choose how you would like to edit your collection:\n"
            << "1: Add Console\n"
            << "2: Remove Console\n"
            << "3: Load Collection From File\n"
            << "4: Save Collection To File\n"
            << "0: Return to Main Menu"
            << endl
            << ">> ";

        cin >> choice;

        switch (choice) {

            case 1:
                addToCollection(); // Add console to collection
                break;

            case 2:
                removeFromCollection(); // Remove console from collection
                break;

            case 3:
                try
                    { disk.readCollection(); } // Read collection from file
                catch (InvalidFile& e)
                    { cout << e.what() << endl; }
                break;

            case 4:
                try
                    { disk.storeCollection(); } // Store collection to file
                catch (InvalidFile& e)
                    { cout << e.what() << endl; }
                break;

            case 0:
                return; // Return to main menu

            default:
                cout << "ERROR" << endl;
                break;
        }
    }
}

// Method to add a console to the collection
template <typename T>
void Menu<T>::addToCollection() {

    string
        manufacturer,
        name;

    int year = 0;
    T* temp{ nullptr };

    cout << "Enter the manufacturer of the console\n>> ";
    cin.ignore(); // Ignore leading whitespace on the input buffer
    getline(cin, manufacturer);

    cout << "Enter the name of the console\n>> ";
    getline(cin, name);

    cout << "If you know the year of release, enter it here. Otherwise enter zero\n>> ";
    cin >> year;

    temp = new T(manufacturer, name, year);

    try
        { collection.addItem(temp); }
    catch (InvalidInput& e)
        { cout << e.what() << endl; }

    collection.print();

    delete temp; // Deallocating memory for temporary console object
}

// Method to remove a console from the collection
template <typename T>
void Menu<T>::removeFromCollection() {

    try {

        collection.size(); // Will throw an exception if the collection is empty
        collection.print();

        cout << "Enter the list number of the item to remove\n>> ";
        cin >> choice;
        
        collection.removeItem(choice); // Remove console from collection

        cout << "\n------------ Edited Collection ------------" << endl;
        collection.print();
    }
    catch (EmptyCollection& e)
        { cout << e.what() << endl; }
}

// Method to search the collection for a console
template <typename T>
void Menu<T>::searchCollection() {

    string nameSearch;
    choice = 0;

    while (choice >= 0) {
        // Displaying the menu options for searching the collection
        cout
            << "\n------------ Search Collection ------------\n"
            << "How would you like to search?\n"
            << "1: By Name\n"
            << "2: By Year\n"
            << "0: Back to previous menu"
            << endl
            << ">> ";

        cin >> choice; // Get user's choice

        switch (choice) {

            case 1: // Search for consoles by name
                
                cout << "Enter the name\n>> ";
                cin.ignore();
                getline(cin, nameSearch);
                transform( // transform the user input into lower case
                    nameSearch.begin(),
                    nameSearch.end(),
                    nameSearch.begin(),
                    ::tolower
                );

                try {
                    
                    cout << "Searching...\n" << endl;
                    // Search for consoles by name and print the details
                    collection.searchByName(nameSearch).print();
                }
                catch (ItemNotFound& e) // Catch and handle the exception if console not found
                    { cout << e.what() << endl; }
                catch (exception& e)// Catch and handle any other exceptions
                    { cout << e.what() << endl; }
                break;

            case 2: // Search for consoles by year
                cout << "Enter the year\n>> ";
                cin >> choice;

                try {

                    cout << "Searching...\n" << endl;
                    // Search for consoles by year and print the details
                    for (const auto& i : *collection.searchByYear(choice))
                        i.print();
                }
                
                catch (ItemNotFound& e) // Catch and handle the exception if console not found
                    { cout << e.what() << endl; }
                break;

            case 0:
                return; // Return to main menu

            default:
                return; // Fail safe
        }
    }
}

template class Menu<Console>;
