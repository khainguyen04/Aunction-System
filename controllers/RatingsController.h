#ifndef RATINGS_CONTROLLER_H
#define RATINGS_CONTROLLER_H

#include "../models/Member.h"
#include <vector>
#include <string>

class RatingsController {
public:
    void addRatingAndReview(Member& loggedInMember);
    void viewMemberReviews(Member& loggedInMember);
    std::vector<std::string> getMemberReviews(int memberId);
};

#endif