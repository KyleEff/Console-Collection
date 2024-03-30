#include "Collection.h" // Including the header file for the Collection class
#include <iostream>
#include <iomanip>

// Method to sort the collection by year
void Collection::sortByYear(bool choice) {
    // Sorting the collection based on the choice (ascending or descending)
    if (choice)
        sort(layerOne.begin(), layerOne.end(), sortYearAsc); // Sorting in ascending order
    else
        sort(layerOne.begin(), layerOne.end(), sortYearDesc); // Sorting in descending order
}

// Method to sort the collection by name
void Collection::sortByName(bool choice) {
    // Sorting the collection based on the choice (ascending or descending)
    if (choice)
        sort(layerOne.begin(), layerOne.end(), sortNameAsc); // Sorting in ascending order
    else
        sort(layerOne.begin(), layerOne.end(), sortNameDesc); // Sorting in descending order
}

// Method to search for a console by name
Console& Collection::searchByName(string name) {
    // Checking if the console with the given name exists in the collection
    if (nameTable.count(name) > 0)
        return nameTable[name]; // Returning the console if found
    else
        throw ItemNotFound("!!! Item Not Found !!!"); // Throwing an exception if not found
}

// Method to search for a console by year
vector<Console>* Collection::searchByYear(int year) {
    // Checking if the console with the given year exists in the collection
    if (yearTable.count(year) > 0)
        return yearTable[year]; // Returning vector of consoles 
    else
        throw ItemNotFound("!!! Item Not Found !!!"); // Throwing an exception if not found
}

int Collection::yearTableBinarySearch(Console& value) {
    
    sortYearTable(); // Sort the year table to ensure binary search works correctly

    // Find the entry for the specified year in the year table
    auto it{ yearTable.find(value.getYear()) };
    // If the entry is not found, return -1
    if (it == yearTable.end())
        return -1;

    // Perform a binary search within the vector associated with the year
    // The data type returned from lower_bound is of type Iterator
    auto result{ lower_bound(it->second->begin(), it->second->end(), value) };

    // If the element is found, return its index in the vector
    if (result != it->second->end() && *result == value)
        return distance(it->second->begin(), result);
    else // If the element is not found, throw an exception
        throw ItemNotFound("!!! Item Not Found !!!");

    // This line is never reached due to the throw statement above
    return -1; // Fail safe
}

// Method that uses a pointer to add a Console object to the collection
void Collection::addItem(Console* add) {
    // Check if the console already exists in the collection
    if (!quickSearch(add)) {
        // Check if the year table has an entry for the console's year
        if (yearTable.count(add->getYear()) == 0) 
            // If not, create a new entry with the console as the first element of a vector
            yearTable.insert({
                add->getYear(),
                new vector<Console>(1, *add)
            });
        else // If an entry already exists, push the console into the vector for that year
            yearTable[add->getYear()]->push_back(*add);

        // Add the console to the main vector and name table
        layerOne.push_back(*add);
        nameTable.insert({ add->getName(), *add });
    }

    else // If the console already exists, throw an exception
        throw Console::InvalidInput("\n!!! Item already exists inside collection !!!");
}

// NOT USED
void Collection::addItem(Console add) {

    if (yearTable.count(add.getYear()) == 0) 
        yearTable.insert({ add.getYear(), new vector<Console>(1, add) });
    else
        yearTable[add.getYear()]->push_back(add);

    layerOne.push_back(add);
    nameTable.insert({ add.getName(), add });
}

// Method to remove an item from 
void Collection::removeItem(int choice) {
    // Find the index of the console to be removed in the vector
    int tempIndex{ yearTableBinarySearch(*(layerOne.begin() + (choice - 1))) };
    // Get the release year of the console to be removed
    int tempYear{ layerOne[choice - 1].getYear() };

    // Erase the console from the vector associated with its release year
    yearTable[tempYear]->erase(
        yearTable[tempYear]->begin() + tempIndex
    );

    // If the vector associated with the release year becomes empty, erase the entry from the year table
    if (yearTable[tempYear]->size() == 0)
        yearTable.erase(tempYear);

    // Erase the console from the name table
    nameTable.erase((layerOne.data() + (choice - 1))->getName());
    // Erase the console from the main collection vector
    layerOne.erase(layerOne.begin() + (choice - 1));
}

// Method to print all Consoles in the collection
void Collection::print() const {
    // Displaying header for the console listing
    cout
        << " # |  Manufacturer |         Name       | Year \n"
        << "------------------------------------------------"
        << endl;

    try {
        // Iterate through the collection
        for (auto i{0}; i < size(); i++) { // size() throws an exception
            // Displaying the index of the console
            cout
                << right
                << setw(3)
                << i + 1
                << '|';
            // Printing the details of the console using its print method
            layerOne[i].print();
        }
    }
    // Catching exception if the collection is empty
    catch (EmptyCollection& e)
        { cout << e.what() << endl; }
}

// Method to get the size of the collection
int Collection::size() const {
    // Check if the collection is empty
    if (layerOne.size() < 1) {
        // Throw exception if the collection is empty
        throw EmptyCollection(
            "\n!!! There are no items in your collection!\nTry editing your collection and adding an item !!!"
        );
    } else {
        // Return the size of the collection
        return layerOne.size();
    }
}

// DEBUG FUNCTIONS NOT USED IN NORMAL OPERATIONS
void Collection::yearTableTest() { // DEBUG FUNCTION

    cout << "!!!!!!!!!!!!!!! YEAR TABLE TEST !!!!!!!!!!!!!!!" << endl;
    /*
    for (const auto& i : yearTable) {
        cout
            << "Year: " << i.first
            << endl
            << "Consoles: \n";
        
        
        for (const auto& j : *i.second) // This is ok for right now....
            j.print();
    }
    */

    //for (auto& i : *yearTable[1977]) i.print();

    //cout << yearTableBinarySearch(&temp->at(0)) << endl;
}

void Collection::yearTablePrint() { // DEBUG FUNCITON

    cout << "!!! YEAR TABLE PRINT !!!" << endl;

    for (const auto& i : yearTable) {
        cout
            << "Year: " << i.first
            << endl
            << "Consoles: \n";
        
        for (const auto& j : *i.second)
            j.print();
    }
}
