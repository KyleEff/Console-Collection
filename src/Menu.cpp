#include "../include/Menu.h" // Including the header file for the Menu class
#include "../include/Console.h"
#include <iostream> // Input/output stream
#include <cassert> // Assertion support
#include <chrono>
//#include <format>

using namespace std;

/**
 * Method: mainMenu
 * 
 * Displays the main menu of the Console Collection Manager.
 * Users can select various operations such as viewing the collection, editing the collection,
 * or exiting the program. The method prompts the user for input and handles the user's choice
 * using a switch statement. It redirects the user to the corresponding operation based on their choice.
 * 
 * @tparam T The type of elements stored in the collection managed by the menu (Console or its derived classes).
 * 
 * This method presents the main menu options to the user and waits for user input. It then processes the
 * user's choice and performs the corresponding action. If the user selects "View Collection", the method
 * calls the viewCollection() function. If "Edit Collection" is chosen, it calls editCollection(). Choosing
 * "Exit Program" terminates the program. Any other input is considered invalid, and the method prompts the user
 * to try again.
 */
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

/**
 * Method: viewCollection
 * 
 * Displays information about the collection of consoles.
 * Users can choose various options to view the collection, such as sorting by year or name,
 * searching the collection, or returning to the main menu.
 * 
 * @tparam T The type of elements stored in the collection managed by the menu (Console or its derived classes).
 * 
 * This method presents a menu to the user to choose how they want to view the collection. They can opt to view
 * the collection sorted by year in ascending or descending order, or sorted by name in ascending or descending order.
 * Additionally, they can choose to search the collection for a specific console. The method handles the user's choice
 * using a switch statement and calls the corresponding functions to perform the desired action. If the collection
 * is empty, the method catches the EmptyCollection exception and displays an appropriate message to the user.
 */
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

/**
 * Method: editCollection
 * 
 * Allows the user to make changes to the collection of consoles.
 * Users can choose to add or remove consoles from the collection, load the collection from a file,
 * or save the collection to a file. After each operation, the user is prompted to choose another action
 * or return to the main menu.
 * 
 * @tparam T The type of elements stored in the collection managed by the menu (Console or its derived classes).
 * 
 * This method presents a menu to the user to choose how they want to edit the collection. They can add a new console
 * to the collection, remove an existing console, load the collection from a file, or save the collection to a file.
 * The method handles the user's choice using a switch statement and calls the corresponding functions to perform
 * the desired action. If there are any issues with loading or saving the collection to a file, appropriate error
 * messages are displayed to the user.
 */

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

/**
 * Method: addToCollection
 * 
 * Allows the user to add a new console to the collection.
 * The method prompts the user to enter the manufacturer, name, and year of release for the new console.
 * It then creates a new console object based on the user input and attempts to add it to the collection.
 * If successful, the updated collection is printed to the console.
 * 
 * @tparam T The type of elements stored in the collection managed by the menu (Console or its derived classes).
 * 
 * This method guides the user through the process of adding a new console to the collection. It prompts the user
 * to enter the manufacturer, name, and year of release for the new console. The user input is validated, and if
 * the input is valid, a new console object is created and added to the collection using the Collection<T>::addItem
 * method. If the input is invalid or if there are any issues adding the console to the collection, appropriate
 * error messages are displayed to the user.
 */
template <typename T>
void Menu<T>::addToCollection() {

    string
        manufacturer,
        name;

    int year;
    T* temp{ nullptr };

    //auto now = chrono::system_clock::now();

    cout << "Enter the manufacturer of the console\n>> ";
    cin.ignore(); // Ignore leading whitespace on the input buffer
    getline(cin, manufacturer);

    cout << "Enter the name of the console\n>> ";
    getline(cin, name);

    cout << "If you know the year of release, enter it here. Otherwise enter zero\n>> ";
    cin >> year;

    while (year < 0 || year > 2025) { //|| year > stoi(format("{:%Y}", now))) {

        cout << "\n!!!The year you have entered is invalid!!!\nTry Again\n>> ";
        cin >> year;
    }

    temp = new T(manufacturer, name, year);

    if (!confirmInput(*temp))
        return;
   
    try
        { collection.addItem(temp); }
    catch (InvalidInput& e)
        { cout << e.what() << endl; }

    collection.print();

    delete temp; // Deallocating memory for temporary console object
}

