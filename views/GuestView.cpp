#include "GuestView.h"
#include "ItemView.h"
#include "../controllers/ItemController.h"
#include <iostream>

void GuestView::showGuestMenu() {
    ItemController itemController;
    std::vector<Item> items = itemController.getItems();
    int choice = 0;
    while (choice != 3) {
        std::cout << "\n-------------------Guest Menu-------------------\n";
        std::cout << "1. View All Item Listings\n";
        std::cout << "2. Search Item by:\n";
        std::cout << "   a. Name\n";
        std::cout << "   b. Category\n";
        std::cout << "   c. Credit Point (CP) Range\n\n";
        std::cout << "3. Return to Main Menu\n";
        std::cout << "-----------------------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                ItemView::showNonMemberItemList(items);
                break;
            case 2:
                // We can show a sub-menu for searching items
                showSearchMenu();
                break;
            case 3:
                std::cout << "Returning to Main Menu...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}

void GuestView::showSearchMenu() {
    int subChoice = 0;
    while (subChoice != 4) {
        std::cout << "\n-----------Search Item-----------\n";
        std::cout << "1. Search by Name\n";
        std::cout << "2. Search by Category\n";
        std::cout << "3. Search by CP Range\n";
        std::cout << "4. Return to Guest Menu\n";
        std::cout << "---------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> subChoice;

        switch (subChoice) {
            case 1:
                std::cout << "Search by Name (feature not yet implemented)...\n";
                break;
            case 2:
                std::cout << "Search by Category (feature not yet implemented)...\n";
                break;
            case 3:
                std::cout << "Search by CP Range (feature not yet implemented)...\n";
                break;
            case 4:
                std::cout << "Returning to Guest Menu...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}
