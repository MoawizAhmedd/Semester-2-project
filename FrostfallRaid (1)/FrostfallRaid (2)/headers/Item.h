#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Player; 

class Item {
protected:
    string name;
    string description;
    int value;

public:
    Item(string n, int v, string desc);
    virtual ~Item() {}

    virtual void use(Player& p) = 0;
    virtual string getType() const = 0;

    string getName() const { return name; }
    int getValue() const { return value; }
    string getDescription() const { return description; }
};

class Weapon : public Item {
    int damage;
public:
    Weapon(string n, int v, string desc, int dmg);
    void use(Player& p) override;
    string getType() const override { return "Weapon"; }
    int getDamage() const { return damage; }
};

class Armor : public Item {
    int hpBoost;
public:
    Armor(string n, int v, string desc, int boost);
    void use(Player& p) override;
    string getType() const override { return "Armor"; }
    int getHpBoost() const { return hpBoost; }
};

class Consumables : public Item {
    int healValue;
public:
    Consumables(string n, int v, string desc, int heal);
    void use(Player& p) override;
    string getType() const override { return "Consumable"; }
};

#endif