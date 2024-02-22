#pragma once

#include "Collection.cpp"
#include <fstream>

class Storage {

    string fileName{ "collection.csv" };
    fstream file(fileName);
    Collection* collection;

public:
    Storage();
    Storage(Collection*);

    void setCollection(Collection*);
    void storeCollection();
    void readCollection();
};
