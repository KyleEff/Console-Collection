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

    unordered_map<string, Console> nameTable;
    unordered_map<int, Console> yearTable; // Does not work as intended

    vector<vector<Console>*> yearTable2; // TEST (POSSIBLY CREATE A CUSTOM NODE)

// Function objects for sorting
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

    void sortByYear(bool);
    void sortByName(bool);

    Console searchByName(string);
    Console searchByYear(int); // DOES NOT WORK AS INTENDED

    inline bool search(Console* value) {

        sortByName(true);
        return binary_search(layerOne.begin(), layerOne.end(), *value);
    }

    inline void addItem(Console* add) {

        layerOne.push_back(*add);
        nameTable.insert({ add->getName(), *add });
    }

    inline void addItem(Console add) {

        layerOne.push_back(add);
        nameTable.insert({ add.getName(), add });
    }

    inline void removeItem(int choice)
        { layerOne.erase(layerOne.begin() + (choice - 1)); }

    inline void print() const {
        
        for (auto i{0}; i < layerOne.size(); i++) {
            cout << i + 1 << ": ";
            layerOne[i].print();
        }
    }
    inline int size() const
        { return layerOne.size(); }

    inline Console getItem(int index) const
        { return layerOne[index]; }

    void test();
};
