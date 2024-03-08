#pragma once

#include "Console.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

class Collection {

    vector<Console> layerOne;
    unordered_map<string, Console> nameTable; // Search by name

    unordered_map<int, Console> yearTable; // Does not work as intended

    vector<vector<Console>*> yearTable2; // TEST (POSSIBLY CREATE A CUSTOM NODE)

    // Function objects for sort function
    // NOTE: !!! I did not know what a function object was until this project !!!
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
    class ItemNotFound : public invalid_argument
        { public: ItemNotFound(const char* what) : invalid_argument(what) {} };

    class EmptyCollection : public range_error
        { public: EmptyCollection(const char* what) : range_error(what) {} };

    void sortByName(bool); // True if ascending, false if descending
    void sortByYear(bool); 

    Console searchByName(string);
    Console searchByYear(int); // DOES NOT WORK AS INTENDED

    bool search(Console* value) { // default binary search by name

        sortByName(true);
        return binary_search(layerOne.begin(), layerOne.end(), *value);
    }

    void addItem(Console* add) {

        layerOne.push_back(*add);
        nameTable.insert({ add->getName(), *add });
    }

    void addItem(Console add) {

        layerOne.push_back(add);
        nameTable.insert({ add.getName(), add });
    }

    void removeItem(int choice) { // FIX THIS (MAJOR PROBLEM)
        
        //nameTable.erase();
        // nameTable.erase(layerOne.begin() + (choice - 1));
        throw int(556546);
        layerOne.erase(layerOne.begin() + (choice - 1));
    }

    void print() const {
        
        for (auto i{0}; i < layerOne.size(); i++) {
            cout << i + 1 << ": ";
            layerOne[i].print();
        }
    }

    int size() const { // LOOK INTO MOVING OUT INTO CPP FILE

        if (layerOne.size() < 1 )
            throw EmptyCollection(
                "!!! There are no items in your collection!\nTry editing your collection and adding an item !!!"
            );
        else
            return layerOne.size();
    }

    Console getItem(int index) const
        { return layerOne[index]; }

};
