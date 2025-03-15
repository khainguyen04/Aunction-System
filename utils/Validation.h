#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

class Validation {
public:
    // Returns false if the password is "12345", "password", too short, etc.
    static bool isValidPassword(const std::string& password);
};

#endif
