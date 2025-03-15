#include "BidController.h"
#include <iostream>
#include "../views/ProfileView.h"   // Include your new ProfileView
#include "../views/ItemView.h"
#include "../views/SearchAndBidView.h"
#include "MemberController.h" 
#include "ItemController.h"
#include "../models/Member.h"
#include "../models/Item.h"

void BidController::searchByName(Member &currentMember,std::vector<Item> &items) {
    std::string name;
    std::cout << "Enter the name of the item: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::vector<Item> results;
    for (const auto &item : items) {
        if (item.getName().find(name) != std::string::npos) {
            results.push_back(item);
        }
    }

    if (results.empty()) {
        std::cout << "No items found for \"" << name << "\".\n";
        return;
    }

    std::cout << "Search Results for \"" << name << "\":\n";
    for (size_t i = 0; i < results.size(); ++i) {
        const auto &item = results[i];
        std::cout << i + 1 << ". " << item.getName() << "\n"
                  << "   - Category: " << item.getCategory() << "\n"
                  << "   - Description: " << item.getShortDescription() << "\n"
                  << "   - Current Bid: " << item.getCurrentBid() << " CP\n"
                  << "   - Highest Bidder: " << (item.getHighestBidderId() == 0 ? "None" : std::to_string(item.getHighestBidderId())) << "\n"
                  << "   - Ends: " << item.getEndDate() << "\n";
    }

    int itemChoice;
    std::cout << "Enter the number of the item to place a bid, or 0 to return: ";
    std::cin >> itemChoice;

    if (itemChoice > 0 && itemChoice <= results.size()) {
        BidController bidController;
        bidController.placeBid(currentMember, results[itemChoice - 1]);
    }
}

void BidController::searchByCategory(Member &currentMember, std::vector<Item> &items) {
    std::vector<std::string> categories = {"Electronics", "Collectibles", "Furniture", "Vehicles"};
    std::cout << "Available Categories:\n";
    for (size_t i = 0; i < categories.size(); ++i) {
        std::cout << i + 1 << ". " << categories[i] << "\n";
    }

    int categoryChoice;
    std::cout << "Enter your choice: ";
    std::cin >> categoryChoice;

    if (categoryChoice > 0 && categoryChoice <= categories.size()) {
        std::string category = categories[categoryChoice - 1];
        std::vector<Item> results;
        for (const auto &item : items) {
            if (item.getCategory() == category) {
                results.push_back(item);
            }
        }

        if (results.empty()) {
            std::cout << "No items found in category \"" << category << "\".\n";
            return;
        }

        std::cout << "Search Results in \"" << category << "\":\n";
        for (size_t i = 0; i < results.size(); ++i) {
            const auto &item = results[i];
            std::cout << i + 1 << ". " << item.getName() << "\n"
                      << "   - Category: " << item.getCategory() << "\n"
                      << "   - Description: " << item.getShortDescription() << "\n"
                      << "   - Current Bid: " << item.getCurrentBid() << " CP\n"
                      << "   - Highest Bidder: " << (item.getHighestBidderId() == 0 ? "None" : std::to_string(item.getHighestBidderId())) << "\n"
                      << "   - Ends: " << item.getEndDate() << "\n";
        }

        int itemChoice;
        std::cout << "Enter the number of the item to place a bid, or 0 to return: ";
        std::cin >> itemChoice;

        if (itemChoice > 0 && itemChoice <= results.size()) {
            placeBid(currentMember, results[itemChoice - 1]);
        }
   }
}

void BidController::searchByCPRange(Member &currentMember, std::vector<Item> &items) {
    double minCP, maxCP;
    std::cout << "Enter the minimum CP: ";
    std::cin >> minCP;
    std::cout << "Enter the maximum CP: ";
    std::cin >> maxCP;

    std::vector<Item> results;
    for (const auto &item : items) {
        if (item.getCurrentBid() >= minCP && item.getCurrentBid() <= maxCP) {
            results.push_back(item);
        }
    }

    if (results.empty()) {
        std::cout << "No items found in the CP range " << minCP << " - " << maxCP << ".\n";
        return;
    }

    std::cout << "Search Results in CP range " << minCP << " - " << maxCP << ":\n";
    for (size_t i = 0; i < results.size(); ++i) {
        const auto &item = results[i];
        std::cout << i + 1 << ". " << item.getName() << "\n"
                  << "   - Category: " << item.getCategory() << "\n"
                  << "   - Description: " << item.getShortDescription() << "\n"
                  << "   - Current Bid: " << item.getCurrentBid() << " CP\n"
                  << "   - Highest Bidder: " << (item.getHighestBidderId() == 0 ? "None" : std::to_string(item.getHighestBidderId())) << "\n"
                  << "   - Ends: " << item.getEndDate() << "\n";
    }

    int itemChoice;
    std::cout << "Enter the number of the item to place a bid, or 0 to return: ";
    std::cin >> itemChoice;

    if (itemChoice > 0 && itemChoice <= results.size()) {
        placeBid(currentMember, results[itemChoice - 1]);
    }
}

