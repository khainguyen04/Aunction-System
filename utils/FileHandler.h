#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include "../models/Member.h"

class FileHandler {
public:
    static std::vector<Member> readMembersFromCSV(const std::string& filePath);
    static void writeMembersToCSV(const std::string& filePath, const std::vector<Member>& members);

    static std::vector<Item> readItemsFromCSV(const std::string& filePath);
    static void writeItemsToCSV(const std::string& filePath, const std::vector<Item>& items);

    static void updateMemberAvgRating(int memberId, double avgRating);

    static void writeReview(int targetMemberId, int reviewerId, const std::string& review, int rating);
    static std::vector<std::string> readReviewsForMember(int memberId);
};

#endif
