#include "AuthView.h"
#include "MemberView.h"
#include "AdminView.h" // <-- So we can call AdminView if admin logs in
#include <iostream>
#include <limits> // for std::numeric_limits<std::streamsize>::max()
#include "../controllers/AuthController.h"
#include "../utils/Validation.h"

void AuthView::showLoginMenu(std::vector<Member>& members) {
    int subChoice = 0;
    while (subChoice != 3) {
        std::cout << "\n-------------------Login Menu-------------------\n";
        std::cout << "1. Login as Regular User\n";
        std::cout << "2. Login as Admin\n";
        std::cout << "3. Return to Application Menu\n";
        std::cout << "---------------------------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> subChoice;

        switch(subChoice) {
            case 1:
                std::cout << "\n[Regular User Login]\n";
                showRegularLoginScreen(members);
                break;

            case 2:
                std::cout << "\n[Admin Login]\n";
                showAdminLoginScreen(members);
                break;

            case 3:
                std::cout << "Returning to Application Menu...\n";
                break;

            default:
                std::cout << "Invalid choice! Try again.\n";
                break;
        }
    }
}

/**
 * Login flow for REGULAR users:
 *   - If successful -> show MemberView
 */
void AuthView::showRegularLoginScreen(std::vector<Member>& members) {
    std::string username, password;
    std::cout << "\n==== LOGIN (Regular User) ====\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    AuthController authController;
    bool success = authController.login(members, username, password);
    if (success) {
        // Find which Member just logged in
        Member* loggedInMember = nullptr;
        for (auto &m : members) {
            if (m.getUsername() == username && m.getPassword() == password) {
                loggedInMember = &m;
                break;
            }
        }

        if (loggedInMember) {
            // Show the Member Menu for a regular user
            MemberView::showMemberMenu(*loggedInMember, members);
        } else {
            std::cout << "Error: Could not identify the logged-in user.\n";
        }
    } else {
        std::cout << "Wrong username or password. Please try again or register.\n";
    }
}

/**
 * Login flow for ADMIN users:
 *   - If successful -> show AdminView
 */
void AuthView::showAdminLoginScreen(std::vector<Member>& members) {
    std::string username, password;
    std::cout << "\n==== LOGIN (Admin) ====\n";
    std::cout << "Enter admin username: ";
    std::cin >> username;
    std::cout << "Enter admin password: ";
    std::cin >> password;

    AuthController authController;
    bool success = authController.login(members, username, password);
    if (success) {
        // ***In a real system, you'd check if this user is truly an admin.***
        // For now, let's assume any "successful" login here is an admin.
        
        std::vector<Item> emptyItemList; 
        // If you have an ItemController or items loaded from a CSV, pass them here.
        // For demonstration, we'll just pass an empty vector.
        
        AdminView::showAdminMenu(members, emptyItemList);
    } else {
        std::cout << "Invalid admin credentials. Please try again.\n";
    }
}

/**
 * Same as before. No change here (unless you want to).
 */
void AuthView::showRegisterScreen(std::vector<Member>& members) {
    std::string username, password, name, phoneNumber, email, idType, idNumber;

    std::cout << "\n==== REGISTER ====\n";
    std::cout << "Enter username: ";
    std::cin >> username;

    // Validate password in a loop until it’s strong enough
    do {
        std::cout << "Enter password: ";
        std::cin >> password;
        if (!Validation::isValidPassword(password)) {
            std::cout << "Weak password! Please enter new one!\n";
        }
    } while (!Validation::isValidPassword(password));

    // We need to consume any leftover newline before reading full name
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter full name: ";
    std::getline(std::cin, name);

    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;

    std::cout << "Enter email: ";
    std::cin >> email;

    std::cout << "Enter ID Type(citizen ID, passport): ";
    std::cin >> idType;

    std::cout << "Enter ID Number: ";
    std::cin >> idNumber;

    // For simplicity, let’s generate an ID based on (size + 1)
    int newMemberID = members.size() + 1;

    // Create the new Member
    Member newMember(newMemberID,
                     username,
                     password,
                     name,
                     phoneNumber,
                     email,
                     idType,
                     idNumber);

    // Attempt registration
    AuthController authController;
    authController.registerMember(members, newMember);
}
