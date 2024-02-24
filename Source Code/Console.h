#pragma once

#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

// CUT DATA STRUCTURE
struct Cpu {
    // OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE 
    string
        manufacturer,
        name,
        frequency;

    int year;
    // OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE 
    Cpu(string manufacturer, string name, string frequency, int year) :
        manufacturer(manufacturer),
        name(name),
        frequency(frequency),
        year(year) {}
    // OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE 
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
    // OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE 
        return out;
    }
};// OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE 


class Console {
// Attributes
    string
        manufacturer, // The company that manufactured the hardware 
        name; // The name of the console
    
    int year; // Year produced

    Cpu* cpu; // Optional CPU specs (does not work with file storage)
public:
// Constructors
    Console();
    Console(string, string, int, Cpu*);
    Console(const Console&);
// Destructor
    virtual ~Console();
// Exception Object
    class InvalidInput : public domain_error
        { public: InvalidInput(const char* what) : domain_error(what) {} };
// Member Functions
    // Mutators
    void setManufacturer(string manufacturer);
    void setName(string name);
    void setCpu(Cpu* cpu);
    void setYear(int year);
    // Accessors
    inline string getManufactuer() const;
    inline string getName() const;
    inline Cpu& getCpu() const;
    inline int getYear() const;
    // Display
    void print() const;

};