#pragma once

#include "Collection.h" // Including the header file for the Collection class
#include <fstream> // File stream operations
#include <string> // String manipulation

using namespace std;

class Storage {

    string fileName{ "collection.csv" }; // File name for storing collection data
    fstream file; // File stream for reading/writing to the file
    Collection* collection{ nullptr }; // Pointer to the collection object

public:
    // Constructors
    Storage(); // Default constructor
    Storage(Collection&); // Constructor with reference to Collection object

    virtual ~Storage(); // Virtual destructor

    // Custom exception class for invalid file
    class InvalidFile : public invalid_argument
        { public: InvalidFile(const char* what) : invalid_argument(what) { } };

    // Method to set the collection for storage
    void setCollection(Collection* collection)
        { this->collection = collection; }

    // Method to store the collection data to a file
    void storeCollection();

    // Method to read the collection data from a file
    void readCollection();
};
