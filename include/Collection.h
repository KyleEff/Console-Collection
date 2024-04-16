#pragma once

#include "Exceptions.h"
#include <vector> // Vector (dynamic storage array)
#include <algorithm> // sort() and binary_search()
#include <unordered_map> // Hash table

/**
 * Collection Class
 * 
 * The Collection class is a templated container designed to manage a collection of objects of type T. 
 * In this context, it is specifically tailored for managing a collection of Console objects.
 * 
 * Data Members:
 * - layerOne: A vector to store objects of type T, which in this context are Console objects.
 * - nameTable: An unordered map (std::unordered_map) facilitating fast searching of consoles by name.
 * - yearTable: An unordered map used for efficient searching of consoles by year. It maps integer keys 
 *              (representing years) to pointers to vectors of type T (consoles of the same year).
 * 
 * Function Objects for Sorting:
 * - sortYearAsc: A function object for sorting consoles by year in ascending order.
 * - sortYearDesc: A function object for sorting consoles by year in descending order.
 * - sortNameAsc: A function object for sorting consoles by name in ascending order.
 * - sortNameDesc: A function object for sorting consoles by name in descending order.
 * 
 * Public Methods:
 * - sortByName(bool): Sorts the collection by name in ascending or descending order.
 * - sortByYear(bool): Sorts the collection by year in ascending or descending order.
 * - sortYearTable(): Inline method to sort the hash table of vectors by name ascending.
 * - searchByName(string): Searches for a console by name and returns a reference to the matched console.
 * - searchByYear(int): Searches for consoles by year and returns a pointer to the vector containing 
 *                      consoles from the same year.
 * - yearTableBinarySearch(T&): Custom binary search that returns the index of the matched console in 
 *                              the year table.
 * - quickSearch(T*): Inline method to search for a console using binary search, defaulting to name 
 *                    search and ensuring the collection is sorted by name.
 * - addItem(T*): Adds a console to the collection using a pointer.
 * - addItem(T): Overloaded method to add a console to the collection (not used).
 * - removeItem(int): Removes a console from the collection based on the specified index.
 * - print(): Method to print all consoles in the collection.
 * - size(): Method to get the size of the collection.
 * - getItem(int): Method to get a console at a specific index, used for Storage.
 * 
 * Debug Methods (Not Used in Normal Operations):
 * - yearTableTest(): Debug function to test the year table.
 * - yearTablePrint(): Debug function to print the year table.
 */
template <typename T>
class Collection {

    std::vector<T> layerOne; // Vector to store Console objects
    std::unordered_map<std::string, T> nameTable; // Hash table for fast search by name
    std::unordered_map<int, std::vector<T>*> yearTable; // Hash table for fast search by year

    // Function objects for sort function
    // NOTE: Function objects are used for custom comparison functions for the sort() function
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
