#include "Collection.h"
#include "Storage.h"

class Menu {
// Attributes
    int choice;
    Collection collection;
    Storage disk;

public:
    void greeting() const;
    void mainMenu(); // The "main lobby" of the program.
    void viewCollection() const; // View information about the collection
    void editCollection(); // Make changes to the collection
};