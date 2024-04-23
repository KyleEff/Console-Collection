#include "../include/Storage.h" // Including the header file for the Storage class
#include "../include/Console.h"
#include <vector> // Standard vector container
#include <sstream> // String stream operations
#include <iostream>
#include <chrono>

using namespace std;

/**
 * Default Constructor for Storage
 * 
 * Initializes a Storage object with a null pointer to the collection.
 */
template <typename T>
Storage<T>::Storage() :
    collection(nullptr) { }

/**
 * Constructor with Reference to Collection Object
 * 
 * Initializes a Storage object with a reference to a Collection object.
 * 
 * @param collection A reference to the Collection object to be associated with the Storage.
 */
template <typename T>
Storage<T>::Storage(Collection<T>& collection) :
    collection(&collection) { }

/**
 * Destructor for Storage
 * 
 * Cleans up resources associated with the Storage object.
 * It deallocates memory for the collection and resets the pointer to nullptr.
 */
template <typename T>
Storage<T>::~Storage() {

    delete collection; // Deallocating memory for the collection
    collection = nullptr; // Resetting pointer to nullptr
}

/**
 * Method to Store Collection Data to a File
 * 
 * Writes the data of the collection to a file. Each item in the collection is written as a separate line in the file.
 * 
 * This method first attempts to open the file specified by the file name for writing. If the file opening is successful,
 * it iterates over each item in the collection, retrieving the details of each item using the `getItem` method of the
 * collection. These details are then written to the file, followed by a newline character to separate each item.
 * 
 * If the collection is empty, an EmptyCollection exception is thrown to indicate that the collection cannot be stored
 * as there are no items to store. If the file cannot be opened for writing, an InvalidFile exception is thrown.
 * 
 * @throws InvalidFile If the file cannot be opened for writing.
 * @throws EmptyCollection If the collection is empty and cannot be stored.
 */
template <typename T>
void Storage<T>::storeCollection() {

    string line; // string to place the data that is written to disk

    // Opening the file for writing
    file.open(fileName, ios::out);

    // Writing collection data to the file
    if (file) {

        cout << "\nSaving Collection To Disk..." << endl;

        try {
            // Iterating over each item in the collection
            for (auto i = 0; i < collection->size(); i++) // Throws exception if collection is empty
                file << collection->getItem(i) << endl;

            cout << "!!! Collection Saved !!!" << endl;
        }
        catch (EmptyCollection& e) { // Handling empty collection exception
        
            cout << e.what() << endl;
            file.close();
        }
    }
    else
        throw InvalidFile("!!! Invalid File !!!");
        
    // Closing the file
    file.close(); 
}

/**
 * Method to Read Collection Data from a File
 * 
 * Reads the data of the collection from a file. Each line in the file represents an item in the collection.
 * 
 * This method first attempts to open the file specified by the file name for reading. If the file opening is successful,
 * it reads each line from the file, parsing it as a CSV line to extract the details of each item in the collection.
 * The extracted details include the manufacturer, name, and year of each console. If the year value is greater than zero,
 * it creates a new console object using the extracted details and adds it to the collection using the `addItem` method.
 * If the year value is not greater than zero, it adds a console with a year value of zero to the collection.
 * 
 * If the collection pointer is null, no action is taken. Any exceptions thrown during file reading or parsing are caught
 * and appropriate error messages are displayed.
 * 
 * @throws InvalidFile If the file cannot be opened for reading.
 */
template <typename T>
void Storage<T>::readCollection() {

    string line; // string containing the csv line

    // Opening the file for reading
    file.open(fileName, ios::in);

    cout << "\nLoading Collection From Disk..." << endl;

    // Reading collection data from the file
    if (file) 
        while (getline(file, line)) {

            vector<string> row;
            stringstream buff(line);

            row.clear();

            // Parsing the CSV line into tokens
            while (getline(buff, line, ',')) 
                row.push_back(line);

            if (collection != nullptr) {

                try {
                    // Adding console to collection based on CSV data
                    if (stoi(row[2]) > 0 && stoi(row[2]) < 2025)// If the year value is greater than zero
                        collection->addItem( // Add Item
                            new T(
                                row[0],      // Manufacturer
                                row[1],      // Name
                                stoi(row[2]) // use the year value
                            )
                        );

                    else // else year is less than zero
                        collection->addItem(
                            new T(
                                row[0], // Manufacturer
                                row[1], // Name
                                0       // Put a zero as a year value
                            )
                        );
                }
                // If a console exists already, catch the exception
                catch (InvalidInput& e)
                    { cout << e.what() << endl; }

                // Handling exception thrown by stoi() function
                catch (exception& e)
                    { cout << "YEAR MALFUNCTION" << endl; }
            }
        }

    else
        throw InvalidFile("!!! Invalid File !!!");
    
    file.close(); // Closing the file

    cout << "!!! Collection Loaded !!!" << endl;
}

/**
 * Explicit Template Instantiation for Storage<Console>
 * 
 * This line explicitly instantiates the Storage class template with the Console class as its template argument.
 * It instructs the compiler to generate the code for all member functions of the Storage class template with Console 
 * as the template parameter. This is useful for separating the declaration and definition of templates into different 
 * files, as it ensures that the template code is compiled only once and linked appropriately.
 */

template class Storage<Console>;
