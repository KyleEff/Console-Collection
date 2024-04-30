#include "Collectable.h"
#include <algorithm>

using namespace std;

/**
 * @brief Constructor for the Collectable class.
 * 
 * This constructor initializes a Collectable object with the specified name and release year. It also
 * initializes the lowerName attribute, which stores the name of the collectible item in lowercase for
 * search purposes. The constructor transforms the name to lowercase using the transform function from
 * the <algorithm> header. The transformed name is then stored in the lowerName attribute.
 * 
 * @param name The name of the collectible item.
 * @param year The release year of the collectible item.
 */

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


