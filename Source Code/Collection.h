#pragma once

#include "Console.h"
#include <stdexcept> // Standard Exception classes
#include <vector> // Vector (dynamic storage array)
#include <algorithm> // Sorting algorithms (sort() and binary_search())
#include <unordered_map> // Hash table

using namespace std;

// Class representing a collection of consoles
class Collection {

    vector<Console> layerOne; // Vector to store Console objects
    unordered_map<string, Console> nameTable; // Hash table for fast search by name

    unordered_map<int, Console> yearTable; // Hash table for lookup by year (currently not working as intended)

    vector<vector<Console>*> yearTable2; // Test vector of vectors, possibly for future use with custom node

    // Function objects for sort function
    // NOTE: Function objects are used for custom comparison functions for sorting
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

    // Methods to search for a console by name or year
    Console searchByName(string);
    Console searchByYear(int); // CURRENTLY NOT WORKING AS INTENDED

    // Method to search for a console by binary search (default: by name)
    bool search(Console* value) { 

        sortByName(true); // Ensure collection is sorted by name for binary search
        return binary_search(layerOne.begin(), layerOne.end(), *value);
    }

    // Method to add a console to the collection
    void addItem(Console* add) {

        layerOne.push_back(*add);
        nameTable.insert({ add->getName(), *add });
    }

    // Overloaded method to add a console to the collection
    void addItem(Console add) {

        layerOne.push_back(add);
        nameTable.insert({ add.getName(), add });
    }

    // Method to remove a console from the collection
    void removeItem(int choice) {

        nameTable.erase((layerOne.data() + (choice - 1))->getName());
        layerOne.erase(layerOne.begin() + (choice - 1));
    }

    // Method to print all consoles in the collection
    void print() const;

    // Method to get the size of the collection
    int size() const;

    // Method to get a console at a specific index
    Console getItem(int index) const
        { return layerOne[index]; }

};
