#pragma once

#include "Collection.h" // Including the header file for the Collection class
#include "Exceptions.h"
#include <fstream> // File stream operations
#include <string> // String manipulation

/**
 * @class Storage
 * 
 * The Storage class provides functionality to store and retrieve collection data from a file.
 * It is templated to work with any type of collection.
 * 
 * Data Members:
 * - fileName: A string representing the file name for storing collection data.
 * - file: A file stream for reading and writing to the file.
 * - collection: A pointer to the collection object.
 * 
 * Constructors:
 * - Storage(): Default constructor.
 * - Storage(Collection<T>& collection): Parameterized constructor that sets the collection.
 * - ~Storage(): Destructor to release resources.
 * 
 * Public Methods:
 * - setCollection(Collection<T>* collection): Method to set the collection for storage.
 * - storeCollection(): Method to store the collection data to a file.
 * - readCollection(): Method to read the collection data from a file.
 */
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
