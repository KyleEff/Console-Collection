#pragma once

#include "Console.cpp"
#include <vector>
#include <forward_list>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

class Collection {

    forward_list<Console> layerOne;
    vector<forward_list<Console>> sortedYear;

    unordered_map<string, Console> hashTable;
public:
    struct
        { bool operator()(const Console& a, const Console& b) const { return a.getName() < b.getName(); } }
        sortName;

    struct
        { bool operator()(const Console& a, const Console& b) const { return a.getYear() < b.getYear(); } }
        sortYear;

public:
    inline void sortByYear();
    inline void sortByName();

    inline void addItem(Console*);
    inline void addItem(Console);
    inline void removeItem(Console*);
    inline void removeItem(Console);

    void print() const;
    int size() const;

    void test();
};
