#ifndef BIDCONTROLLER_H
#define BIDCONTROLLER_H

#include <vector>
#include "../models/Member.h"
#include "../models/Item.h"
class BidController {
public:
    static void searchAndPlaceBid(Member &currentMember, std::vector<Item> &items);

    static void searchByName(Member &currentMember, std::vector<Item> &items);

    static void searchByCategory(Member &currentMember, std::vector<Item> &items);

    static void searchByCPRange(Member &currentMember, std::vector<Item> &items);

    static void placeBid(Member &currentMember, Item &item);

    static void handleAutomaticBids(Member &currentMember, Item &item, double bidLimits);

    static void concludeAuction(Item &item, std::vector<Member> &allMembers);

    static void checkAuctionEnd(std::vector<Item> &items, std::vector<Member> &allMembers);
    
};

#endif