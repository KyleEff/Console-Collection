#pragma once

#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

struct Cpu {

    string
        manufacturer,
        name,
        frequency;

    int year;

    Cpu(string manufacturer, string name, string frequency, int year) :
        manufacturer(manufacturer),
        name(name),
        frequency(frequency),
        year(year) {}

    friend ostream& operator<<(ostream& out, const Cpu& c) {

        out
            << c.manufacturer
            << ' '
            << c.name
            << " @ "
            << c.frequency
            << ", "
            << c.year
            << endl;

        return out;
    }
};


class Console {
// Attributes
    string
        manufacturer, // The company that manufactured the hardware 
        name; // The name of the console
    
    Cpu* cpu; // The CPU specs

    int year; // Year produced

public:
// Constructors
    Console();
    Console(string, string, Cpu*, int);
    Console(const Console& console);

    virtual ~Console();

    class InvalidInput : public domain_error
        { public: InvalidInput(const char* what) : domain_error(what) {} };

    void setManufacturer(string manufacturer) throw(InvalidInput);
    void setName(string name) throw(InvalidInput);
    void setCpu(Cpu* cpu);
    void setYear(int year) throw(InvalidInput);

    inline string getManufactuer() const;
    inline string getName() const;
    inline Cpu& getCpu() const;
    inline int getYear() const;

    void print() const;

};