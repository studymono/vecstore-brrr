#ifndef VECTORE_LOGGER_H
#define VECTORE_LOGGER_H

#include <iostream>
#include <string>

class Logger
{
public:
    // Overload the << operator for integer types
    Logger &operator<<(int value);

    // Overload the << operator for strings
    Logger &operator<<(const std::string &value);

    // Overload the << operator for const char* (C-strings)
    Logger &operator<<(const char *value);

    // Overload the << operator for manipulators like std::endl
    Logger &operator<<(std::ostream &(*manip)(std::ostream &));
};

// Create a global instance similar to std::cout
extern Logger logger;

#endif // VECTORE_LOGGER_H
