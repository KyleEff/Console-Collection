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
### 12.A Console Class

#### Introduction
The `Console` class represents a video game console, storing information such as the manufacturer, name, and year of production. This guide provides an overview of the class structure, its member functions, and usage.

#### Class Structure
The `Console` class is defined in the header file `Console.h` and consists of the following components:

- **Attributes**:
  - `manufacturer`: Represents the company that manufactured the console.
  - `name`: Represents the name of the console.
  - `lowerName`: Represents the name of the console for name searching.
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

### 12.B Collection Class

#### Introduction
The `Collection` class represents a collection of video game consoles, providing functionalities for managing, searching, and printing console data. This guide provides an overview of the class structure, its member functions, and usage, along with a detailed analysis of time complexities for key operations.

#### Class Structure
The `Collection` class is defined in the header file `Collection.h` and consists of the following components:

- **Attributes**:
  - `layerOne`: Vector to store `Console` objects.
  - `nameTable`: Hash table for fast search by console name.
  - `yearTable`: Hash table for fast search by release year, with vectors of consoles for each year.

- **Custom Exception Classes**:
  - `ItemNotFound`: Derived from `invalid_argument`, thrown when an item is not found in the collection.
  - `EmptyCollection`: Derived from `range_error`, thrown when attempting operations on an empty collection.

- **Sorting Function Objects**:
  - Custom comparison functions for sorting consoles by year and name.

- **Member Functions**:

| Function           | Description                                         | Time Complexity |
|--------------------|-----------------------------------------------------|-----------------|
| `sortByName`       | Sorts the collection by console name.               | O(n log n)      |
| `sortByYear`       | Sorts the collection by release year.               | O(n log n)      |
| `searchByName`     | Searches for a console by name.                     | O(1) to O(n)    |
| `searchByYear`     | Searches for consoles released in a given year.     | O(1) to O(n)    |
| `yearTableBinarySearch` | Performs binary search within year table.      | O(log n)        |
| `addItem`          | Adds a console to the collection.                   | O(1) to O(n)    |
| `removeItem`       | Removes a console from the collection.              | O(1) to O(n)    |
| `print`            | Prints all consoles in the collection.              | O(n)            |
| `size`             | Returns the size of the collection.                 | O(1)            |

- **Debug Functions** (Not used in normal operations):
  - `yearTableTest`: Debug function to test year table operations.
  - `yearTablePrint`: Debug function to print the contents of the year table.

#### Usage
To use the `Collection` class, follow these steps:

1. Include the header file `Collection.h` in your source files.
2. Create an instance of the `Collection` class.
3. Use the provided methods to add, remove, search, and print consoles in the collection.
4. Optionally, utilize the debug functions for testing and debugging purposes.

#### Time Complexity Analysis
The time complexity of various operations involving the `Collection` class depends on the specific implementation details of the member functions. Here's a detailed analysis of time complexities for key operations:

- **Sorting Methods** (`sortByName`, `sortByYear`): These methods use sorting algorithms with a time complexity of O(n log n), where n is the number of consoles in the collection.

- **Search Methods** (`searchByName`, `searchByYear`, `yearTableBinarySearch`): Searching operations have time complexities ranging from O(1) to O(n), depending on the size of the collection and the search criteria. Binary search in `yearTableBinarySearch` has a time complexity of O(log n) after sorting.

- **Add and Remove Methods** (`addItem`, `removeItem`): Adding or removing a console involves insertion or deletion in the vectors and hash tables, generally with time complexities of O(1) for average cases but may degrade to O(n) in worst-case scenarios.

- **Printing Method** (`print`): Printing all consoles in the collection requires iterating through the entire collection, resulting in a time complexity of O(n), where n is the number of consoles.

Overall, the `Collection` class provides efficient operations for managing collections of consoles, with time complexity varying based on the specific operation and data size.

### 12.C Storage Class

#### Overview
The `Storage` class in the Console Collection program is responsible for managing the storage and retrieval of collection data to and from a file. It provides methods to store the collection data to a file and read the collection data from a file. This class plays a crucial role in persisting the collection data between program executions.

#### Constructors
- **Storage()**: Default constructor initializes the `collection` pointer to `nullptr`.
- **Storage(Collection&)**: Constructor that takes a reference to a `Collection` object and initializes the `collection` pointer to point to it.

#### Destructor
- **~Storage()**: Virtual destructor deallocates memory for the `Collection` object and resets the `collection` pointer to `nullptr`.