void BidController::placeBid(Member &currentMember, Item &item) {
    double bidAmount;
    std::cout << "Enter your bid amount: ";
    std::cin >> bidAmount;

    if (bidAmount < item.getCurrentBid() + item.getBidIncrement()) {
        std::cout << "Bid amount is too low. Minimum bid increment is " << item.getBidIncrement() << " CP.\n";
        return;
    }

    // Check if the member has enough CP to cover all their ongoing bids
    int totalOngoingBids = 0;
    for (const auto &bidItem : currentMember.getBidItems()) {
        totalOngoingBids += bidItem.getCurrentBid();
    }

    if (currentMember.getCreditPoints() < totalOngoingBids + bidAmount) {
        std::cout << "Insufficient CP to place this bid.\n";
        return;
    }

    // Ask for automatic bid limit
    double bidLimit;
    std::cout << "Enter your automatic bid limit (or 0 to skip): ";
    std::cin >> bidLimit;

    if (bidLimit > 0 && bidLimit <= bidAmount) {
        std::cout << "Automatic bid limit must be higher than your bid amount.\n";
        return;
    }

    // Check for automatic bid limit conflicts
    if (bidLimit > 0) {
        for (const auto &bidItem : currentMember.getBidItems()) {
            if (bidItem.getId() == item.getId() && bidItem.getCurrentBid() == bidLimit) {
                std::cout << "Automatic bid limit conflict. Please choose a different limit.\n";
                return;
            }
        }
    }

    // Prevent bid withdrawal and item cancellation
    if (item.getHighestBidderId() != 0) {
        std::cout << "You cannot withdraw your bid once placed.\n";
        return;
    }

    // Place the bid
    item.setCurrentBid(bidAmount);
    item.setHighestBidderId(currentMember.getMemberID());
    currentMember.addBidItem(item);

    std::cout << "Bid placed successfully!\n";

    // Handle automatic bids
    if (bidLimit > 0) {
        handleAutomaticBids(currentMember, item, bidLimit);
    }
}

void BidController::handleAutomaticBids(Member &currentMember, Item &item, double bidLimit) {
    while (item.getCurrentBid() < bidLimit) {
        double newBid = item.getCurrentBid() + item.getBidIncrement();
        if (newBid > bidLimit) {
            newBid = bidLimit;
        }

        // Check if the member has enough CP to cover all their ongoing bids
        int totalOngoingBids = 0;
        for (const auto &bidItem : currentMember.getBidItems()) {
            totalOngoingBids += bidItem.getCurrentBid();
        }

        if (currentMember.getCreditPoints() < totalOngoingBids + newBid) {
            std::cout << "Insufficient CP to place this automatic bid.\n";
            return;
        }

        item.setCurrentBid(newBid);
        item.setHighestBidderId(currentMember.getMemberID());
        currentMember.addBidItem(item);

        std::cout << "Automatic bid placed: " << newBid << " CP\n";

        // Simulate another bidder placing a higher bid
        // In a real application, this would be triggered by another user
        break; // Remove this break statement in a real application
    }
}

void BidController::checkAuctionEnd(std::vector<Item> &items, std::vector<Member> &allMembers) {
    for (auto &item : items) {
        if (item.isAuctionEnded()) {
            concludeAuction(item, allMembers);
        }
    }
}

void BidController::concludeAuction(Item &item, std::vector<Member> &allMembers) {
    if (item.getHighestBidderId() == 0) {
        std::cout << "No bids placed on this item.\n";
        return;
    }

    Member *winner = nullptr;
    Member *seller = nullptr;

    for (auto &member : allMembers) {
        if (member.getMemberID() == item.getHighestBidderId()) {
            winner = &member;
        }
        if (member.getMemberID() == item.getMemberId()) {
            seller = &member;
        }
    }

    if (winner && seller) {
        double finalBid = item.getCurrentBid();
        winner->deductCreditPoints(finalBid);
        seller->addCreditPoints(finalBid);

        std::cout << "Auction concluded. " << winner->getUsername() << " won the item with a bid of " << finalBid << " CP.\n";
        std::cout << finalBid << " CP has been transferred from " << winner->getUsername() << " to " << seller->getUsername() << ".\n";
    } else {
        std::cout << "Error concluding auction. Winner or seller not found.\n";
    }
}
