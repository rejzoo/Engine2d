#pragma once

#include <stdexcept>
#include <string>

struct UnknownSectionException : public std::runtime_error {
    explicit UnknownSectionException(const std::string& section)
        : std::runtime_error("Unknown section: " + section) 
    {
    
    }
};

struct UnknownActionException : public std::runtime_error {
    explicit UnknownActionException(const std::string& action)
        : std::runtime_error("Unknown action: " + action) 
    {

    }
};
