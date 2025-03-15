#include "RatingsController.h"
#include "../utils/FileHandler.h"
#include <iostream>
#include <vector>
#include <string>

void RatingsController::addRatingAndReview(Member& loggedInMember) {
    int rating;
    std::string review;

    std::vector<Item> allTransactions = loggedInMember.getBidItems();
    std::vector<Item> eligibleTransactions;

    for (const auto& item : allTransactions) {
        if (item.isAuctionEnded()) {
            eligibleTransactions.push_back(item);
        }
    }

    if (eligibleTransactions.empty()) {
        std::cout << "No completed transactions regarding to your account.\n";
        return;
    }

    std::cout << "\n--- Completed Transactions ---\n";
    for (size_t i = 0; i < eligibleTransactions.size(); ++i) {
        const auto& item = eligibleTransactions[i];
        std::cout << i + 1 << ". Item: " << item.getName()
                  << " (Seller ID: " << item.getMemberId()
                  << ", Buyer ID: " << item.getHighestBidderId() << ")\n";
    }

    int choice;
    std::cout << "Select a transaction to rate (1-" << eligibleTransactions.size() << "): ";
    std::cin >> choice;

    if (choice < 1 || choice > static_cast<int>(eligibleTransactions.size())) {
        std::cout << "Invalid choice\n";
        return;
    }

    const auto& selectedItem = eligibleTransactions[choice - 1];
    int reviewerId = loggedInMember.getMemberID();
    int targetMemberId = (reviewerId == selectedItem.getMemberId())
                         ? selectedItem.getHighestBidderId()
                         : selectedItem.getMemberId();

    std::cout << "Enter rating (1-5): ";
    std::cin >> rating;
    std::cin.ignore();

    if (rating < 1 || rating > 5) {
        std::cout << "Invalid number\n";
        return;
    }

    std::cout << "Enter your review: ";
    std::getline(std::cin, review);

    FileHandler::writeReview(targetMemberId, reviewerId, review, rating);

    std::cout << "Rating and review added successfully.\n";
}

void RatingsController::viewMemberReviews(Member& loggedInMember) {
    int memberId = loggedInMember.getMemberID();

    std::vector<std::string> reviews = FileHandler::readReviewsForMember(memberId);

    if (reviews.empty()) {
        std::cout << "No reviews found\n";
    } else {
        std::cout << "\n--- Reviews ---\n";
        for (const auto& review : reviews) {
            std::cout << "- " << review << "\n";
        }
    }
}

// Returns reviews for a specific member ID
std::vector<std::string> RatingsController::getMemberReviews(int memberId) {
    return FileHandler::readReviewsForMember(memberId);
}
