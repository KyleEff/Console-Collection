#pragma once

#include <stdexcept>

using namespace std;

// Custom exception classes
// Exception Object
class InvalidInput : public domain_error
    { public: InvalidInput(const char* what) : domain_error(what) {} };

class ItemNotFound : public invalid_argument
    { public: ItemNotFound(const char* what) : invalid_argument(what) {} };

class EmptyCollection : public range_error
    { public: EmptyCollection(const char* what) : range_error(what) {} };

// Custom exception class for invalid file
class InvalidFile : public invalid_argument
    { public: InvalidFile(const char* what) : invalid_argument(what) { } };

