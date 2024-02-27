#include "Collection.h"

void Collection::sortByYear(int choice) {

    if (choice == 0)
        sort(layerOne.begin(), layerOne.end(), sortYearAsc);
    else sort(layerOne.begin(), layerOne.end(), sortYearDesc);
}

void Collection::sortByName(int choice) {

    if (choice == 0)
        sort(layerOne.begin(), layerOne.end(), sortNameAsc);
    else sort(layerOne.begin(), layerOne.end(), sortNameDesc);
}

Console Collection::searchByName(string name) {

    if (nameTable.empty())
        for (auto i : layerOne)
            nameTable.insert({i.getName(), i});

    if (nameTable.count(name) > 0)
        return nameTable[name];
    else throw ItemNotFound("Item Not Found");
}

Console Collection::searchByYear(int year) { // DOES NOT WORK AS INTENDED

    if (yearTable.empty())
        for (auto i : layerOne)
            yearTable.insert({i.getYear(), i});

    if (yearTable.count(year) > 0)
        return yearTable[year];
    else throw ItemNotFound("Item Not Found");
}

void Collection::test() {

}