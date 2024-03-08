#pragma once

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

    class InvalidFile : public invalid_argument
        { public: InvalidFile(const char* what) : invalid_argument(what) { } };

    void setCollection(Collection*);
    void storeCollection();
    void readCollection();

    Collection* getCollection();
};
