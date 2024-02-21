#include "Collection.h"

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
        new Cpu(
            "MIPS",
            "R5900 Emotion Engine",
            "294.912 MHz",
            1999
        ),
        2000
    );

    layerOne.push_back(ps2);

    //layerOne.push_back(*(new Console("Atari", "2600", new Cpu("MOS Technology", "6507", "1.19 MHz", 1975), 1977)));
    
}

void Collection::sortByYear()
    { sort(layerOne.begin(), layerOne.end(), sortYear); }

void Collection::sortByName() {

    hashTable.clear();

    for (auto i : layerOne)
        hashTable.insert({i.getName(), i});

    if (hashTable.find("PS2") != hashTable.end())
        hashTable["2600"].print();

    //sort(layerOne.begin(), layerOne.end(), sortName);
}

