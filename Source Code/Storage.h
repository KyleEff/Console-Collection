#pragma once

#include "Collection.h" // Including the header file for the Collection class
#include "Exceptions.cpp"
#include <fstream> // File stream operations
#include <string> // String manipulation

template <typename T>
class Storage {

    std::string fileName{ "collection.csv" }; // File name for storing collection data
    std::fstream file; // File stream for reading/writing to the file
    Collection<T>* collection{ nullptr }; // Pointer to the collection object

public:
    // Constructors
    Storage();
    Storage(Collection<T>& collection);
    virtual ~Storage();

    // Method to set the collection for storage
    void setCollection(Collection<T>* collection)
        { this->collection = collection; }

    // Method to store the collection data to a file
    void storeCollection();

    // Method to read the collection data from a file
    void readCollection();
};
