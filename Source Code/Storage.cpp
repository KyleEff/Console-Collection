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

void Storage::storeCollection() { }

void Storage::readCollection() {

    string line, temp;

    file.open(fileName, ios::in);

    if (collection != nullptr) {

        while (file >> line) {

            vector<string> row;

            //char* tokens = strtok(line.c_str(), ',');

            //for (auto i : strtok(line, ',')) row.push_back(i);

            //while (getline(file, line, ',')) row.push_back(line);
/*
            collection->addItem(
                new Console(
                    row[0],
                    row[1],
                    new Cpu(
                        row[2],
                        row[3],
                        row[4],
                        stoi(row[5])
                    ),
                    stoi(row[6])
                )
            );
            */
        }

        collection->print();
        
        //for (auto i : row) cout << i << endl;
    }

    file.close();
}
