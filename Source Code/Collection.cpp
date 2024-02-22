#include "Collection.h"

void Collection::addItem(Console* add)
    { layerOne.push_front(*add); }

void Collection::addItem(Console add)
    { layerOne.push_front(add); }

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

    layerOne.push_front(ps2);

    layerOne.push_front(*(new Console("Atari", "2600", new Cpu("MOS Technology", "6507", "1.19 MHz", 1975), 1977)));
}

void Collection::sortByYear()
    { layerOne.sort(sortYear); }

void Collection::sortByName() {

    hashTable.clear();

    for (auto i : layerOne)
        hashTable.insert({i.getName(), i});

    //if (hashTable.find("PS2") != hashTable.end())
    if (hashTable.count("2600"))
        hashTable["2600"].print();

    //sort(layerOne.begin(), layerOne.end(), sortName);
}

