#include "Collection.h"

void Collection::sortByYear(bool choice) {

    if (choice)
        sort(layerOne.begin(), layerOne.end(), sortYearAsc);
    else sort(layerOne.begin(), layerOne.end(), sortYearDesc);
}

void Collection::sortByName(bool choice) {

    if (choice)
        sort(layerOne.begin(), layerOne.end(), sortNameAsc);
    else sort(layerOne.begin(), layerOne.end(), sortNameDesc);
}

Console Collection::searchByName(string name) {

    if (nameTable.count(name) > 0)
        return nameTable[name];
    else throw ItemNotFound("Item Not Found");
}

Console Collection::searchByYear(int year) { // DOES NOT WORK AS INTENDED

    if (yearTable.count(year) > 0)
        return yearTable[year];
    else throw ItemNotFound("Item Not Found");
}

void Collection::test() {

}