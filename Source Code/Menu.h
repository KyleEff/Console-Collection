#include "Collection.h"
#include "Storage.h"

class Menu {
// Attributes
    Collection collection;
    Storage disk;

    int choice;

public:
    Menu();

    void greeting() const;
    void mainMenu(); // The "main lobby" of the program.
    void viewCollection(); // View information about the collection
    void editCollection(); // Make changes to the collection

    inline Collection& getCollection()
        { return collection; } // DEBUG FUNCTION
};