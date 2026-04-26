#include "../headers/Enemy.h"

using namespace std;

Enemy::Enemy(string n, int health, int damage, int gold) 
    : Entity(n, health, damage), goldDrop(gold) {}

int Enemy::attack() {
    return baseDamage;
}

FrostGoblin::FrostGoblin(int diff) 
    : Enemy("Frost Goblin", 40 * diff, 8 * diff, 25 * diff) {}

IceWolf::IceWolf(int diff) 
    : Enemy("Ice Wolf", 80 * diff, 15 * diff, 60 * diff) {}

IceTitan::IceTitan(int diff) 
    : Enemy("THE ICE TITAN (BOSS)", 250 * diff, 35 * diff, 500) {}