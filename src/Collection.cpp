#include "../include/Collection.h" // Including the header file for the Collection class
#include "../include/Console.h"
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Sorts the elements of the collection by year.
 * 
 * This method sorts the elements of the collection based on their year attribute. 
 * It allows sorting in both ascending and descending order, determined by the 
 * boolean parameter `choice`. Sorting is performed using either `sortYearAsc` or
 * `sortYearDesc` comparison functions.
 * 
 * @tparam T The type of elements stored in the collection.
 * @param choice A boolean flag indicating the sorting order:
 *               - `true` for ascending order.
 *               - `false` for descending order.
 * @return void
 */
template <typename T>
void Collection<T>::sortByYear(bool choice) {
    // Sorting the collection based on the choice (ascending or descending)
    if (choice)
        sort(layerOne.begin(), layerOne.end(), sortYearAsc); // Sorting in ascending order
    else
        sort(layerOne.begin(), layerOne.end(), sortYearDesc); // Sorting in descending order
}

/**
 * Sorts the elements of the collection by name.
 * 
 * This method sorts the elements of the collection based on their name attribute. 
 * It allows sorting in both ascending and descending order, determined by the 
 * boolean parameter `choice`. Sorting is performed using either `sortNameAsc` or
 * `sortNameDesc` comparison functions.
 * 
 * @tparam T The type of elements stored in the collection.
 * @param choice A boolean flag indicating the sorting order:
 *               - `true` for ascending order.
 *               - `false` for descending order.
 * @return void
 */
template <typename T>
void Collection<T>::sortByName(bool choice) {
    // Sorting the collection based on the choice (ascending or descending)
    if (choice)
        sort(layerOne.begin(), layerOne.end(), sortNameAsc); // Sorting in ascending order
    else
        sort(layerOne.begin(), layerOne.end(), sortNameDesc); // Sorting in descending order
}

/**
 * Searches for a console by name in the collection.
 * 
 * This method searches for a console within the collection based on its name attribute.
 * It takes a string parameter `name` representing the name of the console to search for.
 * If a console with the provided name is found, a reference to the console is returned.
 * Otherwise, it throws an exception of type `ItemNotFound`.
 * 
 * @tparam T The type of elements stored in the collection.
 * @param name The name of the console to search for.
 * @return A reference to the console if found.
 * @throws ItemNotFound If the console with the specified name is not found in the collection.
 */
template <typename T>
T& Collection<T>::searchByName(string name) {
    // Checking if the console with the given name exists in the collection
    if (nameTable.count(name) > 0)
        return nameTable[name]; // Returning the console if found
    else
        throw ItemNotFound("!!! Item Not Found !!!"); // Throwing an exception if not found
}

/**
 * Method to Search for Consoles by Year
 * 
 * Searches for consoles within the collection based on their release year.
 * 
 * @tparam T The type of elements stored in the collection (Console or its derived classes).
 * @param year The year to search for consoles.
 * @return A pointer to the vector containing consoles released in the specified year.
 * @throws ItemNotFound If no consoles are found for the specified year.
 */
template <typename T>
vector<T>* Collection<T>::searchByYear(int year) {
    // Checking if the console with the given year exists in the collection
    if (yearTable.count(year) > 0)
        return yearTable[year]; // Returning vector of consoles 
    else
        throw ItemNotFound("!!! Item Not Found !!!"); // Throwing an exception if not found
}

/**
 * Method to perform binary search on the year table for a specified value.
 * 
 * Performs binary search on the year table for a specified value.
 * It first sorts the year table to ensure binary search works correctly.
 * Then, it searches for the entry corresponding to the year of the provided value
 * in the year table. If the entry is found, it performs a binary search within the
 * associated vector to find the value. If found, it returns the index of the value
 * in the vector. If not found, it throws an exception of type `ItemNotFound`.
 * 
 * @tparam T The type of elements stored in the collection.
 * @param value The value to search for in the year table.
 * @return The index of the value in the vector associated with its year, if found.
 *         Otherwise, returns -1.
 * @throws ItemNotFound If the specified value is not found in the year table.
 */
