#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
private:
    int id;
    std::string name;
    std::string category;
    std::string shortDescription;
    double startingBid;
    double currentBid;
    double bidIncrement;
    std::string endDate;
    int minBuyerRating;
    double sellerRating;
    int memberId;
    int highestBidderId;

public:
    Item();
    Item(int id,
         const std::string &name,
         const std::string &category,
         const std::string &shortDescription,
         double startingBid,
         double currentBid,
         double bidIncrement,
         const std::string &endDate,
         int minBuyerRating,
         double sellerRating,
         int memberId,
         int highestBidderId);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getCategory() const;
    std::string getShortDescription() const;
    double getStartingBid() const;
    double getCurrentBid() const;
    double getBidIncrement() const;
    std::string getEndDate() const;
    int getMinBuyerRating() const;
    double getSellerRating() const;
    int getMemberId() const;
    int getHighestBidderId() const;

    // Setters
    void setId(int id);
    void setName(const std::string &name);
    void setCategory(const std::string &category);
    void setShortDescription(const std::string &shortDescription);
    void setStartingBid(double startingBid);
    void setCurrentBid(double currentBid);
    void setBidIncrement(double bidIncrement);
    void setEndDate(const std::string &endDate);
    void setMinBuyerRating(int minBuyerRating);
    void setSellerRating(double sellerRating);
    void setMemberId(int memberId);
    void setHighestBidderId(int highestBidderId);

    // Utility Methods
    bool isEligibleToBid(int buyerRating) const;
    bool isAuctionEnded() const;

    //bool canRate(int memberId) const;
};

#endif // ITEM_H