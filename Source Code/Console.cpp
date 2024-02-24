#include "Console.h"
#include <iostream>

using namespace std;

//Constructor
Console::Console() :
    manufacturer(""),
    name(""),
    cpu(nullptr),
    year(0) { }

Console::Console(
        string manufacturer,
        string name,
        int year = 0,
        Cpu* cpu = nullptr
    ) :
    manufacturer(manufacturer),
    name(name),
    year(year),
    cpu(cpu) { }

Console::Console(const Console& console) :
    manufacturer(console.manufacturer),
    name(console.name),
    cpu(console.cpu),
    year(console.year) { }

Console::~Console() {

    delete cpu;
    cpu = nullptr;
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

void Console::setCpu(Cpu* cpu)
    { this->cpu = cpu; }

void Console::setYear(int year) {

    if (year >= 1972)
        this->year = year;
    else throw InvalidInput("Invalid year");
}

string Console::getManufactuer() const
    { return manufacturer; }

string Console::getName() const
    { return name; }

Cpu& Console::getCpu()  const
    { return *cpu; }

int Console::getYear() const
    { return year; }

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
            << endl;

    if (cpu != nullptr)
        cout
            << "CPU: "
            << *cpu
            << endl;
    else cout << endl;
}

ostream& operator<<(ostream& out, const Console& c) {

    out
        << c.getManufactuer()
        << ','
        << c.getName()
        << ',';

    if (c.getYear() > 0)
        out
            << c.getYear()
            << endl;
    
    return out;
}
