#include "Storage.h" // Including the header file for the Storage class
#include <vector> // Standard vector container
#include <sstream> // String stream operations
#include <iostream>

// Default constructor
Storage::Storage() :
    collection(nullptr) { }

// Constructor with reference to Collection object
Storage::Storage(Collection& collection) :
    collection(&collection) { }

// Destructor
Storage::~Storage() {

    delete collection; // Deallocating memory for the collection
    collection = nullptr; // Resetting pointer to nullptr
}

// Method to store the collection data to a file
void Storage::storeCollection() {

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
        catch (Collection::EmptyCollection& e) { // Handling empty collection exception
        
            cout << e.what() << endl;
            file.close();
        }
    }
    else
        throw InvalidFile("!!! Invalid File !!!");
        
    // Closing the file
    file.close(); 
}

// Method to read the collection data from a file
void Storage::readCollection() {

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
                    if (stoi(row[2]) > 0) // If the year value is greater than zero
                        collection->addItem( // Add Item
                            new Console(
                                row[0],      // Manufacturer
                                row[1],      // Name
                                stoi(row[2]) // use the year value
                            )
                        );

                    else // else year is less than zero
                        collection->addItem(
                            new Console(
                                row[0], // Manufacturer
                                row[1], // Name
                                0       // Put a zero as a year value
                            )
                        );
                }
                // If a console exists already, catch the exception
                catch (Console::InvalidInput& e)
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
