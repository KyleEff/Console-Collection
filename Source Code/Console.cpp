#include "Console.h"
#include <iostream>

using namespace std;

//Constructor
Console::Console() :
    manufacturer(""),
    name(""),
    cpu(nullptr),
    year(0) {}

Console::Console(
        string manufacturer,
        string name,
        Cpu* cpu,
        int year
    ) :
    manufacturer(manufacturer),
    name(name),
    cpu(cpu),
    year(year) {}

Console::Console(const Console& console) :
    manufacturer(console.manufacturer),
    name(console.name),
    cpu(console.cpu),
    year(console.year) {}

Console::~Console() {

    delete cpu;
    cpu = nullptr;
}

void Console::setManufacturer(string manufacturer) {

    if (manufacturer != "")
        this->manufacturer = manufacturer;
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
        << endl

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

