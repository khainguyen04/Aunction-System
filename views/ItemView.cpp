#include "ItemView.h"
#include <iostream>


void ItemView::showNonMemberItemList(const std::vector<Item>& items) {
    std::cout << "\n==== Item Listings (Guest View) ====" << std::endl;
    for (const auto& item : items) {
        std::cout << "Item Name: " << item.getName() << std::endl;
        std::cout << "Category: " << item.getCategory() << std::endl;
        std::cout << "Description: " << item.getShortDescription() << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
}


// void ItemView::showMemberItemList(const std::vector<Item>& items) {
//     std::cout << "\n==== Item Listings (Member View) ====" << std::endl;
//     for (const auto& item : items) {
//         std::cout << "Item Name: " << item.getName() << std::endl;
//         std::cout << "Category: " << item.getCategory() << std::endl;
//         std::cout << "Description: " << item.getShortDescription() << std::endl;
//         std::cout << "Starting Bid: " << item.getStartingBid() << " CP" << std::endl;
//         std::cout << "Current Highest Bid: " << item.getCurrentBid() << " CP" << std::endl;

//         if (item.getHighestBidderId() == 0) {
//             std::cout << "Highest Bidder ID: No bids yet" << std::endl;
//         } else {
//             std::cout << "Highest Bidder ID: " << item.getHighestBidderId() << std::endl;
//         }

//         std::cout << "Bid Increment: " << item.getBidIncrement() << " CP" << std::endl;
//         std::cout << "Auction Ends: " << item.getEndDate() << std::endl;
//         std::cout << "Minimum Buyer Rating: " << item.getMinBuyerRating() << std::endl;
//         std::cout << "Seller Rating: " << item.getSellerRating() << std::endl;
//         std::cout << "-----------------------------------" << std::endl;
//     }
// }



void ItemView::showMemberListedItems(const std::vector<Item>& items, int memberId) {
    std::cout << "\n==== My Listed Items ====" << std::endl;
    bool found = false;

    for (const auto& item : items) {
        if (item.getMemberId() == memberId) {
            found = true;
            std::cout << "Item Name: " << item.getName() << std::endl;
            std::cout << "Category: " << item.getCategory() << std::endl;
            std::cout << "Description: " << item.getShortDescription() << std::endl;
            std::cout << "Starting Bid: " << item.getStartingBid() << " CP" << std::endl;
            std::cout << "Current Highest Bid: " << item.getCurrentBid() << " CP" << std::endl;
            std::cout << "Highest Bidder ID: " << item.getHighestBidderId() << std::endl;
            std::cout << "Bid Increment: " << item.getBidIncrement() << " CP" << std::endl;
            std::cout << "Auction Ends: " << item.getEndDate() << std::endl;
            std::cout << "Minimum Buyer Rating: " << item.getMinBuyerRating() << std::endl;
            std::cout << "-----------------------------------" << std::endl;
        }
    }

    if (!found) {
        std::cout << "You have no listed items." << std::endl;
    }
}

void ItemView::inputItemDetailsForSale(std::vector<Item>& items)
{
    int id;
    std::string name, category, shortDescription, endDate;
    double startingBid, bidIncrement;
    int minBuyerRating;
    
    Member member;
    
    std::cout << "\n==== List Item for Sale ====\n";
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore();  // Ignore the leftover newline character from the previous input
    
    std::cout << "Enter Item Name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter Category: ";
    std::getline(std::cin, category);
    
    std::cout << "Enter Short Description: ";
    std::getline(std::cin, shortDescription);
    
    std::cout << "Enter Starting Bid (CP): ";
    std::cin >> startingBid;
    std::cout << "Enter Bid Increment (CP): ";
    std::cin >> bidIncrement;
    std::cin.ignore();  // Ignore the leftover newline character
    
    std::cout << "Enter Auction End Date (YYYY-MM-DD HH:MM:SS): ";
    std::getline(std::cin, endDate);
    
    std::cout << "Enter Minimum Buyer Rating: ";
    std::cin >> minBuyerRating;

    // Initialize currentBid to startingBid and highestBidderId to 0
    double currentBid = startingBid;
    int highestBidderId = 0;

    // Create and return the new item
    Item newItem(id, name, category, shortDescription, startingBid, currentBid, bidIncrement, endDate,
                 minBuyerRating, member.getAvgRatings(), member.getMemberID(), highestBidderId);
    std::cout << "Item listed for sale successfully!\n";

    // Add the new item to the items vector
    ItemController itemcontroller;
    itemcontroller.addItem(newItem, items);
}


void ItemView::showNoItemsMessage() {
    std::cout << "\nNo items found!" << std::endl;
}
