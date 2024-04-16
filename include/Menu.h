#include "Collection.h" // Including the header file for the Collection class
#include "Storage.h" // Including the header file for the Storage class
#include "Exceptions.h"
#include <iostream>

/**
 * Template Class: Menu
 * 
 * Manages the user interface and interaction with the Console Collection Manager.
 * This class provides a menu-driven interface for users to interact with the collection of consoles.
 * It encapsulates functionalities such as displaying a greeting message, presenting the main menu, viewing information about the collection,
 * making changes to the collection, adding a console to the collection, removing a console from the collection, and searching the collection.
 * 
 * @tparam T The type of elements stored in the collection managed by the menu (Console or its derived classes).
 */

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
        
        std::cout
            << "\n------------ Welcome to the Console Collection Manager ------------\n"
            << "This software is used to manage the user's collection of video game consoles.\n"
            << "Start off by editing your collection to either add a Console, or load a \n"
            << "collection if there is one saved to disk."
            << std::endl;
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

    // Confirms the user's input
    bool confirmInput(T*);
};
