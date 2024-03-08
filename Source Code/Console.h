#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

// Class representing a console
class Console {
    // Attributes
    string
        manufacturer, // The company that manufactured the hardware 
        name; // The name of the console

    int year; // Year produced

public:
    // Constructors
    Console(); // Default constructor
    Console(string, string, int); // Parameterized constructor
    Console(const Console&); // Copy constructor

    // Destructor
    virtual ~Console();

    // Exception Object
    class InvalidInput : public domain_error
        { public: InvalidInput(const char* what) : domain_error(what) {} };

    // Member Functions
    void setManufacturer(string); // Setter for manufacturer
    void setName(string); // Setter for name
    void setYear(int); // Setter for year
    
    // Accessors
    inline string getManufacturer() const // Getter for manufacturer
        { return manufacturer; }

    inline string getName() const // Getter for name
        { return name; }

    inline int getYear() const // Getter for year
        { return year; }

    // Display
    void print() const; // Print console details

    friend ostream& operator<<(ostream&, const Console&); // Overloaded output operator
    friend bool operator<(const Console&, const Console&); // Overloaded less than operator
};
