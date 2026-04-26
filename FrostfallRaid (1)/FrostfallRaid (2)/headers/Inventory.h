#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
using namespace std;

class Inventory {
private:
    Item** items;
    int itemCount;
    const int maxSlots = 10;

public:
    Inventory();
    ~Inventory();

    bool addItem(Item* item);
    bool removeItem(int index);
    void useItem(int index, Player& p);
    void display() const;
    
    int findItemByName(string itemName) const;
    
    Item* getItem(int index) const;
    int getCount() const { return itemCount; }
};

#endif