#include "../headers/Entity.h"

using namespace std;

Entity::Entity(string n, int health, int damage) 
    : name(n), hp(health), maxHp(health), baseDamage(damage) {}

void Entity::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}