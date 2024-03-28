# Console Collection Program

This console program is designed to manage a collection of video game consoles. It allows users to add, remove, view, and edit information about various gaming consoles, including their manufacturer, name, and year of release.

Currently, the user can only add and remove entire data sets of Consoles, meaning the data of singular Consoles within the collection cannot be edited. The entire Console must be deleted and re-entered.

## Features

- **View Collection**: Users can view the entire collection of gaming consoles. They have the option to sort the consoles by release year or name in both ascending and descending orders.
- **Edit Collection**: The program allows users to edit the collection by adding new consoles, removing existing ones, or performing other operations such as loading or saving the collection to/from a file.
- **Search Collection**: Users can search for specific consoles within the collection based on their names or release years. This feature helps users quickly locate consoles of interest.
- **Load/Save Collection**: Load the collection from a file or save the collection to a file for future use.

## Usage

Upon running the program, you will be presented with a main menu.
Choose an operation to perform:
- **View Collection**
- **Edit Collection**
- **Exit Program**

Follow the on-screen prompts to interact with the program.

No operations can or will be performed if the collection is empty. Either load a collection from file, or enter a Console manually using the interface.

## Installation
There are two options to choose from:

The first option is to compile and run the program locally:
1. Clone the repository to your local machine.
2. Compile the source code using a C++ compiler.
3. Run the compiled executable file.

The second option is to download the .exe file in the release.

## Dependencies

- C++ compiler
or 
- Windows Machine

## File Structure

| File             | Description                                                                                   |
|------------------|-----------------------------------------------------------------------------------------------|
| `Menu.h`         | Header file for the Menu class, which handles user interaction and menu navigation.           |
| `Menu.cpp`       | Implementation file for the Menu class.                                                       |
| `Console.h`      | Header file for the Console class, which represents a video game console.                     |
| `Console.cpp`    | Implementation file for the Console class.                                                    |
| `Collection.h`   | Header file for the Collection class, which manages the collection of consoles.               |
| `Collection.cpp` | Implementation file for the Collection class.                                                  |
| `Storage.h`      | Header file for the Storage class, which handles file I/O operations.                          |
| `Storage.cpp`    | Implementation file for the Storage class.                                                     |
| `main.cpp`       | Main program file containing the `main()` function.                                            |


## Contributors

- [Kyle Free](https://github.com/KyleEff)

## License

This project is dedicated to the public domain under the [Unlicense](https://unlicense.org/). You are free to use, modify, and distribute the software without any restrictions.