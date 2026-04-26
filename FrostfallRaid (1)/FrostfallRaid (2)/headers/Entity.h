#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
using namespace std;

class Entity {
protected:
    string name;
    int hp;
    int maxHp;
    int baseDamage;

public:
    Entity(string n, int health, int damage);
    virtual ~Entity() {} // Virtual destructor for proper cleanup

    virtual int attack() = 0; 
    virtual void takeDamage(int damage);

    string getName() const { return name; }
    int getHp() const { return hp; }
    int getMaxHp() const { return maxHp; }
    bool isAlive() const { return hp > 0; }
};

#endif