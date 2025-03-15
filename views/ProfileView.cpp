#include "ProfileView.h"
#include <iostream>
#include <limits> // for std::numeric_limits<std::streamsize>::max()
#include "../controllers/MemberController.h"  


void ProfileView::showProfileMenu(Member &currentMember, std::vector<Member> &allMembers) {
    int choice = 0;
    do {
        // Display current profile info at the top
        displayCurrentProfile(currentMember);

        std::cout << "\nOptions:\n"
                  << "1. Top Up Credit Points (CP)\n"
                  << "2. Update Profile Details\n"
                  << "3. Change Password\n"
                  << "4. Return to Member Menu\n"
                  << "-------------------------------------------------------\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                topUpCreditPoints(currentMember);
                break;
            case 2:
                updateProfileDetails(currentMember);
                MemberController::saveMembersToFile("data/members.csv", allMembers);
                break;
            case 3:
                changePassword(currentMember);
                MemberController::saveMembersToFile("data/members.csv", allMembers);
                break;
            case 4:
                std::cout << "Returning to Member Menu...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }

        // Optionally, if you want changes to be saved immediately:
        // MemberController::saveMembersToFile("data/members.csv", allMembers);

    } while (choice != 4);
}

void ProfileView::topUpCreditPoints(Member &currentMember) {
    std::cout << "\n-------------------Top Up Credit Points-------------------\n";
    std::cout << "Current CP Balance: " << currentMember.getCreditPoints() << "\n";

    int amount;
    std::cout << "\nEnter the dollar amount to top up (or 0 to return): ";
    std::cin >> amount;

    if (amount == 0) {
        std::cout << "No top-up performed. Returning...\n";
        return;
    }

    // Request password for authorization
    std::string pw;
    std::cout << "Enter your password for authorization: ";
    std::cin >> pw;

    if (pw == currentMember.getPassword()) {
        // Add to CP
        currentMember.setCreditPoints(currentMember.getCreditPoints() + amount);
        std::cout << "Top-up successful! New balance: " 
                  << currentMember.getCreditPoints() 
                  << "\n";
    } else {
        std::cout << "Incorrect password. No changes made.\n";
    }
}

void ProfileView::updateProfileDetails(Member &currentMember) {
    std::cout << "\n-------------------Update Profile Details-------------------\n";
    std::cout << "Current Profile:\n";
    std::cout << "- Full Name: " << currentMember.getName() << "\n";
    std::cout << "- Phone Number: " << currentMember.getPhoneNumber() << "\n";
    std::cout << "- Email: " << currentMember.getEmail() << "\n";
    std::cout << "- ID Type: " << currentMember.getIDType() << "\n";
    std::cout << "- ID/Passport Number: " << currentMember.getIDNumber() << "\n\n";

    // Consume leftover newline if any
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Prompt for new details (press Enter to skip)
    std::string newName, newPhone, newEmail, newIDType, newIDNumber;

    std::cout << "Enter the new Full Name (or press Enter to skip): ";
    std::getline(std::cin, newName);
    if (!newName.empty()) {
        currentMember.setName(newName);
    }

    std::cout << "Enter the new Phone Number (or press Enter to skip): ";
    std::getline(std::cin, newPhone);
    if (!newPhone.empty()) {
        currentMember.setPhoneNumber(newPhone);
    }

    std::cout << "Enter the new Email (or press Enter to skip): ";
    std::getline(std::cin, newEmail);
    if (!newEmail.empty()) {
        currentMember.setEmail(newEmail);
    }

    std::cout << "Enter the new ID Type (Citizen ID/Passport) (or press Enter to skip): ";
    std::getline(std::cin, newIDType);
    if (!newIDType.empty()) {
        currentMember.setIDType(newIDType);
    }

    std::cout << "Enter the new ID/Passport Number (or press Enter to skip): ";
    std::getline(std::cin, newIDNumber);
    if (!newIDNumber.empty()) {
        currentMember.setIDNumber(newIDNumber);
    }

    std::cout << "Profile update completed.\n";
}

void ProfileView::changePassword(Member &currentMember) {
    std::cout << "\n-------------------Change Password-------------------\n";
    
    std::string oldPw, newPw, confirmPw;
    std::cout << "Enter your current password: ";
    std::cin >> oldPw;

    if (oldPw != currentMember.getPassword()) {
        std::cout << "Incorrect current password.\n";
        return;
    }

    std::cout << "Enter your new password: ";
    std::cin >> newPw;

    std::cout << "Confirm your new password: ";
    std::cin >> confirmPw;

    if (newPw != confirmPw) {
        std::cout << "New passwords do not match.\n";
        return;
    }

    // Optionally, add your password validation rules here
    currentMember.setPassword(newPw);
    std::cout << "Password changed successfully!\n";
}

void ProfileView::displayCurrentProfile(const Member &member) {
    std::cout << "\n-------------------Profile Management-------------------\n";
    std::cout << "Current Profile:\n";
    std::cout << "- Username: " << member.getUsername() << "\n";
    std::cout << "- Full Name: " << member.getName() << "\n";
    std::cout << "- Phone Number: " << member.getPhoneNumber() << "\n";
    std::cout << "- Email: " << member.getEmail() << "\n";
    std::cout << "- ID Type: " << member.getIDType() << "\n";
    std::cout << "- ID/Passport Number: " << member.getIDNumber() << "\n";
    std::cout << "- CP Balance: " << member.getCreditPoints() << "\n";
    std::cout << "- Rating: " << member.getAvgRatings() << "\n";
    std::cout << "-------------------------------------------------------\n";
}
