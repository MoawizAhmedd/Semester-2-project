#ifndef COMBAT_H
#define COMBAT_H

#include "Player.h"
#include "Enemy.h"

class CombatManager {
private:
    void drawBorder() const; 

public:
    bool startFight(Player& p, Enemy* e);
};

#endif