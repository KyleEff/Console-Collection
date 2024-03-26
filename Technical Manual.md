# Console Collection Program Technical Manual

## Table of Contents
1. Introduction
2. System Requirements
3. Installation
4. Usage
5. Program Structure
6. Data Structures and Algorithms
7. Error Handling
8. File Management
9. Extending the Program
10. Contributing
11. License
12. Class / Object Specifications

## 1. Introduction
The Console Collection program is a command-line application designed to manage a collection of video game consoles. It provides functionalities to view, edit, search, save, and load the collection from a file.

## 2. System Requirements
- Operating System: Any platform with a C++11 or later compatible compiler
- Compiler: C++11 compatible compiler (e.g., GCC, Clang, Visual C++)
- Standard Template Library (STL) support

## 3. Installation
1. Clone or download the repository to your local machine.
2. Navigate to the project directory in your terminal.
3. Compile the program using a C++11 compatible compiler. For example:
    ```bash
    g++ -std=c++11 *.cpp -o console_collection
    ```
4. Run the compiled executable:
    ```bash
    ./console_collection
    ```

## 4. Usage
Upon running the program, you will be presented with a main menu where you can choose various operations:
- **View Collection:** View the collection sorted by year or name.
- **Edit Collection:** Add, remove, or edit consoles in the collection.
- **Exit Program:** Terminate the program.

Follow the on-screen prompts to interact with the program and navigate through the menu options.

## 5. Program Structure
The program is structured into multiple classes:
- **Console**: Represents a single video game console with attributes such as manufacturer, name, and year of release.
- **Collection**: Manages the collection of consoles using vectors and hash tables for efficient storage and retrieval.
- **Menu**: Handles the user interface and main menu functionalities.
- **Storage**: Provides file I/O operations for saving and loading the collection from a file.

## 6. Data Structures and Algorithms
The Console Collection program utilizes the following data structures and algorithms:

- **Vectors**: Used to store the collection of consoles. Vectors offer O(1) time complexity for accessing elements by index, but O(n) time complexity for inserting or deleting elements at arbitrary positions.

- **Unordered Map (Hash Table)**: Utilized for fast search operations by console name and year. Hash tables provide average-case O(1) time complexity for insertion, deletion, and lookup operations.

- **Sorting Algorithms**: QuickSort is used for sorting the collection by name or year. QuickSort has an average-case time complexity of O(n log n) and worst-case time complexity of O(n^2). However, since the collection is relatively small, the performance impact is negligible.

## 7. Error Handling
The program implements exception handling to manage errors gracefully. Common exceptions include:
- `Collection::EmptyCollection`: Raised when performing operations on an empty collection.
- `Console::InvalidInput`: Raised when invalid input is provided during console creation or manipulation.
- `Storage::InvalidFile`: Raised when attempting to read from or write to an invalid file.

## 8. File Management
The program allows users to save the collection to a file and load it back for future use. The file format is simple CSV (Comma-Separated Values) where each line represents a console with manufacturer, name, and year separated by commas.

## 9. Extending the Program
You can extend the program by adding new functionalities or improving existing ones. Possible enhancements include:
- Adding support for more attributes of consoles (e.g., region, price).
- Implementing advanced search and sorting algorithms for better user experience.
- Introducing a graphical user interface (GUI) for easier interaction.

## 10. Contributing
Contributions to the project are welcome! Feel free to fork the repository, make your changes, and submit a pull request. Please follow the project's coding standards and guidelines.

## 11. License
This project is dedicated to the public domain under the [Unlicense](https://unlicense.org/). You are free to use, modify, and distribute the software without any restrictions.

## 12. Class and Object Specifications
### Console Class

#### Introduction
The `Console` class represents a video game console, storing information such as the manufacturer, name, and year of production. This guide provides an overview of the class structure, its member functions, and usage.

#### Class Structure
The `Console` class is defined in the header file `Console.h` and consists of the following components:

- **Attributes**:
  - `manufacturer`: Represents the company that manufactured the console.
  - `name`: Represents the name of the console.
  - `year`: Represents the year the console was produced.

- **Constructors**:
  - `Console()`: Default constructor initializing attributes to default values.
  - `Console(string, string, int)`: Parameterized constructor allowing initialization of attributes with provided values.

- **Exception Object**:
  - `InvalidInput`: Custom exception class derived from `domain_error` to handle invalid input during attribute setting.

- **Member Functions**:
  - Setter methods (`setManufacturer`, `setName`, `setYear`) to modify attribute values.
  - Getter methods (`getManufacturer`, `getName`, `getYear`) to access attribute values.
  - `print()`: Outputs console details to the standard output.
  
- **Friend Functions**:
  - `operator<<`: Overloaded output operator to facilitate output of console details.
  - `operator<`: Overloaded less than operator used for sorting and searching operations.
  - `operator==`: Overloaded equality operator to compare consoles.

#### Usage
To use the `Console` class, follow these steps:

1. Include the header file `Console.h` in your source files.
2. Create instances of the `Console` class using either the default constructor or the parameterized constructor.
3. Use setter methods (`setManufacturer`, `setName`, `setYear`) to modify console attributes.
4. Use getter methods (`getManufacturer`, `getName`, `getYear`) to access console attributes.
5. Utilize the `print()` method to display console details.
6. Optionally, use the overloaded operators (`<<`, `<`, `==`) for output, sorting, and comparison operations.

#### Time Complexity Analysis
The time complexity of various operations involving the `Console` class depends on the specific implementation details of the member functions. Here's an analysis of key operations:

- **Setter and Getter Methods**: 
  - Time complexity: O(1)
  - Explanation: These methods directly access or modify the attribute values, requiring constant time regardless of the size of the data.

- **Printing Console Details (`print()`)**:
  - Time complexity: O(1)
  - Explanation: The `print()` method outputs fixed-format console details and does not involve any iterations or data traversal, resulting in constant time complexity.

- **Comparison Operations (`operator<`, `operator==`)**:
  - Time complexity: O(1)
  - Explanation: These comparison operations involve comparing attributes of two console objects, which can be performed in constant time.

- **Exception Handling**:
  - Time complexity: O(1)
  - Explanation: Throwing and catching exceptions involve minimal overhead and do not depend on the size of the data.

Overall, the `Console` class is designed to provide efficient access and manipulation of console data with consistent time complexity across operations.


