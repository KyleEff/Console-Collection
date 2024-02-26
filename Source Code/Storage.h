#ifndef STORAGE_H
#define STORAGE_H

#include "Collection.h"
#include <fstream>
#include <string>

using namespace std;


class Storage {

    string fileName{ "collection.csv" };
    fstream file;
    Collection* collection{ nullptr };

public:
    Storage();
    Storage(Collection&);
    Storage(Collection*);

    virtual ~Storage();

    void setCollection(Collection*);
    void storeCollection();
    void readCollection();

    Collection* getCollection();
};

#endif