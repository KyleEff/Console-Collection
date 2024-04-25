# Video Game Console Collection Manager

## INTRODUCTION
The purpose of this program is to store, view, and edit a collection of objects, specifically video game consoles, using various data structures and algorithms within a command-line interface. The entire program will be written in C++.

The Menu class will contain a Storage and a Collection object that will be used throughout the program. The Collection class will contain a set of Console objects stored in the necessary data structures, along with the appropriate search and sort algorithms.

There are no instances of inheritance or polymorphism as the program does not require it. If a separate class were needed for a specific purpose, it would be created.

## DATA STRUCTURES
The program design will be strictly object-oriented, starting with a Console object that holds the following attributes:
- Manufacturer (string)
- Name (string)
- Year (integer)

Console objects will be stored in a vector inside a Collection object. This Collection class will manage the "first layer" of input in a vector of Consoles, along with hash tables for searching. The vector is chosen for its ability to automatically resize with new input, while the hash tables will serve their purpose of constant-time searching.

## SEARCH ALGORITHMS
The first search will be performed on the Layer One vector using a binary search sorted by name. If the item is found in the vector, it will not be added to the collection. Otherwise, it will be added to the vector and the hash table. This search has a runtime of O(logn). Overloading the comparison operator "<" will be necessary.

The second search will be conducted on the hash tables by name and year. The year hash table may encounter collisions, so a custom hash table using vectors may be implemented. The name search will have a constant-time complexity of O(1), while the year search will have a worst-case complexity of O(nlogn) and an average-case complexity of O(1).

During the development of the hash table for the search by year, it was observed that collisions are not handled well by the default library unordered_map. Hence, a custom data structure utilizing a vector of pointers to chain the consoles released in the same year may be designed. Consequently, the feature of searching by year may not be included in the final version of the software.

The name search currently functions correctly, although further investigation is needed to make the input search from the user case-insensitive. For now, name searches must match the input exactly as entered into the collection.

## SORTING ALGORITHM
The vectors will be sorted using the built-in sort() function from the <algorithm> library. This function employs an algorithm called "Introsort," which begins with quicksort, switches to heapsort when the recursion exceeds a certain threshold, and switches to insertion sort when the number of elements is below a threshold. This approach avoids the worst-case time complexity of O(n^2) in quicksort and maintains a complexity of O(nlogn).

The function has an overloaded implementation that accepts a third argument, which is a function object used by the algorithm to compare values in the data set. A function object is an object (or struct) that only returns the overloaded function() operator and the resulting operation.

Refer to the [documentation](https://en.cppreference.com/w/cpp/algorithm/sort) for more information.

## USER INTERFACE DESIGN
The UI will be contained in a class named "Menu." This class will include a Collection object that contains the collection of Console objects and all associated member functions. Acting as the intermediary between the user and the data, the Menu class will display text-based menus and execute operations based on the user's choice.

Additionally, the Menu class will manage an object interacting with a hard storage file, as described in the next section.

## PERSISTENT STORAGE
Data about the collection will be stored in a comma-separated value (.csv) file for ease of reading and storage. Using comma delimiters, the data can be read and stored using overloaded "<<" operators.

Storage will be handled entirely by a Storage class. This class will have a Collection pointer as an attribute, which will be set upon construction using a reference to the program's Collection object. Once the Collection reference is passed to the Storage object, data can move freely to and from the file.

## EXCEPTION HANDLING
Exceptions will be thrown in cases of invalid user input, invalid storage file opening, or attempts to access the collection when it is empty.
