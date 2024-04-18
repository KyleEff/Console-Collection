#pragma once

class Collectable {

protected:
    std::string
        name,
        lowerName;
    
    int year;

public:
    Collectable(std::string, int);

    std::string getName() const // Getter for name
        { return name; }

    std::string getLowerCase() const // Returns the name of the console in lowercase (for name table search)
        { return lowerName; }

    int getYear() const // Getter for year
        { return year; }


};