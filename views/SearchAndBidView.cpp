#include "../views/MemberView.h"
#include <iostream>
#include "../views/ProfileView.h"   // Include your new ProfileView
#include "../views/ItemView.h"
#include "../controllers/BidController.h"
#include "../controllers/MemberController.h" 
#include "../controllers/ItemController.h"
#include "../models/Member.h"
#include "../models/Item.h"
#include "SearchAndBidView.h"

void SearchAndBidView::searchAndPlaceBid(Member &currentMember, std::vector<Item> &items) {
    int choice = 0;
    while (choice != 4) {
        std::cout << "\n-------------------Search and Place a Bid-------------------\n";
        std::cout << "Choose your search criterion:\n";
        std::cout << "1. Search by Name\n";
        std::cout << "2. Search by Category\n";
        std::cout << "3. Search by Credit Point (CP) Range\n";
        std::cout << "4. Return to Member Menu\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                BidController::searchByName(currentMember, items);
                break;
            case 2:
                BidController::searchByCategory(currentMember, items);
                break;
            case 3:
                BidController::searchByCPRange(currentMember, items);
                break;
            case 4:
                std::cout << "Returning to Member Menu...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}