template <typename T>
int Collection<T>::yearTableBinarySearch(T& value) {
    
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

/**
 * Method to add a Console object to the collection using a pointer.
 * 
 * Adds a Console object to the collection using a pointer to the object.
 * This method checks if the console already exists in the collection using a quick search.
 * If the console does not exist, it checks if the year table has an entry for the console's year.
 * If not, it creates a new entry with the console as the first element of a vector.
 * If an entry already exists, it pushes the console into the vector for that year.
 * Additionally, the console is added to the main vector and name table.
 * 
 * @tparam T The type of elements stored in the collection.
 * @param add A pointer to the Console object to be added to the collection.
 * @throws InvalidInput If the console already exists inside the collection.
 */
template <typename T>
void Collection<T>::addItem(T* add) {
    // Check if the console already exists in the collection
    if (!quickSearch(add)) {
        // Check if the year table has an entry for the console's year
        if (yearTable.count(add->getYear()) == 0) 
            // If not, create a new entry with the console as the first element of a vector
            yearTable.insert({
                add->getYear(),
                new vector<T>(1, *add)
            });
        else // If an entry already exists, push the console into the vector for that year
            yearTable[add->getYear()]->push_back(*add);

        // Add the console to the main vector and name table
        layerOne.push_back(*add);
        nameTable.insert({ add->getLowerCase(), *add });
    }

    else // If the console already exists, throw an exception
        throw InvalidInput("\n!!! Item already exists inside collection !!!");
}

// NOT USED
template <typename T>
void Collection<T>::addItem(T add) {

    if (yearTable.count(add.getYear()) == 0) 
        yearTable.insert({ add.getYear(), new vector<T>(1, add) });
    else
        yearTable[add.getYear()]->push_back(add);

    layerOne.push_back(add);
    nameTable.insert({ add.getName(), add });
}

/**
 * Method to remove an item from the collection.
 * 
 * Removes an item from the collection based on the specified choice.
 * It finds the index of the item to be removed in the main vector,
 * then gets the release year of the item to be removed.
 * It erases the item from the vector associated with its release year
 * and removes the entry from the year table if the vector becomes empty.
 * Additionally, it erases the item from the name table.
 * 
 * @tparam T The type of elements stored in the collection.
 * @param choice The index of the item to be removed in the main vector.
 */
template <typename T>
void Collection<T>::removeItem(int choice) {
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

/**
 * Method to print all Consoles in the collection.
 * 
 * Prints all Consoles in the collection along with their details.
 * It displays a header for the console listing and then iterates through
 * the collection, printing the manufacturer, name, and year of each console.
 * The details of each console are printed using its print method.
 * If the collection is empty, it catches and handles the EmptyCollection exception.
 * 
 * @tparam T The type of elements stored in the collection.
 */
template <typename T>
void Collection<T>::print() const {
    // Displaying header for the console listing
    cout
        << "  # |                   Manufacturer                  |                     Name                        | Year \n"
        << "----+-------------------------------------------------+-------------------------------------------------+-------"
        << endl;

    try {
        // Iterate through the collection
        for (auto i{0}; i < size(); i++) { // size() throws an exception
            // Displaying the index of the console
            cout
                << right
                << setw(3)
                << i + 1
                << " | ";
            // Printing the details of the console using its print method
            layerOne[i].print();

            cout
                << "----+"
                << "-------------------------------------------------+"
                << "-------------------------------------------------+"
                << "-------"
                << endl;
        }
    }
    // Catching exception if the collection is empty
    catch (EmptyCollection& e)
        { cout << e.what() << endl; }
}

/**
 * Method to get the size of the collection.
 * 
 * Returns the number of items in the collection.
 * If the collection is empty, it throws an EmptyCollection exception.
 * 
 * @tparam T The type of elements stored in the collection.
 * @return The number of items in the collection.
 * @throws EmptyCollection If the collection is empty.
 */
template <typename T>
int Collection<T>::size() const {
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
template <typename T>
void Collection<T>::yearTableTest() { // DEBUG FUNCTION

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

template <typename T>
void Collection<T>::yearTablePrint() { // DEBUG FUNCITON

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

/**
 * Explicit Template Instantiation for Collection<Console>
 * 
 * This line explicitly instantiates the Collection class template with the Console class as its template argument.
 * It instructs the compiler to generate the code for all member functions of the Collection class template with Console 
 * as the template parameter. This is useful for separating the declaration and definition of templates into different 
 * files, as it ensures that the template code is compiled only once and linked appropriately.
 */

template class Collection<Console>;