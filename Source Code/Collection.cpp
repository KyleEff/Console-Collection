#include "Collection.h"

void Collection::addItem(Console* add)
    { layerOne.push_back(*add); }

void Collection::addItem(Console add)
    { layerOne.push_back(add); }

void Collection::print() const {

    for (auto i : layerOne)
        i.print();
}

void Collection::test() {

    Console ps2(
        "Sony",
        "PlayStation 2",
        2000
    );

    layerOne.push_back(ps2);

    layerOne.push_back(*(new Console("Atari", "2600", 1977)));
}

void Collection::sortByYear()
    { sort(layerOne.begin(), layerOne.end(), sortYear); }

void Collection::sortByName() { // TESTING

    hashTable.clear();

    for (auto i : layerOne)
        hashTable.insert({i.getName(), i});

    //if (hashTable.find("PS2") != hashTable.end())
    if (hashTable.count("2600"))
        hashTable["2600"].print();

    //sort(layerOne.begin(), layerOne.end(), sortName);
}

int Collection::size() const
    { return layerOne.size(); }

Console Collection::getItem(int index) const
    { return layerOne[index]; }
