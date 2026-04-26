#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include "Combat.h"
#include <string>

class GameEngine {
private:
    Player* player;
    CombatManager combat;
    int difficulty;
    int currentLevel;
    bool isRunning;

    // Internal Menus
    void mainMenu();
    void newGame();
    void gameLoop();
    void shop();
    
    void saveGame();
    void loadGame();
    void showInfo();

    void displayGameOver();

public:
    GameEngine();
    ~GameEngine();
    void run();
};

#endif