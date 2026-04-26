#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
using namespace std;

class Enemy : public Entity {
protected:
    int goldDrop;
public:
    Enemy(string n, int health, int damage, int gold);
    int attack() override;
    int getGoldDrop() const { return goldDrop; }
};

class FrostGoblin : public Enemy {
public:
    FrostGoblin(int difficulty);
};

class IceWolf : public Enemy {
public:
    IceWolf(int difficulty);
};

class IceTitan : public Enemy { // The Final Boss
public:
    IceTitan(int difficulty);
};

#endif