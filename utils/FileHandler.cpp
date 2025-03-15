#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

/**
 * Reads members from a CSV file, ensuring proper error handling.
 */
std::vector<Member> FileHandler::readMembersFromCSV(const std::string& filePath) {
    std::vector<Member> members;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::ofstream logFile("error.log", std::ios::app);
        logFile << "Cannot open file: " << filePath << std::endl;
        logFile.close();
        return members;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        // Split line by comma
        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 10) {
            std::ofstream logFile("error.log", std::ios::app);
            logFile << "Skipping line due to insufficient columns in members.csv: " << line << std::endl;
            logFile.close();
            continue;
        }

        Member m;

        try {
            // Convert and validate values
            m.setMemberID(std::stoi(tokens[0]));
            m.setUsername(tokens[1]);
            m.setPassword(tokens[2]);
            m.setName(tokens[3]);
            m.setPhoneNumber(tokens[4]);
            m.setEmail(tokens[5]);
            m.setIDType(tokens[6]);
            m.setIDNumber(tokens[7]);
            m.setCreditPoints(std::stoi(tokens[8]));
            m.setAvgRatings(std::stod(tokens[9])); // Use stod for double values
        } catch (const std::exception& e) {
            std::ofstream logFile("error.log", std::ios::app);
            logFile << "Error parsing line in members.csv: " << line << " - " << e.what() << std::endl;
            logFile.close();
            continue;
        }

        members.push_back(m);
    }

    file.close();
    return members;
}

/**
 * Writes members to a CSV file, maintaining the correct column order.
 */
void FileHandler::writeMembersToCSV(const std::string& filePath, const std::vector<Member>& members) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::ofstream logFile("error.log", std::ios::app);
        logFile << "Cannot open file: " << filePath << std::endl;
        logFile.close();
        return;
    }

    for (const auto& m : members) {
        file << m.getMemberID() << ","
             << m.getUsername() << ","
             << m.getPassword() << ","
             << m.getName() << ","
             << m.getPhoneNumber() << ","
             << m.getEmail() << ","
             << m.getIDType() << ","
             << m.getIDNumber() << ","
             << m.getCreditPoints() << ","
             << m.getAvgRatings()
             << std::endl;
    }

    file.close();
}

/**
 * Reads items from a CSV file, handling parsing errors and missing columns properly.
 */
std::vector<Item> FileHandler::readItemsFromCSV(const std::string& filePath) {
    std::vector<Item> items;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::ofstream logFile("error.log", std::ios::app);
        logFile << "Cannot open file: " << filePath << std::endl;
        logFile.close();
        return items;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        // Split line by comma
        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        // Ensure we have at least the required number of columns (12)
        while (tokens.size() < 12) {
            tokens.push_back("0"); // Default value for missing numeric fields
        }

        try {
            items.emplace_back(
                std::stoi(tokens[0]),          // ID
                tokens[1],                     // Name
                tokens[2],                     // Category
                tokens[3],                     // Short Description
                std::stod(tokens[4]),          // Starting Bid
                std::stod(tokens[5]),          // Current Bid
                std::stod(tokens[6]),          // Bid Increment (default to 0 if missing)
                tokens[7],                     // End Date
                std::stoi(tokens[8]),          // Minimum Buyer Rating
                std::stod(tokens[9]),          // Seller Rating
                std::stoi(tokens[10]),         // Member ID
                std::stoi(tokens[11])          // Highest Bidder ID (default to 0 if missing)
            );
        } catch (const std::exception& e) {
            std::ofstream logFile("error.log", std::ios::app);
            logFile << "Error parsing line in items.csv: " << line << " - " << e.what() << std::endl;
            logFile.close();
            continue;
        }
    }

    file.close();
    return items;
}

/**
 * Writes items to a CSV file.
 */
void FileHandler::writeItemsToCSV(const std::string& filePath, const std::vector<Item>& items) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::ofstream logFile("error.log", std::ios::app);
        logFile << "Cannot open file: " << filePath << std::endl;
        logFile.close();
        return;
    }

    for (const auto& item : items) {
        file << item.getId() << ","
             << item.getName() << ","
             << item.getCategory() << ","
             << item.getShortDescription() << ","
             << item.getStartingBid() << ","
             << item.getCurrentBid() << ","
             << item.getBidIncrement() << ","
             << item.getEndDate() << ","
             << item.getMinBuyerRating() << ","
             << item.getSellerRating() << ","
             << item.getMemberId() << ","
             << item.getHighestBidderId()
             << "\n";
    }

    file.close();
}

/**
 * Updates a member's average rating.
 */
void FileHandler::updateMemberAvgRating(int memberId, double avgRating) {
    std::vector<Member> members = readMembersFromCSV("data/members.csv");
    for (auto& member : members) {
        if (member.getMemberID() == memberId) {
            member.setAvgRatings(avgRating);
            break;
        }
    }
    writeMembersToCSV("data/members.csv", members);
}

/**
 * Writes a review to the reviews CSV file.
 */
void FileHandler::writeReview(int targetMemberId, int reviewerId, const std::string& review, int rating) {
    std::ofstream reviewsFile("data/reviews.csv", std::ios::app);
    if (!reviewsFile) {
        std::ofstream logFile("error.log", std::ios::app);
        logFile << "Failed to open reviews.csv for writing" << std::endl;
        logFile.close();
        return;
    }
    reviewsFile << targetMemberId << "," << reviewerId << ",\"" << review << "\"," << rating << "\n";
    reviewsFile.close();
}

/**
 * Reads all reviews for a specific member.
 */
std::vector<std::string> FileHandler::readReviewsForMember(int memberId) {
    std::ifstream reviewsFile("data/reviews.csv");
    std::vector<std::string> reviews;
    std::string line;

    if (!reviewsFile) {
        std::ofstream logFile("error.log", std::ios::app);
        logFile << "Failed to open reviews.csv for reading" << std::endl;
        logFile.close();
        return reviews;
    }

    while (std::getline(reviewsFile, line)) {
        std::stringstream ss(line);
        std::string field;
        int targetMemberId;

        // Extract targetMemberId
        std::getline(ss, field, ',');
        try {
            targetMemberId = std::stoi(field);
        } catch (const std::exception& e) {
            std::ofstream logFile("error.log", std::ios::app);
            logFile << "Invalid member ID in reviews.csv: " << field << " - " << e.what() << std::endl;
            logFile.close();
            continue;
        }

        if (targetMemberId == memberId) {
            std::getline(ss, field, ','); // Skip reviewerId
            std::getline(ss, field, ','); // Extract review text (with quotes)
            reviews.push_back(field);    // Add review text to the result
        }
    }

    reviewsFile.close();
    return reviews;
}