#pragma once

#include "Console.h"
#include <stdexcept> // Standard Exception classes
#include <vector> // Vector (dynamic storage array)
#include <algorithm> // sort() and binary_search()
#include <unordered_map> // Hash table

using namespace std;

// Class representing a collection of consoles
class Collection {

    vector<Console> layerOne; // Vector to store Console objects
    unordered_map<string, Console> nameTable; // Hash table for fast search by name
    unordered_map<int, vector<Console>*> yearTable; // Hash table for fast search by year

    // Function objects for sort function
    // NOTE: Function objects are used for custom comparison functions for the sort() function
    struct {
        bool operator()(const Console& a, const Console& b) const
            { return a.getYear() < b.getYear(); }
    } sortYearAsc;

    struct {
        bool operator()(const Console& a, const Console& b) const
            { return a.getYear() > b.getYear(); }
    } sortYearDesc;

    struct {
        bool operator()(const Console& a, const Console& b) const
            { return a.getName() < b.getName(); }
    } sortNameAsc;

    struct {
        bool operator()(const Console& a, const Console& b) const
            { return a.getName() > b.getName(); }
    } sortNameDesc;

public:
    // Custom exception classes
    class ItemNotFound : public invalid_argument
        { public: ItemNotFound(const char* what) : invalid_argument(what) {} };

    class EmptyCollection : public range_error
        { public: EmptyCollection(const char* what) : range_error(what) {} };

    // Methods to sort the collection by name or year
    void sortByName(bool); // True if ascending, false if descending
    void sortByYear(bool);

    // Inline Method to sort the hash table full of vectors
    void sortYearTable() {

        for (auto& i : yearTable) // For each vector in the table
            sort(i.second->begin(), i.second->end(), sortNameAsc); // Sort by name ascending
    }

    // Methods to search for a console by name or year
    Console& searchByName(string); // NOT WORKING NEED TO DEBUG
    vector<Console>* searchByYear(int); // Returns a pointer to the vector containing all the consoles from the same year

    // Custom Binary Search that returns an index instead of bool
    int yearTableBinarySearch(Console&);

    // Inline Method to search for a console by binary search (default: by name)
    bool quickSearch(Console* value) {

        sortByName(true); // Ensure collection is sorted by name for binary search
        return binary_search(layerOne.begin(), layerOne.end(), *value); // Binary search
    }

    // Method to add a console to the collection using a pointer
    void addItem(Console*);

    // Overloaded method to add a console to the collection
    void addItem(Console); // NOT USED

    // Method to remove a console from the collection
    void removeItem(int);

    // Method to print all consoles in the collection
    void print() const;

    // Method to get the size of the collection
    int size() const;

    // Method to get a console at a specific index; used for Storage
    Console getItem(int index) const
        { return layerOne[index]; }

    // DEBUG FUNCTIONS NOT USED IN NORMAL OPERATIONS
    void yearTableTest();
    void yearTablePrint();
};