#### Methods
- **setCollection(Collection*)**: Sets the `collection` pointer to point to the provided `Collection` object.
- **storeCollection()**: Writes the collection data to a file named "collection.csv". It iterates over each item in the collection and writes its details to the file. Throws an `InvalidFile` exception if the file cannot be opened for writing.
- **readCollection()**: Reads the collection data from the "collection.csv" file. It parses each line of the file as a CSV record, creates `Console` objects from the parsed data, and adds them to the collection. Throws an `InvalidFile` exception if the file cannot be opened for reading.

#### Exception Handling
- **InvalidFile**: Custom exception class derived from `invalid_argument`. It is thrown when the file operation (reading or writing) fails due to an invalid file.

#### File Operations
- The class uses the `fstream` class to perform file I/O operations.
- The default file name for storing collection data is "collection.csv".

#### Dependencies
- **Collection**: The `Storage` class depends on the `Collection` class to store and retrieve collection data.

#### Example Usage
```cpp
// Creating a Storage object with a Collection object
Collection myCollection;
Storage storage(myCollection);

// Storing collection data to file
storage.storeCollection();

// Reading collection data from file
storage.readCollection();
```

#### Time Complexity Analysis
- The time complexity of the `storeCollection()` method is O(n), where n is the number of items in the collection.
- The time complexity of the `readCollection()` method depends on the size of the collection and the number of records in the file. In the worst-case scenario, where the file contains m records and each record results in the creation of a new `Console` object, the time complexity is O(m).

#### File Format
- The collection data is stored in a CSV (Comma-Separated Values) format.
- Each line in the file represents a console, with attributes separated by commas.
- The format is as follows: `manufacturer, name, year`.

### 12.D Menu Class

#### Overview
The `Menu` class is the central component of the Console Collection Manager program. It provides a user-friendly interface for managing the collection of video game consoles. The class includes methods for displaying menus, adding and removing consoles from the collection, searching the collection, and interacting with storage for persistent data.

#### Attributes
- **collection**: An object of the `Collection` class used to manage the collection of consoles.
- **disk**: An object of the `Storage` class used for storing and retrieving collection data from disk.
- **choice**: An integer variable representing the user's menu choice.

#### Constructor
- **Menu()**: Default constructor initializes the `choice` variable to 0, sets the collection for storage, and displays a greeting message. It then enters a loop to display the main menu until the user chooses to exit the program.

#### Methods
- **greeting()**: Displays a greeting message to the user upon program initialization.
- **mainMenu()**: Displays the main menu options and handles user input to navigate through different functionalities of the program.
- **viewCollection()**: Displays the collection to the user based on different sorting options (by year or by name) and provides an option to search the collection.
- **editCollection()**: Allows the user to edit the collection by adding or removing consoles, loading the collection from a file, or saving the collection to a file.
- **addToCollection()**: Prompts the user to enter details of a new console and adds it to the collection.
- **removeFromCollection()**: Allows the user to remove a console from the collection.
- **searchCollection()**: Provides options to search the collection by name or year and displays the details of the consoles matching the search criteria.

#### Constructor Details
- The constructor initializes the `choice` variable to 0 and sets the collection for storage by calling the `setCollection()` method of the `Storage` object.
- After initialization, the constructor displays a greeting message using the `greeting()` method and enters a loop to display the main menu until the user chooses to exit the program.

#### Method Details
- **viewCollection()**: The method first checks if the collection is empty using the `size()` method of the `Collection` class and displays the menu options for viewing the collection. It then handles user input to sort and display the collection based on different criteria.
- **editCollection()**: This method provides options for adding or removing consoles, loading the collection from a file, or saving the collection to a file. It utilizes exception handling to catch any errors that may occur during file operations.
- **addToCollection()**: Prompts the user to enter details of a new console and adds it to the collection using the `addItem()` method of the `Collection` class.
- **removeFromCollection()**: Allows the user to select a console to remove from the collection and removes it using the `removeItem()` method of the `Collection` class.
- **searchCollection()**: Provides options for searching the collection by name or year and displays the details of the consoles matching the search criteria. It handles exceptions for item not found and other errors that may occur during the search process.

#### Dependencies
- The `Menu` class depends on the `Collection` and `Storage` classes for managing the collection of consoles and storing/retrieving collection data from disk, respectively.

#### Example Usage
```cpp
// Creating a Menu object
Menu menu;
```
This single line of code runs the whole program due to the loop in the constructor.

#### Time Complexity Analysis
- The time complexity of each method depends on the operations performed within them and the size of the collection. Methods involving sorting or searching the collection may have time complexities of O(n log n) or O(n) depending on the algorithm used. Methods involving file I/O operations may have time complexities proportional to the size of the file or collection data.