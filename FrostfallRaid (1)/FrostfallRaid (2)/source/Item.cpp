#include "../headers/Item.h"
#include "../headers/Player.h"
#include <iostream>

using namespace std;

Item::Item(string n, int v, string desc) : name(n), value(v), description(desc) {}

Weapon::Weapon(string n, int v, string desc, int dmg) : Item(n, v, desc), damage(dmg) {}
void Weapon::use(Player& p) {
    cout << ">>> You equip the " << name << ". Your strikes feel heavier!" << endl;
}

Armor::Armor(string n, int v, string desc, int boost) : Item(n, v, desc), hpBoost(boost) {}
void Armor::use(Player& p) {
    p.increaseMaxHP(hpBoost);
    cout << ">>> You don the " << name << ". Max HP increased by " << hpBoost << "!" << endl;
}

Consumables::Consumables(string n, int v, string desc, int heal) : Item(n, v, desc), healValue(heal) {}
void Consumables::use(Player& p) {
    if (this->name == "Stamina Potion") {
        cout << ">>> You drink the Stamina Potion! Energy restored." << endl;
    } else {
        p.heal(healValue);
        cout << ">>> You drink the " << name << "! HP restored." << endl;
    }
}