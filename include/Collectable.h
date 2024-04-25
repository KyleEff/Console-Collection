#pragma once
#include <string>

class Collectable {

protected:
    std::string
        name,
        lowerName;
    
    unsigned short year;

public:
    Collectable(std::string, int);

    virtual std::string getName() const = 0;

    virtual std::string getLowerCase() const = 0;

    virtual int getYear() const = 0;

    virtual void print() const = 0;
};