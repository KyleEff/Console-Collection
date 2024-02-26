#include "Collection.h"

#include <vector>
#include <sstream>

void Collection::sortByYear()
    { sort(layerOne.begin(), layerOne.end(), sortYear); }

void Collection::sortByName() { // TESTING

    nameTable.clear();

    for (auto i : layerOne)
        nameTable.insert({i.getName(), i});

    //if (hashTable.find("PS2") != hashTable.end())
    if (nameTable.count("2600"))
        nameTable["2600"].print();

    //sort(layerOne.begin(), layerOne.end(), sortName);
}

void Collection::addItem(Console* add)
    { }//layerOne.push_back(*add); }

void Collection::removeItem(int choice) { }

void Collection::searchByName() const {}

void Collection::searchByYear() const {}

void Collection::print() const {

    for (auto i : layerOne)
        i.print();
}

void Collection::test() {

}