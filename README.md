# Console Collection Program

This console program is designed to manage a collection of video game consoles. It allows users to add, remove, view, and edit information about various gaming consoles, including their manufacturer, name, and year of release.

Currently, the user can only add and remove entire data sets of Consoles, and not edit the data of singular Consoles within the collection.

## Features

- **View Collection**: View the entire collection of gaming consoles.
- **Edit Collection**: Add new consoles to the collection, remove existing consoles, or edit console information.
- **Search Collection**: Search for a specific console by name or year.
- **Load/Save Collection**: Load the collection from a file or save the collection to a file for future use.

## Usage

To use the console program, follow these steps:

1. Run the program.
2. Choose an operation from the main menu:
   - View Collection
   - Edit Collection
   - Search Collection
   - Load Collection From File
   - Save Collection To File
   - Exit Program
3. Follow the on-screen prompts to perform the chosen operation.

## Installation

To install and run the program:

1. Clone the repository to your local machine.
2. Compile the source code using a C++ compiler.
3. Run the compiled executable file.

## Dependencies

- C++ compiler

## File Structure

- `Menu.h`: Header file for the Menu class, which handles user interaction and menu navigation.
- `Menu.cpp`: Implementation file for the Menu class.
- `Console.h`: Header file for the Console class, which represents a video game console.
- `Console.cpp`: Implementation file for the Console class.
- `Collection.h`: Header file for the Collection class, which manages the collection of consoles.
- `Collection.cpp`: Implementation file for the Collection class.
- `Storage.h`: Header file for the Storage class, which handles file I/O operations.
- `Storage.cpp`: Implementation file for the Storage class.
- `main.cpp`: Main program file containing the `main()` function.

## Contributors

- [Kyle Free](https://github.com/KyleEff)

## License

This project is licensed under the [MIT License](LICENSE).