#ifndef SEARCHANDBIDVIEW_H
#define SEARCHANDBIDVIEW_H

#include <vector>
#include "../models/Member.h"
#include "../models/Item.h"
#include "../controllers/BidController.h"

class SearchAndBidView {
public:
    static void searchAndPlaceBid(Member &currentMember, std::vector<Item> &items);
};

#endif
