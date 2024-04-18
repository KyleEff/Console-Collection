#include "Collectable.h"
#include <algorithm>

using namespace std;

Collectable::Collectable(string name, int year) :
    name(name),
    year(year) {

        transform(
            name.begin(),
            name.end(),
            lowerName.begin(),
            ::tolower
        );
    }


