#pragma once

#include "Exceptions.h"
#include <string>

// Class representing a console
class Console {
    // Attributes
    string
        manufacturer, // The company that manufactured the hardware 
        name, // The name of the console
        lowerName;

    int year; // Year produced

public:
    // Constructors
    Console(); // Default constructor
    Console(string, string, int); // Parameterized constructor

    // Member Functions
    void setManufacturer(string); // Setter for manufacturer
    void setName(string); // Setter for name
    void setYear(int); // Setter for year
    void print() const; // Print console details

    // Accessors
    string getManufacturer() const // Getter for manufacturer
        { return manufacturer; }

    string getName() const // Getter for name
        { return name; }

    string getLowerCase() const
        { return lowerName; }

    int getYear() const // Getter for year
        { return year; }

    friend ostream& operator<<(ostream&, const Console&); // Overloaded output operator for storage
    friend bool operator<(const Console&, const Console&); // Overloaded less than operator
    friend bool operator==(const Console&, const Console&); // Needed for custom binary search
};
