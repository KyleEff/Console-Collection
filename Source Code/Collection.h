#pragma once

#include "Console.cpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

class Collection {

    vector<Console> layerOne;

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
    inline void searchByYear() const;
    inline void sortByName();
    inline void searchByName() const;

    inline void addItem(Console*);
    inline void addItem(Console);
    inline void removeItem(Console*);
    inline void removeItem(Console);

    void print() const;
    inline int size() const;
    inline Console getItem(int) const;

    void test();
};
