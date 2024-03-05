#include "Storage.h"
#include <vector>
#include <sstream>

Storage::Storage() :
    collection(nullptr) { }

Storage::Storage(Collection& collection) :
    collection(&collection) { }

Storage::Storage(Collection* collection) :
    collection(collection) { }

Storage::~Storage() {

    delete collection;
    collection = nullptr;
}

void Storage::setCollection(Collection* collection)
    { this->collection = collection; }

void Storage::storeCollection() {

    string line, temp;

    file.open(fileName, ios::out);
    /*              // TEST
        for (int i = 0; i < 5; i++)
            collection->addItem(
                new Console(
                    "Sony",
                    "PlayStation3",
                    2007
                )
            );
    */

    cout << "Saving Collection To Disk..." << endl;

    if (file)
        for (auto i = 0; i < collection->size(); i++) 
            file << collection->getItem(i) << endl;
    else
        cout << "!!! PROBLEM WITH FILE !!!" << endl;
        
    file.close();
    
    cout << "!!! Collection Saved !!!" << endl;
}

void Storage::readCollection() {

    string line, temp;

    file.open(fileName, ios::in);

    cout << "Loading Collection From Disk..." << endl;

    if (file) 
        while (getline(file, line)) {

            vector<string> row;
            stringstream buff(line);

            row.clear();

            while (getline(buff, line, ',')) 
                row.push_back(line);
            
/*        //          DEBUG STATEMENTS
            cout << "PRINT ROW" << endl;
            for (auto i : row)
                cout << i << endl;
*/
            if (collection != nullptr) {

                try {
                    if (stoi(row[2]) > 0)
                        collection->addItem(
                            new Console(
                                row[0],
                                row[1],
                                stoi(row[2])
                            )
                        );

                    else collection->addItem(
                        new Console(
                            row[0],
                            row[1],
                            0
                        )
                    );
                }
                catch(exception e)
                    { cout << e.what() << endl; }
            }
        }
    
    file.close();

    cout << "!!! Collection Loaded !!!" << endl;
}


Collection* Storage::getCollection()
    { return collection; }
