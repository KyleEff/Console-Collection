#include "../include/Console.h" // Include the header file for Console class
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Constructor definitions
/**
 * Default Constructor for Console
 * 
 * Initializes a Console object with default values.
 * 
 * Attributes Initialized:
 * - manufacturer: Empty string.
 * - name: Empty string.
 * - year: 0.
 */
Console::Console() : Collectable("", 0) {  }

/**
 * Parameterized Constructor for Console
 * 
 * Initializes a Console object with specified values for its attributes.
 * 
 * Parameters:
 * - manufacturer: The company that manufactured the hardware.
 * - name: The name of the console.
 * - year: The year the console was released. Defaults to 0 if not provided.
 * 
 * @param manufacturer The company that manufactured the hardware.
 * @param name The name of the console.
 * @param year The year the console was released. Defaults to 0 if not provided.
 */
Console::Console(
    string manufacturer,
    string name,
    int year = 0 /* default value for year */
    ) :
        Collectable(name, year),
        manufacturer(manufacturer) { }

/**
 * Setter for Manufacturer
 * 
 * Sets the manufacturer of the console to the specified value.
 * 
 * @param manufacturer The company name to set as the manufacturer.
 * @throws InvalidInput If the input manufacturer is empty.
 */
void Console::setManufacturer(string manufacturer) {
    // Check if the input manufacturer is not empty
    if (manufacturer != "") // If not empty, assign it to the member variable 'manufacturer'
        this->manufacturer = manufacturer; 
    else throw InvalidInput("Invalid Manufacturer"); // If empty, throw an exception indicating invalid input
}

/**
 * Setter for Name
 * 
 * Sets the name of the console to the specified value.
 * 
 * @param name The name to set for the console.
 * @throws InvalidInput If the input name is empty.
 */
void Console::setName(string name) {
    // Check if the input name is not empty
    if (name != "") // If not empty, assign it to the member variable 'name'
        this->name = name;
    // If empty, throw an exception indicating invalid input
    else throw InvalidInput("Invalid Console Name");
}

/**
 * Setter for Year
 * 
 * Sets the release year of the console to the specified value.
 * 
 * @param year The year to set for the console.
 * @throws InvalidInput If the input year is earlier than 1972.
 */
void Console::setYear(int year) {
    // Check if the input year is valid (1972 or later)
    if (year >= 1972 && year <= 2025)
        // If valid, assign it to the member variable 'year'
        this->year = year;
    // If not valid, throw an exception indicating invalid input
    else throw InvalidInput("Invalid Year");
}

/**
 * Print Console Details
 * 
 * Prints the details of the console, including its manufacturer, name, and release year.
 * 
 * The console details are formatted as follows:
 * - Manufacturer: Left-aligned within a 48-character width.
 * - Name: Left-aligned within a 48-character width.
 * - Year: If the year is valid (greater than 0), it is printed; otherwise, a newline is printed for formatting.
 * 
 * Output Format:
 *  Manufacturer                                    | Name                                            | Year
 * -------------------------------------------------+-------------------------------------------------+-------
 * 
 * Note: The output format aligns the manufacturer and name within a 48-character width and separates each 
 * column with a vertical bar. The horizontal divider indicates the end of each console's details.
 */
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
}

/**
 * Overloaded Output Operator for Console Class
 * 
 * Overloads the output operator (<<) to allow streaming the details of a console to an output stream.
 * 
 * @param out The output stream to stream the console details to.
 * @param c The console object whose details are to be streamed.
 * @return The output stream after streaming the console details.
 */
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

/**
 * Overloaded Less Than Operator for Console Class (Used for Binary Search)
 * 
 * Overloads the less than operator (<) to compare two console objects based on their names.
 * 
 * @param c1 The first console object to compare.
 * @param c2 The second console object to compare.
 * @return True if the name of the first console is less than the name of the second console; otherwise, false.
 */
bool operator<(const Console& c1, const Console& c2) {
    // Compare the names of the consoles
    return c1.name < c2.name;
}

/**
 * Overloaded Equality Operator for Console Class
 * 
 * Overloads the equality operator (==) to compare two console objects based on their names.
 * 
 * @param c1 The first console object to compare.
 * @param c2 The second console object to compare.
 * @return True if the name of the first console is equal to the name of the second console; otherwise, false.
 */
bool operator==(const Console& c1, const Console& c2) {
    // Compare the names of the consoles
    return c1.name == c2.name;
}
