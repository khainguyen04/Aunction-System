#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <vector>
#include "../models/Member.h"
#include "../models/Item.h"

class AdminView {
public:
    static void showAdminMenu(std::vector<Member>& members, std::vector<Item>& items);

private:
    // NEW FUNCTION to display all members in a table/dash-board style
    static void viewAllMembers(const std::vector<Member>& members);
    static void viewAllItemListings();

};

#endif
