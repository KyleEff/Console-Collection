#pragma once
#include <string>

/**
 * @class Collectable
 * @brief Represents a collectible item with a name and release year.
 * 
 * The Collectable class serves as a base class for representing collectible items. It contains attributes
 * for the name and release year of the collectible item. The class provides methods to retrieve the name,
 * get the name in lowercase for search purposes, and retrieve the release year of the item. Additionally,
 * it defines pure virtual methods for setting the name and release year, as well as a virtual method for
 * printing information about the collectible item.
 */

class Collectable {

protected:
    std::string
        name,
        lowerName;
    
    unsigned short year;

public:
    Collectable(std::string, int);

    std::string getName() const // Getter for name
        { return name; }

    std::string getLowerCase() const // Returns the name of the console in lowercase (for name table search)
        { return lowerName; }

    int getYear() const // Getter for year
        { return year; }

    virtual void setYear(int) = 0;
    virtual void setName(std::string) = 0;

    virtual void print() const = 0;
};