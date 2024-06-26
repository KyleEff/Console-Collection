#pragma once

#include "Exceptions.h"
#include <vector> // Vector (dynamic storage array)
#include <algorithm> // sort() and binary_search()
#include <unordered_map> // Hash table

/**
 * @class Collection
 * @brief A template class representing a collection of objects of type T.
 * 
 * This class manages a collection of objects of type T, where T is typically a derived class
 * of the Collectable class. It provides various methods for sorting, searching, adding, and removing
 * items from the collection. The collection is stored internally in a vector and two hash tables,
 * allowing for efficient search and retrieval operations.
 * 
 * The class defines several function objects for custom comparison functions used in sorting operations.
 * These function objects facilitate sorting the collection by name or year in ascending or descending order.
 * 
 * Public Methods:
 *  - sortByName(bool ascending): Sorts the collection by name in ascending or descending order.
 *  - sortByYear(bool ascending): Sorts the collection by year in ascending or descending order.
 *  - searchByName(std::string name): Searches the collection for an item by its name.
 *  - searchByYear(int year): Searches the collection for items released in a specific year.
 *  - yearTableBinarySearch(T& item): Performs a binary search on the collection's year table.
 *  - quickSearch(T* value): Searches for an item in the collection using binary search (by name).
 *  - addItem(T* item): Adds an item to the collection using a pointer.
 *  - addItem(T item): Overloaded method to add an item to the collection.
 *  - removeItem(int index): Removes an item from the collection at the specified index.
 *  - print(): Prints all items in the collection.
 *  - size(): Returns the size of the collection.
 *  - getItem(int index): Retrieves an item from the collection at the specified index.
 *  - yearTableTest(): Debug function to test the year table.
 *  - yearTablePrint(): Debug function to print the contents of the year table.
 */
template <typename T>
class Collection {

    std::vector<T> layerOne; // Vector to store Console objects
    std::unordered_map<std::string, T> nameTable; // Hash table for fast search by name
    std::unordered_map<int, std::vector<T>*> yearTable; // Hash table for fast search by year

    // Function objects for sort function
    // NOTE: Function objects are used for custom comparison functions for the std::sort() function
    struct {
        bool operator()(const T& a, const T& b) const
            { return a.getYear() < b.getYear(); }
    } sortYearAsc;

    struct {
        bool operator()(const T& a, const T& b) const
            { return a.getYear() > b.getYear(); }
    } sortYearDesc;

    struct {
        bool operator()(const T& a, const T& b) const
            { return a.getName() < b.getName(); }
    } sortNameAsc;

    struct {
        bool operator()(const T& a, const T& b) const
            { return a.getName() > b.getName(); }
    } sortNameDesc;

public:
    // Methods to sort the collection by name or year
    void sortByName(bool); // True if ascending, false if descending
    void sortByYear(bool);

    // Inline Method to sort the hash table full of vectors
    void sortYearTable() {

        for (auto& i : yearTable) // For each vector in the table
            sort(i.second->begin(), i.second->end(), sortNameAsc); // Sort by name ascending
    }

    // Methods to search for a console by name or year
    T& searchByName(std::string); // Returns a reference to a Console matched by name
    std::vector<T>* searchByYear(int); // Returns a pointer to the vector containing all the consoles from the same year

    // Custom Binary Search that returns an index instead of bool
    int yearTableBinarySearch(T&);

    // Inline Method to search for a console by binary search (default: by name)
    bool quickSearch(T* value) {

        sortByName(true); // Ensure collection is sorted by name for binary search
        return binary_search(layerOne.begin(), layerOne.end(), *value); // Binary search
    }

    // Method to add a console to the collection using a pointer
    void addItem(T*);

    // Overloaded method to add a console to the collection
    void addItem(T); // NOT USED

    // Method to remove a console from the collection
    void removeItem(int);

    // Method to print all consoles in the collection
    void print() const;

    // Method to get the size of the collection
    int size() const;

    // Method to get a console at a specific index; used for Storage
    T& getItem(int index)
        { return layerOne[index]; }

    // DEBUG FUNCTIONS NOT USED IN NORMAL OPERATIONS
    void yearTableTest();
    void yearTablePrint();
};
