#include "Console.h"
#include <iostream>

using namespace std;

//Constructor
Console::Console() :
    manufacturer(""),
    name(""),
    year(0) { }

Console::Console(
    string manufacturer,
    string name,
    int year = 0
) :
    manufacturer(manufacturer),
    name(name),
    year(year) { }

Console::Console(const Console& console) :
    manufacturer(console.manufacturer),
    name(console.name),
    year(console.year) { }

Console::~Console() {

}

void Console::setManufacturer(string manufacturer) {
    // Check if the input manufacturer is not empty
    if (manufacturer != "")
        // If not empty, assign it to the member variable 'manufacturer'
        this->manufacturer = manufacturer;
    // If empty, throw an exception indicating invalid input
    else throw InvalidInput("Invalid Manufacturer");
}

void Console::setName(string name) {

    if (name != "")
        this->name = name;
    else throw InvalidInput("Invalid Console Name");
}


void Console::setYear(int year) {

    if (year >= 1972)
        this->year = year;
    else throw InvalidInput("Invalid year");
}

void Console::print() const {

    cout
        << "Manufacturer: "
        << manufacturer
        << endl

        << "Name: "
        << name
        << endl;

    if (year > 0)
        cout
            << "Year: "
            << year
            << '\n'
            << endl;
    else cout << endl;
}

ostream& operator<<(ostream& out, const Console& c) {

    out
        << c.manufacturer
        << ','
        << c.name;

    if (c.getYear() > 0)
        out
            << ','
            << to_string(c.year);

    return out;
}

bool operator<(const Console& c1, const Console& c2) {

    return c1.name < c2.name;
}
