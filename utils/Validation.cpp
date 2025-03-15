#include "Validation.h"
#include <cctype>   // for isupper, isalpha, isdigit

bool Validation::isValidPassword(const std::string& password) {
    // 1) Reject obviously weak passwords:
    if (password == "12345" || password == "password") {
        return false;
    }

    // 2) Check if the string is empty or the first character is not uppercase
    if (password.empty() || !std::isupper(password[0])) {
        return false;
    }

    // 3) Ensure the password contains at least one letter and at least one digit
    bool hasLetter = false;
    bool hasDigit  = false;
    
    for (char c : password) {
        if (std::isalpha(c)) {
            hasLetter = true;
        }
        if (std::isdigit(c)) {
            hasDigit = true;
        }
    }

    // If you need both letters and digits, check that here
    if (!hasLetter || !hasDigit) {
        return false;
    }

    // 4) Optionally, enforce minimum length
    if (password.size() < 8) {
        return false;
    }

    // If all checks pass, return true
    return true;
}
