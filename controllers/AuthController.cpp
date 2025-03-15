#include "AuthController.h"
#include "../utils/Validation.h"
#include "../utils/FileHandler.h"
#include "../controllers/MemberController.h"
#include <iostream>

AuthController::AuthController() {}

bool AuthController::login(std::vector<Member>& members, const std::string& username, const std::string& password) {
    for (auto &member : members) {
        // Simple comparison
        if (member.getUsername() == username && member.getPassword() == password) {
            std::cout << "Login successful. Welcome " << member.getName() << "!\n";
            return true;
        }
    }
    std::cout << "Login failed. Invalid username or password.\n";
    return false;
}

bool AuthController::registerMember(std::vector<Member>& members, const Member& newMember) {
    // Check if username already exists
    for (auto &member : members) {
        if (member.getUsername() == newMember.getUsername()) {
            std::cout << "Username already taken.\n";
            return false;
        }
    }

    // If unique, push back to the list
    members.push_back(newMember);

    // Persist to file
    MemberController::saveMembersToFile("data/members.csv", members);

    std::cout << "Registration successful!\n";
    return true;
}
