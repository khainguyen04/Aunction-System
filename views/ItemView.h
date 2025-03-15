#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include <vector>
#include "../models/Item.h"
#include "../controllers/ItemController.h"
#include "../models/Member.h"

class ItemView {
public:
    static void showNonMemberItemList(const std::vector<Item>& items);
    static void showMemberItemList(const std::vector<Item>& items);
    static void showNoItemsMessage();
    static void showMemberListedItems(const std::vector<Item>& items, int memberId);
    static void inputItemDetailsForSale(std::vector<Item>& items);
};

#endif // ITEMVIEW_H
