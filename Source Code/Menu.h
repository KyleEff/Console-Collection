#include "Collection.h" // Including the header file for the Collection class
#include "Storage.h" // Including the header file for the Storage class

class Menu {
    // Attributes
    Collection collection; // Object to manage the collection of consoles
    Storage disk; // Object to manage storing and retrieving collection data from disk
    int choice; // User's menu choice

public:
    // Constructor
    Menu();

    // Method to display greeting message
    void greeting() const {
        
        cout
            << "\n------------ Welcome to the Console Collection Manager ------------\n"
            << "This software is used to manage the user's collection of video game consoles.\n"
            << "Feel free to have a look around."
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
