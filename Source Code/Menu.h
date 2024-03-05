#include "Collection.h"
#include "Storage.h"

class Menu {
// Attributes
    Collection collection;
    Storage disk;
    int choice;

public:
    Menu();

    inline void greeting() const {
        cout
            << "\n------------ Welcome to the Console Collection Manager ------------\n"
            << "This software is used to manage the user's collection of video game consoles.\n"
            << "Feel free to have a look around."
            << endl;
    }
    
    void mainMenu(); // The "main lobby" of the program.
    void viewCollection(); // View information about the collection
    void editCollection(); // Make changes to the collection

    void addToCollection();
    void removeFromCollection();
    void searchCollection();

    inline Collection& getCollection()
        { return collection; } // DEBUG FUNCTION
};