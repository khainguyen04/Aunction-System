#include "Member.h"
#include "../controllers/RatingsController.h"

// Default constructor
Member::Member()
    : memberID(0),
      username(""),
      password(""),
      name(""),
      phoneNumber(""),
      email(""),
      IDType(""),
      IDNumber(""),
      creditPoints(0),
      avgRatings(3.0) // Default rating
{
    // bidItems and sellItems are default-initialized (empty)
}

// Parameterized constructor
Member::Member(int id,
               const std::string& user,
               const std::string& pass,
               const std::string& nm,
               const std::string& phone,
               const std::string& mail,
               const std::string& type,
               const std::string& number)
    : memberID(id),
      username(user),
      password(pass),
      name(nm),
      phoneNumber(phone),
      email(mail),
      IDType(type),
      IDNumber(number),
      creditPoints(0),
      avgRatings(3.0) // Default rating
{
    // bidItems and sellItems are default-initialized (empty)
}

// Getters and Setters
int Member::getMemberID() const {
    return memberID;
}
void Member::setMemberID(int id) {
    memberID = id;
}

std::string Member::getUsername() const {
    return username;
}
void Member::setUsername(const std::string& user) {
    username = user;
}

std::string Member::getPassword() const {
    return password;
}
void Member::setPassword(const std::string& pass) {
    password = pass;
}

std::string Member::getName() const {
    return name;
}
void Member::setName(const std::string& nm) {
    name = nm;
}

std::string Member::getPhoneNumber() const {
    return phoneNumber;
}
void Member::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
}

std::string Member::getEmail() const {
    return email;
}
void Member::setEmail(const std::string& mail) {
    email = mail;
}

std::string Member::getIDType() const {
    return IDType;
}
void Member::setIDType(const std::string& type) {
    IDType = type;
}

std::string Member::getIDNumber() const {
    return IDNumber;
}
void Member::setIDNumber(const std::string& number) {
    IDNumber = number;
}

int Member::getCreditPoints() const {
    return creditPoints;
}
void Member::setCreditPoints(int points) {
    creditPoints = points;
}

double Member::getAvgRatings() const {
    return avgRatings;
}
void Member::setAvgRatings(double rating) {
    avgRatings = rating;
}

// bidItems & sellItems
std::vector<Item>& Member::getBidItems() {
    return bidItems;
}
void Member::addBidItem(const Item& item) {
    bidItems.push_back(item);
}

std::vector<Item>& Member::getSellItems() {
    return sellItems;
}
void Member::addSellItem(const Item& item) {
    sellItems.push_back(item);
}

// Change credit points
void Member::deductCreditPoints(double amount) {
    creditPoints -= amount;
}
void Member::addCreditPoints(double amount) {
    creditPoints += amount;
}

// Retrieve Reviews
std::vector<std::string> Member::getReviews() const {
    RatingsController ratingsController;
    return ratingsController.getMemberReviews(getMemberID());
}