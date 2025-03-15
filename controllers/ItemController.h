#ifndef ITEM_CONTROLLER_H
#define ITEM_CONTROLLER_H

#include "../models/Item.h"
#include <vector>
#include <string>

class ItemController {
private:
    std::vector<Item> items;
    const std::string filePath = "data/items.csv";

public:
    ItemController();

    ~ItemController();

    std::vector<Item> getItems() const;

    void addItem(const Item& newItem, std::vector<Item>& items);

    bool removeItem(int itemId);

    std::vector<Item> getItemsByMemberId(int memberId) const;

};

#endif // ITEM_CONTROLLER_H
