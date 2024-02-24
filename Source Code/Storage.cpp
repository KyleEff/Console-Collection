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

    string line, temp;

    file.open(fileName, ios::out);

// TEST
    for (int i = 0; i < 1000; i++)
        collection->addItem(
            new Console(
                "Sony",
                "PlayStation 3",
                2007
            )
        );

    collection->addItem(
        new Console(
            "Sony",
            "PlayStation 3",
            2007
        )
    );

    for (auto i = 0; i < collection->size(); i++)  {

        file << collection->getItem(i);

        //cout << collection->getItem(i) << endl;
    }

    file.close();

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

                else
                collection->addItem(
                    new Console(
                        row[0],
                        row[1]
                    )
                );
            }
            catch(exception e)
                { }//cout << e.what() << endl; }
        }
    }

    //collection->print();

    file.close();
}
