#include "Collection.h" // Including the header file for the Collection class
#include <iostream>
#include <iomanip>

using namespace std;

// Method to sort the collection by year
void Collection::sortByYear(bool choice) {

    // Sorting the collection based on the choice (ascending or descending)
    if (choice)
        sort(layerOne.begin(), layerOne.end(), sortYearAsc); // Sorting in ascending order
    else
        sort(layerOne.begin(), layerOne.end(), sortYearDesc); // Sorting in descending order
}

void Collection::sortYearTable() {

    cout << "!!! SORT YEAR TABLE!!! " << endl;

    for (auto& i : yearTable)
        sort(i.second->begin(), i.second->end(), sortNameAsc);
    
    //yearTablePrint();
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

int Collection::yearTableBinarySearch(Console& value) {

    cout << "!!! YEAR TABLE BINARY SEARCH !!!" << endl;

    sortYearTable();

    auto it{ yearTable.find(value.getYear()) };
    if (it == yearTable.end())
        return -1;

    auto result{ lower_bound(it->second->begin(), it->second->end(), value) };

    if (result != it->second->end() && *result == value)
        return distance(it->second->begin(), result);
    else
        throw ItemNotFound("!!! Item Not Found !!!");
    
    return -1; // Fail safe
}

void Collection::addItem(Console* add) {

    if (!quickSearch(add)) {

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

    else
        throw Console::InvalidInput("\n!!! Item already exists inside collection !!!");
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

    int
        tempIndex{ yearTableBinarySearch(*(layerOne.begin() + (choice - 1))) },
        tempYear{ layerOne[choice - 1].getYear() };

    yearTable[tempYear]->erase(
        yearTable[tempYear]->begin() + tempIndex
    );

    nameTable.erase((layerOne.data() + (choice - 1))->getName());
    layerOne.erase(layerOne.begin() + (choice - 1));
}

// Method to print all consoles in the collection
void Collection::print() const {
    
    try {

        cout
            << " # |  Manufacturer |         Name       | Year \n"
            << "------------------------------------------------"
            << endl;

        for (auto i{0}; i < size(); i++) {
            
            cout
                << right
                << setw(3)
                << i + 1
                << '|';
            
            layerOne[i].print();
        }
    }
    catch (EmptyCollection e)
        { cout << e.what() << endl; }
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

    //cout << yearTableBinarySearch(&temp->at(0)) << endl;
}

void Collection::yearTablePrint() { // DEBUG FUNCITON

    cout << "!!! YEAR TABLE PRINT !!!" << endl;

    for (const auto& i : yearTable) {
        cout
            << "Year: " << i.first
            << endl
            << "Consoles: \n";
        
        for (const auto& j : *i.second)
            j.print();
    }
}
