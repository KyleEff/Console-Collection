#include "Storage.h"
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

Storage::Storage() :
    collection(nullptr) { }

Storage::Storage(Collection* collection) :
    collection(collection) { }

void Storage::setCollection(Collection* collection)
    { this->collection = collection; }

void Storage::storeCollection() { 


}

void Storage::readCollection() {

    string line, temp;

    file.open(fileName, ios::in);

    while (file >> line) {

        vector<string> row;
        stringstream buff(line, ios::in);

        row.clear();

        while (getline(buff, temp, ',')) 
            row.push_back(temp);
        
        if (collection != nullptr)
            collection->addItem(
                new Console(
                    row[0],
                    row[1],
                    stoi(row[2])
                )
            );
    }

    collection->print();

    file.close();
}
