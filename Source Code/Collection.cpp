#include "Collection.h" // Including the header file for the Collection class

// Method to sort the collection by year
void Collection::sortByYear(bool choice) {

    // Sorting the collection based on the choice (ascending or descending)
    if (choice)
        sort(layerOne.begin(), layerOne.end(), sortYearAsc); // Sorting in ascending order
    else
        sort(layerOne.begin(), layerOne.end(), sortYearDesc); // Sorting in descending order
}

// Method to sort the collection by name
void Collection::sortByName(bool choice) {

    // Sorting the collection based on the choice (ascending or descending)
    if (choice)
        sort(layerOne.begin(), layerOne.end(), sortNameAsc); // Sorting in ascending order
    else
        sort(layerOne.begin(), layerOne.end(), sortNameDesc); // Sorting in descending order
}

// Method to search for a console by name
Console Collection::searchByName(string name) {

    // Checking if the console with the given name exists in the collection
    if (nameTable.count(name) > 0)
        return nameTable[name]; // Returning the console if found
    else
        throw ItemNotFound("!!! Item Not Found !!!"); // Throwing an exception if not found
}

// Method to search for a console by year
Console Collection::searchByYear(int year) { // DOES NOT WORK AS INTENDED

    // Checking if the console with the given year exists in the collection
    if (yearTable.count(year) > 0)
        return yearTable[year]; // Returning the console if found
    else
        throw ItemNotFound("!!! Item Not Found !!!"); // Throwing an exception if not found
}
