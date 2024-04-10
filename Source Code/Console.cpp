#include "Console.h" // Include the header file for Console class
#include <iostream>
#include <iomanip>

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

// Setter for manufacturer
void Console::setManufacturer(string manufacturer) {
    // Check if the input manufacturer is not empty
    if (manufacturer != "") // If not empty, assign it to the member variable 'manufacturer'
        this->manufacturer = manufacturer; 
    else throw InvalidInput("Invalid Manufacturer"); // If empty, throw an exception indicating invalid input
}

// Setter for name
void Console::setName(string name) {
    // Check if the input name is not empty
    if (name != "") // If not empty, assign it to the member variable 'name'
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
    else throw InvalidInput("Invalid Year");
}

// Print console details
void Console::print() const {
    // Output the manufacturer and name
    cout
        << setw(48)
        << left
        << manufacturer
        << "| "

        << setw(48)
        << left
        << name
        << '|';

    // Output the year if it's valid (greater than 0)
    if (year > 0)
        cout 
            << ' '
            << year
            << endl;
    // Otherwise, just output a newline for formatting
    else cout << endl;

    // Divider
    cout
        << "----+"
        << "-------------------------------------------------+"
        << "-------------------------------------------------+"
        << "-------"
        << endl;
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

// Overloaded less than operator for Console class (used for binary search)
bool operator<(const Console& c1, const Console& c2) {
    // Compare the names of the consoles
    return c1.name < c2.name;
}

bool operator==(const Console& c1, const Console& c2) {
    // Compare the names of the consoles
    return c1.name == c2.name;
}