/**
 * Method: removeFromCollection
 * 
 * Allows the user to remove a console from the collection.
 * The method first checks if the collection is empty. If it is not empty,
 * it displays the current contents of the collection along with a prompt
 * for the user to enter the list number of the item they want to remove.
 * After receiving the user input, it attempts to remove the specified console
 * from the collection using the Collection<T>::removeItem method.
 * If successful, the updated collection is printed to the console.
 * 
 * @tparam T The type of elements stored in the collection managed by the menu (Console or its derived classes).
 * 
 * This method facilitates the removal of a console from the collection. It first checks if the collection is empty,
 * and if not, it displays the current contents of the collection to the user along with a prompt to enter the list
 * number of the item they want to remove. It then attempts to remove the specified console from the collection using
 * the Collection<T>::removeItem method. If the input is invalid or if there are any issues removing the console from
 * the collection, appropriate error messages are displayed to the user.
 */

template <typename T>
void Menu<T>::removeFromCollection() {

    try {

        collection.size(); // Will throw an exception if the collection is empty
        collection.print();

        cout << "Enter the list number of the item to remove\n>> ";
        cin >> choice;
        
        if (!confirmInput(collection.getItem(choice - 1)))
            return;

        collection.removeItem(choice); // Remove console from collection

        cout << "\n------------ Edited Collection ------------" << endl;
        collection.print();
    }
    catch (EmptyCollection& e)
        { cout << e.what() << endl; }
}

/**
 * Method: searchCollection
 * 
 * Allows the user to search the collection for a console based on either its name or year of release.
 * The method presents the user with menu options to choose the search criteria: by name or by year.
 * If the user chooses to search by name, they are prompted to enter the name of the console they want to find.
 * The method then performs a case-insensitive search for consoles matching the entered name using the
 * Collection<T>::searchByName method. If the user chooses to search by year, they are prompted to enter
 * the release year of the console. The method then searches for consoles released in the specified year
 * using the Collection<T>::searchByYear method. If consoles matching the search criteria are found, their
 * details are printed to the console. If no consoles are found or if there are any issues during the search process,
 * appropriate error messages are displayed.
 * 
 * @tparam T The type of elements stored in the collection managed by the menu (Console or its derived classes).
 * 
 * This method facilitates searching the collection for consoles based on either their name or year of release.
 * The user is presented with menu options to choose the search criteria: by name or by year. If the user chooses
 * to search by name, they are prompted to enter the name of the console they want to find, and the method performs
 * a case-insensitive search for consoles matching the entered name. If the user chooses to search by year, they
 * are prompted to enter the release year of the console, and the method searches for consoles released in the
 * specified year. If consoles matching the search criteria are found, their details are printed to the console.
 * If no consoles are found or if there are any issues during the search process, appropriate error messages
 * are displayed to the user.
 */
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

// Confirmation Function
template <typename T>
bool Menu<T>::confirmInput(T& input) {

    char choice;

    cout
        << "\n---------- CONFIRM INPUT ----------\n"
        << "You have entered:\n"
        << "                  Manufacturer                   |                     Name                        | Year \n"
        << "-------------------------------------------------+-------------------------------------------------+-------\n ";

    input.print();

    cout
        << "-------------------------------------------------+"
        << "-------------------------------------------------+"
        << "-------"
        << endl;

    cout << "Is this correct? (Y/N)\n>> ";
    cin.ignore();
    cin >> choice;

    return (tolower(choice) == 'y');
}

/**
 * Explicit Template Instantiation: Menu<Console>
 * 
 * Instantiates the Menu class template with the type parameter T set to Console.
 * This instantiation creates a specialized version of the Menu class specifically tailored to manage
 * a collection of Console objects. It provides functionality to interact with and manipulate a collection
 * of Console objects, including viewing, editing, adding, and removing consoles, as well as searching the
 * collection based on various criteria. The instantiated Menu<Console> class operates on a Collection<Console>
 * object and utilizes a Storage<Console> object for storing and retrieving collection data from disk.
 * 
 * By explicitly instantiating the Menu class with the Console type, the compiler generates the necessary
 * code for the Menu class to operate on Console objects, reducing compilation time and improving code efficiency.
 */
template class Menu<Console>;