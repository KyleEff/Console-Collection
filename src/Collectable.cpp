#include "Collectable.h"
#include <algorithm>

using namespace std;

Collectable::Collectable(string name, int year) :
    name(name),
    year(year),
    lowerName(name) {

        transform(
            lowerName.begin(),
            lowerName.end(),
            lowerName.begin(),
            ::tolower
        );
    }


