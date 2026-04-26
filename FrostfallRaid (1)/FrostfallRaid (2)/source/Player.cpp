#include "../headers/Player.h"
#include <iostream>

using namespace std;

Player::Player(string n, int type) : Entity(n, 100, 10), gold(50) {
    inventory = new Inventory();
    maxStamina = 100;
    stamina = 100;
    
    if (type == 1) {
        hp = maxHp = 120; baseDamage = 15; defense = 10;
    } else if (type == 2) { 
        hp = maxHp = 80; baseDamage = 22; defense = 5;
    } else { 
        hp = maxHp = 160; baseDamage = 8; defense = 20;
    }
}

Player::~Player() {
    delete inventory;
}

int Player::attack() {
    if (stamina >= 10) {
        stamina -= 10;
        return baseDamage;
    } 
    return -1; 
}

int Player::specialAttack(int choice) {
    if (choice == 3) { 
        if (stamina >= 30) {
            stamina -= 30;
            return baseDamage * 2;
        }
        return -1;
    } 
    else if (choice == 4) { 
        if (stamina >= 50) {
            stamina -= 50;
            return baseDamage * 3.5;
        }
        return -1;
    }
    return 0;
}

void Player::takeDamage(int damage) {
    int reducedDamage = damage - (defense / 2);
    if (reducedDamage < 1) reducedDamage = 1;
    hp -= reducedDamage;
    if (hp < 0) hp = 0;
}

void Player::heal(int amount) {
    hp += amount;
    if (hp > maxHp) hp = maxHp;
}

void Player::increaseMaxHP(int amount) {
    maxHp += amount;
    hp += amount;
}

void Player::regenStamina() {
    stamina += 15;
    if (stamina > maxStamina) stamina = maxStamina;
}