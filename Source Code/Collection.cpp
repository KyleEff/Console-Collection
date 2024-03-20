#include "Collection.h" // Including the header file for the Collection class
#include <iostream>

// Method to sort the collection by year
void Collection::sortByYear(bool choice) {

    // Sorting the collection based on the choice (ascending or descending)
    if (choice)
        sort(layerOne.begin(), layerOne.end(), sortYearAsc); // Sorting in ascending order
    else
        sort(layerOne.begin(), layerOne.end(), sortYearDesc); // Sorting in descending order
}

void Collection::sortYearTable() {

    for (auto& i : yearTable) {
        sort(*i.second->begin(), *i.second->end(), sortNameAsc);
    }
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
vector<Console>* Collection::searchByYear(int year) { // DOES NOT WORK AS INTENDED

    // Checking if the console with the given year exists in the collection
    if (yearTable.count(year) > 0)
        return yearTable[year]; // Returning vector of consoles 
    else
        throw ItemNotFound("!!! Item Not Found !!!"); // Throwing an exception if not found
}

int Collection::binarySearch(Console* value) {

    int low{ 0 };
    int high{ size() };

    while (low <= high) {

        int mid{ (low + high) / 2 };
        Console* guess{ &yearTable[value->getYear()]->at(mid) };

        if (*guess == *value)
            return mid;
        else if (*guess < *value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    // If the index is not returned from the while loop, an exception is thrown
    throw ItemNotFound("!!! Item Not Found !!!");
    
    return 0; // Fail safe
}

void Collection::addItem(Console* add) {

    if (yearTable.count(add->getYear()) == 0) 
        yearTable.insert({
            add->getYear(),
            new vector<Console>(1, *add)
        });
    else
        yearTable[add->getYear()]->push_back(*add);

    layerOne.push_back(*add);
    nameTable.insert({ add->getName(), *add });
}

// NOT USED
void Collection::addItem(Console add) { 

    if (yearTable.count(add.getYear()) == 0) 
        yearTable.insert({ add.getYear(), new vector<Console>(1, add) });
    else 
        yearTable[add.getYear()]->push_back(add);
    
    layerOne.push_back(add);
    nameTable.insert({ add.getName(), add });
}

void Collection::removeItem(int choice) {

    int tempIndex{ binarySearch((layerOne.begin() + (choice - 1))) };
    yearTable[layerOne[choice - 1].getYear()]->erase(layerOne.begin() + tempIndex);

    nameTable.erase((layerOne.data() + (choice - 1))->getName());
    layerOne.erase(layerOne.begin() + (choice - 1));
}

// Method to print all consoles in the collection
void Collection::print() const {
    
    try {

        for (auto i{0}; i < size(); i++) {
            
            std::cout << i + 1 << ": ";
            layerOne[i].print();
        }
    }
    catch (EmptyCollection e)
        { std::cout << e.what() << endl; }
}

// Method to get the size of the collection
int Collection::size() const {

    if (layerOne.size() < 1 )
        throw EmptyCollection(
            "\n!!! There are no items in your collection!\nTry editing your collection and adding an item !!!"
        );
    else
        return layerOne.size();
}


void Collection::yearTableTest() {

    cout << "!!!!!!!!!!!!!!! YEAR TABLE TEST !!!!!!!!!!!!!!!" << endl;
    /*
    for (const auto& i : yearTable) {
        cout
            << "Year: " << i.first
            << endl
            << "Consoles: \n";
        
        
        for (const auto& j : *i.second) // This is ok for right now....
            j.print();
    }
    */

    //for (auto& i : *yearTable[1977]) i.print();


    //cout << binarySearch(&temp->at(0)) << endl;
}
