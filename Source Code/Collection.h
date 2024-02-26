#ifndef COLLECTION_H
#define COLLECTION_H

#include "Console.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

class Collection {

    vector<Console> layerOne;

    unordered_map<string, Console> nameTable;
    unordered_map<int, Console> yearTable;
public:
    struct
        { bool operator()(const Console& a, const Console& b) const { return a.getName() < b.getName(); } }
        sortName;

    struct
        { bool operator()(const Console& a, const Console& b) const { return a.getYear() < b.getYear(); } }
        sortYear;

public:
    void sortByYear();
    void sortByName();

    void addItem(Console*);
    //inline void addItem(Console* add) { layerOne.push_back(*add); }

    inline void addItem(Console add)
        { layerOne.push_back(add); }

    void removeItem(int);

    void searchByName() const;
    void searchByYear() const;
    void print() const;

    inline int size() const
        { return layerOne.size(); }

    inline Console getItem(int index) const
        { return layerOne[index]; }

    void test();
};

#endif


