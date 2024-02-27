#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class Console {
    // Attributes
    string
        manufacturer, // The company that manufactured the hardware 
        name; // The name of the console

    int year; // Year produced

public:
    // Constructors
    Console();
    Console(string, string, int);
    Console(const Console&);
    // Destructor
    virtual ~Console();
    // Exception Object
    class InvalidInput : public domain_error
        { public: InvalidInput(const char* what) : domain_error(what) {} };
    // Member Functions
        // Mutators
    void setManufacturer(string);
    void setName(string);
    void setYear(int);
    // Accessors
    inline string getManufacturer() const
        { return manufacturer; }

    inline string getName() const
        { return name; }

    inline int getYear() const
        { return year; }

    // Display
    void print() const;

    friend ostream& operator<<(ostream&, const Console&);

};
