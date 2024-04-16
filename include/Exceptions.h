#pragma once

#include <stdexcept>

// Custom exception classes

/**
 * Custom Exception Class: InvalidInput
 * 
 * Extends the standard exception class domain_error. This exception is thrown to indicate invalid input or parameters.
 * 
 * @param what A C-style string describing the reason for the exception.
 */

class InvalidInput : public std::domain_error
    { public: InvalidInput(const char* what) : std::domain_error(what) {} };

/**
 * Custom Exception Class: ItemNotFound
 * 
 * Extends the standard exception class invalid_argument. This exception is thrown to indicate that an item could not be found.
 * 
 * @param what A C-style string describing the reason for the exception.
 */
class ItemNotFound : public std::invalid_argument
    { public: ItemNotFound(const char* what) : std::invalid_argument(what) {} };

/**
 * Custom Exception Class: EmptyCollection
 * 
 * Extends the standard exception class range_error. This exception is thrown to indicate that a collection is empty and
 * cannot perform the requested operation.
 * 
 * @param what A C-style string describing the reason for the exception.
 */
class EmptyCollection : public std::range_error
    { public: EmptyCollection(const char* what) : std::range_error(what) {} };

/**
 * Custom Exception Class: InvalidFile
 * 
 * Extends the standard exception class invalid_argument. This exception is thrown to indicate that a file is invalid or 
 * cannot be processed.
 * 
 * @param what A C-style string describing the reason for the exception.
 */
class InvalidFile : public std::invalid_argument
    { public: InvalidFile(const char* what) : std::invalid_argument(what) { } };

