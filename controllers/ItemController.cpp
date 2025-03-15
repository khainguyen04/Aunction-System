#include "ItemController.h"
#include "../utils/FileHandler.h"
#include <iostream>
#include <algorithm>

ItemController::ItemController() {
    items = FileHandler::readItemsFromCSV(filePath);
}

ItemController::~ItemController() {
    //FileHandler::writeItemsToCSV(filePath, items);
}

std::vector<Item> ItemController::getItems() const {
    return items;
}

std::vector<Item> ItemController::getItemsByMemberId(int memberId) const {
    std::vector<Item> memberItems;
    std::copy_if(items.begin(), items.end(), std::back_inserter(memberItems),
                 [memberId](const Item& item) {
                     return item.getMemberId() == memberId;
                 });
    return memberItems;
}

void ItemController::addItem(const Item& newItem, std::vector<Item>& items) {
    for (const auto& item : items) {
        if (item.getId() == newItem.getId()) {
            std::cerr << "Error: Item with ID " << newItem.getId() << " already exists.\n";
            return;
        }
    }
    items.push_back(newItem);
    FileHandler::writeItemsToCSV(filePath,items);
}
