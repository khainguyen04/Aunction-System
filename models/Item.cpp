#include "Item.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <ratio>
#include <chrono>

Item::Item(int id,
           const std::string& name,
           const std::string& category,
           const std::string& shortDescription,
           double startingBid,
           double currentBid,
           double bidIncrement,
           const std::string& endDate,
           int minBuyerRating,
           double sellerRating,
           int memberId,
        int highestBidderId)
    : id(id),
      name(name),
      category(category),
      shortDescription(shortDescription),
      startingBid(startingBid),
      currentBid(currentBid),
      bidIncrement(bidIncrement),
      endDate(endDate),
      minBuyerRating(minBuyerRating),
      sellerRating(sellerRating),
      memberId(memberId),
      highestBidderId(highestBidderId)
{
}



int Item::getId() const {
    return id;
}
void Item::setId(int id) {
    this->id = id;
}

std::string Item::getName() const {
    return name;
}
void Item::setName(const std::string& name) {
    this->name = name;
}

std::string Item::getCategory() const {
    return category;
}
void Item::setCategory(const std::string& category) {
    this->category = category;
}

std::string Item::getShortDescription() const {
    return shortDescription;
}
void Item::setShortDescription(const std::string& shortDescription) {
    this->shortDescription = shortDescription;
}

double Item::getStartingBid() const {
    return startingBid;
}
void Item::setStartingBid(double startingBid) {
    this->startingBid = startingBid;
}

double Item::getCurrentBid() const {
    return currentBid;
}
void Item::setCurrentBid(double currentBid) {
    this->currentBid = currentBid;
}

double Item::getBidIncrement() const {
    return bidIncrement;
}
void Item::setBidIncrement(double bidIncrement) {
    this->bidIncrement = bidIncrement;
}

std::string Item::getEndDate() const {
    return endDate;
}
void Item::setEndDate(const std::string& endDate) {
    this->endDate = endDate;
}

int Item::getMinBuyerRating() const {
    return minBuyerRating;
}
void Item::setMinBuyerRating(int minBuyerRating) {
    this->minBuyerRating = minBuyerRating;
}

double Item::getSellerRating() const {
    return sellerRating;
}
void Item::setSellerRating(double sellerRating) {
    this->sellerRating = sellerRating;
}

int Item::getMemberId() const {
    return memberId;
}
void Item::setMemberId(int memberId) {
    this->memberId = memberId;
}

int Item::getHighestBidderId() const {
    return highestBidderId;
}
void Item::setHighestBidderId(int highestBidderId) {
    this->highestBidderId = highestBidderId;
}

// Utility Methods
bool Item::isEligibleToBid(int buyerRating) const {
    return buyerRating >= minBuyerRating;
}

bool Item::isAuctionEnded() const {
    std::tm tm = {};
    std::istringstream ss(endDate);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

    auto end_time = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    auto now = std::chrono::system_clock::now();

    std::cout << "Debug: Comparing end time (" 
              << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") 
              << ") with current time.\n";

    return now > end_time;
}


// bool Item::canRate(int memberId) const {
//     return this->memberId == memberId || this->highestBidderId == memberId;
// }