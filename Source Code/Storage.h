#pragma once

#include "Collection.cpp"
#include <fstream>
#include <string>

class Storage {

    string fileName{ "collection.csv" };
    fstream file;
    Collection* collection;

public:
    Storage();
    Storage(Collection*);

    void setCollection(Collection*);
    void storeCollection();
    void readCollection();
};
