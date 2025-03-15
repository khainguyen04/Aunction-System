#include "RatingsView.h"
#include "../controllers/RatingsController.h"
#include "../models/Member.h"
#include <iostream>

void RatingsView::showRatingsMenu(Member& loggedInMember) {
    RatingsController ratingsController;

    int choice;
    do {
        std::cout << "\n--- Ratings and Reviews ---\n";
        std::cout << "1. Add Rating and Review\n";
        std::cout << "2. View My Reviews\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            ratingsController.addRatingAndReview(loggedInMember);
            break;
        case 2:
            ratingsController.viewMemberReviews(loggedInMember);
            break;
        case 3:
            std::cout << "Exiting Ratings and Reviews menu\n";
            break;
        default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 3);
}
