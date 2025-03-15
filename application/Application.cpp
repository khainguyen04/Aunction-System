#include "Application.h"
#include <iostream>
#include "../controllers/MemberController.h"
#include "../views/AuthView.h"
#include "../views/GuestView.h"

int Application::run() {
    using namespace std;

    // Display the assignment header
    cout << "\033[38;5;214m----------------------------------------------------------------------------------------\033[0m\n"; // Orange color
    cout << "                          \033[1m EEET2482/COSC2082 GROUP ASSIGNMENT\033[0m                  \n\n";
    cout << "Instructor: \033[1;32mDr. Huo Chong Ling\033[0m                  \n";
    cout << "Group: \033[1;38;5;131mGroup 14 - HD Destroyers\033[0m             \n"; // Bold text, Orange color
    cout << " Nguyen Minh Khai (s3995223)                      \n";
    cout << " Nguyen Vu Trong Nhan (s3975010)                      \n";
    cout << " Duong Hoang Anh Khoa (s3864111)                     \n";
    cout << " Nhat Pham (s3915104)                    \n";
    cout << " Ho Gia Bao (s3958122)               \n";

    // ANSI escape codes for colors
    string green = "\033[32m"; // Green for the $
    string yellow = "\033[33m"; // Yellow for "Auction"
    string blue = "\033[34m";   // Blue for the decorative line
    string reset = "\033[0m";   // Reset to default color

    // Decorative line
    cout << blue << "========================================================================================" << reset << endl;
    // Display the text with colors
    cout << green << ""
         << yellow << "                                     Auction \n" 
         << yellow << "                                       App"
         << reset << endl;

    // Decorative line
    cout << blue << "========================================================================================" << reset << endl;

    // 1. Load existing members from CSV
    std::vector<Member> members = MemberController::loadMembersFromFile("data/members.csv");

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n==========Application Menu==========\n";
        std::cout << "1. Login\n";
        std::cout << "2. Register\n";
        std::cout << "3. Use the app as Guest\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                AuthView::showLoginMenu(members);
                break;
            case 2:
                AuthView::showRegisterScreen(members);
                break;
            case 3:
                // Now call the guest menu
                GuestView::showGuestMenu();
                break;
            case 0:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
                break;
        }
    }

    // 2. Save members back to the CSV before exiting
    MemberController::saveMembersToFile("data/members.csv", members);

    // Return an exit code
    return 0;
}
