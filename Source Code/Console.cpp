#include "Console.h" // Include the header file for Console class
#include <iostream>

using namespace std;

// Constructor definitions

// Default constructor
Console::Console() :
    manufacturer(""),
    name(""),
    year(0) { }

// Parameterized constructor
Console::Console(
    string manufacturer,
    string name,
    int year = 0 // default value for year
) :
    manufacturer(manufacturer),
    name(name),
    year(year) { }

// Copy constructor
Console::Console(const Console& console) :
    manufacturer(console.manufacturer),
    name(console.name),
    year(console.year) { }

// Setter for manufacturer
void Console::setManufacturer(string manufacturer) {
    // Check if the input manufacturer is not empty
    if (manufacturer != "")
        // If not empty, assign it to the member variable 'manufacturer'
        this->manufacturer = manufacturer;
    // If empty, throw an exception indicating invalid input
    else throw InvalidInput("Invalid Manufacturer");
}

// Setter for name
void Console::setName(string name) {
    // Check if the input name is not empty
    if (name != "")
        // If not empty, assign it to the member variable 'name'
        this->name = name;
    // If empty, throw an exception indicating invalid input
    else throw InvalidInput("Invalid Console Name");
}

// Setter for year
void Console::setYear(int year) {
    // Check if the input year is valid (1972 or later)
    if (year >= 1972)
        // If valid, assign it to the member variable 'year'
        this->year = year;
    // If not valid, throw an exception indicating invalid input
    else throw InvalidInput("Invalid year");
}

// Print console details
void Console::print() const {
    // Output the manufacturer and name
    cout
        << "Manufacturer: "
        << manufacturer
        << endl

        << "Name: "
        << name
        << endl;

    // Output the year if it's valid (greater than 0)
    if (year > 0)
        cout
            << "Year: "
            << year
            << '\n'
            << endl;
    // Otherwise, just output a newline for formatting
    else cout << endl;
}

// Overloaded output operator for Console class
ostream& operator<<(ostream& out, const Console& c) {
    // Output the manufacturer and name separated by a comma
    out
        << c.manufacturer
        << ','
        << c.name;

    // Output the year if it's valid (greater than 0)
    if (c.getYear() > 0)
        out
            << ','
            << to_string(c.year);

    return out;
}

// Overloaded less than operator for Console class (used for sorting)
bool operator<(const Console& c1, const Console& c2) {
    // Compare the names of the consoles
    return c1.name < c2.name;
}
