#pragma once

#include "Exceptions.h"
#include <string>

/**
 * Console Class
 * 
 * The Console class represents a gaming console, encapsulating attributes such as manufacturer, name, and release year.
 * 
 * Attributes:
 * - manufacturer: The company that manufactured the hardware.
 * - name: The name of the console.
 * - lowerName: A lowercase version of the console name (for name table search).
 * - year: The year the console was released.
 * 
 * Constructors:
 * - Console(): Default constructor.
 * - Console(string, string, int): Parameterized constructor to initialize attributes.
 * 
 * Member Functions:
 * - setManufacturer(string): Setter for the manufacturer attribute.
 * - setName(string): Setter for the name attribute.
 * - setYear(int): Setter for the year attribute.
 * - print() const: Method to print console details.
 * 
 * Accessors:
 * - getManufacturer() const: Getter for the manufacturer attribute.
 * - getName() const: Getter for the name attribute.
 * - getLowerCase() const: Returns the name of the console in lowercase (for name table search).
 * - getYear() const: Getter for the year attribute.
 * 
 * Friend Functions:
 * - operator<< (ostream&, const Console&): Overloaded output operator for storage.
 * - operator< (const Console&, const Console&): Overloaded less than operator.
 * - operator== (const Console&, const Console&): Overloaded equality operator, needed for custom binary search.
 */

class Console {
    // Attributes
    std::string
        manufacturer, // The company that manufactured the hardware 
        name, // The name of the console
        lowerName; // Lowercase name for search optimization

    int year; // Year released

public:
    // Constructors
    Console(); // Default constructor
    Console(std::string, std::string, int); // Parameterized constructor

    // Member Functions
    void setManufacturer(std::string); // Setter for manufacturer
    void setName(std::string); // Setter for name
    void setYear(int); // Setter for year
    void print() const; // Print console details

    // Accessors
    std::string getManufacturer() const // Getter for manufacturer
        { return manufacturer; }

    std::string getName() const // Getter for name
        { return name; }

    std::string getLowerCase() const // Returns the name of the console in lowercase (for name table search)
        { return lowerName; }

    int getYear() const // Getter for year
        { return year; }

    friend std::ostream& operator<<(std::ostream&, const Console&); // Overloaded output operator for storage
    friend bool operator<(const Console&, const Console&); // Overloaded less than operator
    friend bool operator==(const Console&, const Console&); // Needed for custom binary search
};
