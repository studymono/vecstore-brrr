#include "logger.h"

// Overload the << operator for integer types
Logger &Logger::operator<<(int value)
{
    std::cout << value;
    return *this; // Return the stream to allow chaining
}

// Overload the << operator for strings
Logger &Logger::operator<<(const std::string &value)
{
    std::cout << value;
    return *this;
}

// Overload the << operator for const char* (C-strings)
Logger &Logger::operator<<(const char *value)
{
    std::cout << value;
    return *this;
}

// Overload the << operator for manipulators like std::endl
Logger &Logger::operator<<(std::ostream &(*manip)(std::ostream &))
{
    manip(std::cout); // Call the manipulator on std::cout
    return *this;
}

// Create a global instance similar to std::cout
Logger logger;
