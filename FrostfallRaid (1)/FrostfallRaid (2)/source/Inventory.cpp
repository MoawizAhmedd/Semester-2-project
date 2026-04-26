#include "../headers/Inventory.h"
#include <iostream>

using namespace std;

Inventory::Inventory() : itemCount(0) {
    items = new Item*[maxSlots];
    for (int i = 0; i < maxSlots; i++) items[i] = nullptr;
}

Inventory::~Inventory() {
    for (int i = 0; i < itemCount; i++) {
        delete items[i];
    }
    delete[] items;
}

bool Inventory::addItem(Item* item) {
    if (itemCount < maxSlots) {
        items[itemCount++] = item;
        cout << ">>> " << item->getName() << " added to bag." << endl;
        return true;
    }
    cout << ">>> Your bag is too heavy! Drop something first." << endl;
    return false;
}

bool Inventory::removeItem(int index) {
    if (index < 0 || index >= itemCount) return false;
    
    delete items[index];
    for (int i = index; i < itemCount - 1; i++) {
        items[i] = items[i + 1];
    }
    items[itemCount - 1] = nullptr;
    itemCount--;
    return true;
}

void Inventory::useItem(int index, Player& p) {
    if (index < 0 || index >= itemCount) {
        cout << ">>> Invalid item selection!" << endl;
        return;
    }

    Item* item = items[index];
    item->use(p);

    if (item->getType() == "Consumable") {
        removeItem(index);
    }
}

void Inventory::display() const {
    cout << "\n----------- YOUR BAG -----------" << endl;
    if (itemCount == 0) {
        cout << "[ Empty ]" << endl;
    } else {
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i]->getName() << " (" << items[i]->getType() << ")" << endl;
            cout << "   Desc: " << items[i]->getDescription() << endl;
        }
    }
    cout << "--------------------------------" << endl;
}

int Inventory::findItemByName(string name) const {
    for (int i = 0; i < itemCount; i++) {
        if (items[i]->getName() == name) return i;
    }
    return -1;
}

Item* Inventory::getItem(int index) const {
    if (index >= 0 && index < itemCount) return items[index];
    return nullptr;
}