#include "Collection.h" // Including the header file for the Collection class
#include "Storage.h" // Including the header file for the Storage class
#include "Exceptions.h"
#include <iostream>

template <typename T>
class Menu {
    // Attributes
    Collection<T> collection; // Object to manage the collection of consoles
    Storage<T> disk; // Object to manage storing and retrieving collection data from disk
    int choice; // User's menu choice

public:
    // Constructor
    Menu() :
        choice(0) {

            disk.setCollection(&collection); // Setting the collection for storage

            greeting(); // Display greeting message

            // Main menu loop
            while (choice >= 0)
                mainMenu();
        }

    // Method to display greeting message
    void greeting() const {
        
        cout
            << "\n------------ Welcome to the Console Collection Manager ------------\n"
            << "This software is used to manage the user's collection of video game consoles.\n"
            << "Start off by editing your collection to either add a Console, or load a \n"
            << "collection if there is one saved to disk."
            << endl;
    }
    
    // Method to display the main menu
    void mainMenu(); // The "main lobby" of the program.

    // Method to view information about the collection
    void viewCollection();

    // Method to make changes to the collection
    void editCollection();

    // Method to add a console to the collection
    void addToCollection();

    // Method to remove a console from the collection
    void removeFromCollection();

    // Method to search the collection for a console
    void searchCollection();
};
