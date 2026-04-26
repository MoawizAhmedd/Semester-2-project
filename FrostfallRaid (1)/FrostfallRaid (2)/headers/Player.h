#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Inventory.h"
using namespace std;

class Player : public Entity {
private:
    int stamina;
    int maxStamina;
    int gold;
    int defense;
    Inventory* inventory;
public:
    Player(string n, int classType);
    ~Player();

    int attack() override; 
    int specialAttack(int choice);
    
    void takeDamage(int damage) override;
    void heal(int amount);
    void increaseMaxHP(int amount);
    void regenStamina();
    
    // Getters
    int getStamina() const { return stamina; }
    int getGold() const { return gold; }
    void addGold(int amount) { gold += amount; }
    Inventory* getInv() { return inventory; }
};

#endif