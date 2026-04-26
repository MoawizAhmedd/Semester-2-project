#include "../headers/GameEngine.h"
#include <iostream>
#include <fstream>

using namespace std;

GameEngine::GameEngine() : player(nullptr), difficulty(1), currentLevel(1), isRunning(true) {}

GameEngine::~GameEngine() {
    delete player;
}

void GameEngine::run() {
    mainMenu();
}

void GameEngine::mainMenu() {
    while (isRunning) {

        cout << "\n========================================" << endl;
        cout << "      FROSTBOUND: THE MELEE RPG" << endl;
        cout << "========================================" << endl;
        cout << "1. Start New Journey" << endl;
        cout << "2. Continue Journey" << endl;
        cout << "3. Game Instructions" << endl;
        cout << "4. Exit Game" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Selection >> ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        if (choice == 1) { 
            newGame(); 
            gameLoop(); 
        }
        else if (choice == 2) { 
            loadGame(); 
            if (player != nullptr) gameLoop(); 
        }
        else if (choice == 3) { 
            showInfo(); 
        }
        else if (choice == 4) { 
            isRunning = false; 
            cout << "Closing game. Goodbye!" << endl;
        }
    }
}

void GameEngine::newGame() {
    if (player != nullptr) {
        delete player;
        player = nullptr;
    }

    string name;
    int type, diff;

    cout << "\n--- Character Creation ---" << endl;

    cout << "Enter Hero Name: "; 
    cin >> name;
    cout << "A NEW LEGEND RISES...\n";

    cout << "\nChoose A Class: \n1. Warrior \n2. Rogue \n3. Tank \n"; 
    cin >> type;

    if(type == 1) 
        cout << "You have chosen: Warrior.\nThe battlefield shall tremble beneath your blade!\n"; 
    else if(type == 2) 
        cout << "You have chosen: Rogue.\nShadows will whisper your name!\n"; 
    else if(type == 3) 
        cout << "You have chosen: Tank.\nYou stand unbreakable, a wall against chaos!\n"; 

    cout << "\nWorld Difficulty: \n1. Easy \n2. Hard \n3. Nightmare\n";
    cin >> diff;

    if(diff == 1) 
        cout << "You have Chosen: Easy difficulty. \nIt seems like you are weak...\n";
    else if(diff == 2) 
        cout << "You have Chosen: Hard difficulty. \nIt seems you are brave enough to face a real challenge...\n";
    else if(diff == 3) 
        cout << "You have Chosen: Nightmare difficulty. \nIt seems you fear nothing or perhaps you seek suffering...\n";

    
    difficulty = (diff < 1) ? 1 : diff;
    player = new Player(name, type);
    currentLevel = 1;
    cout << "\n>>> Welcome, " << name << ". Your trial begins now." << endl;
}

void GameEngine::gameLoop() {
    int choice;
    while (player != nullptr && player->isAlive()) {

        cout << "\n========================================" << endl;
        cout << " HUB: CAMP FROSTFIRE | LEVEL: " << currentLevel << endl;
        cout << " [HP: " << player->getHp() << "/" << player->getMaxHp() << " | Gold: " << player->getGold() << "g]" << endl;
        cout << "========================================" << endl;

        cout << "1. Enter Dungeon" << endl;
        cout << "2. Visit Merchant" << endl;
        cout << "3. Inventory & Stats" << endl;
        cout << "4. Manual Save" << endl;
        cout << "5. Return to Menu" << endl;
        cout << "Selection >> ";
        cin >> choice;

        if (choice == 1) {
            Enemy* e;
            if (currentLevel % 5 == 0) e = new IceTitan(difficulty);
            else if (currentLevel % 2 == 0) e = new IceWolf(difficulty);
            else e = new FrostGoblin(difficulty);

            if (combat.startFight(*player, e)) {
                currentLevel++;
            }
            delete e;
        } 
        else if (choice == 2) shop();
        else if (choice == 3) player->getInv()->display();
        else if (choice == 4) saveGame();
        else if (choice == 5) {
            saveGame();
            break;
        }

        if (!player->isAlive()) {
            cout <<"\n############################################" << endl;
            cout <<  "#                                          #" << endl;
            cout <<  "#              G A M E   O V E R           #" << endl;
            cout <<  "#                                          #" << endl;
            cout <<  "#        Your Grave lies in the snow       #" << endl;
            cout <<  "#                                          #" << endl;
            cout <<  "############################################" << endl;
            cout << "Press Enter to return to menu..." << endl;
            cin.ignore();
            cin.get();
            
            delete player;
            player = nullptr;
        }
    }
}

void GameEngine::shop() {
    bool stayInShop = true;

    while (stayInShop) {
        cout << "\n========================================" << endl;
        cout << "      THE IRON FORGE - MERCHANT" << endl;
        cout << "========================================" << endl;
        cout << "Current Gold: " << player->getGold() << "g" << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Healing Potion (25g)     5. Knight Helmet (50g)" << endl;
        cout << "2. Stamina Potion (20g)     6. Knight Chestplate (120g)" << endl;
        cout << "3. Steel Sword (100g)       7. Knight Leggings (90g)" << endl;
        cout << "4. Iron Shield (80g)        8. Knight Boots (40g)" << endl;
        cout << "9. Exit Shop" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Selection >> ";

        int c;
        if (!(cin >> c)) {
            cin.clear();
            while (cin.get() != '\n'); 
            continue;
        }

        if (c == 9) {
            cout << ">>> Shop se bahar ja rahe hain... Safe travels!" << endl;
            stayInShop = false; 
            continue;
        }

        if (c == 1 && player->getGold() >= 25) {
            player->addGold(-25);
            player->getInv()->addItem(new Consumables("Healing Potion", 25, "Heals 50 HP", 50));
        } 
        else if (c == 2 && player->getGold() >= 20) {
            player->addGold(-20);
            player->getInv()->addItem(new Consumables("Stamina Potion", 20, "Restores 40 STM", 40));
        }
        else if (c == 3 && player->getGold() >= 100) {
            player->addGold(-100);
            player->getInv()->addItem(new Weapon("Steel Sword", 100, "+15 DMG", 15));
        }
        else if (c == 4 && player->getGold() >= 80) {
            player->addGold(-80);
            player->getInv()->addItem(new Armor("Iron Shield", 80, "+10 DEF", 10));
        }
        else if (c == 5 && player->getGold() >= 50) {
            player->addGold(-50);
            player->getInv()->addItem(new Armor("Knight Helmet", 50, "+10 HP", 10));
        }
        else if (c == 6 && player->getGold() >= 120) {
            player->addGold(-120);
            player->getInv()->addItem(new Armor("Knight Chestplate", 120, "+30 HP", 30));
        }
        else if (c == 7 && player->getGold() >= 90) {
            player->addGold(-90);
            player->getInv()->addItem(new Armor("Knight Leggings", 90, "+20 HP", 20));
        }
        else if (c == 8 && player->getGold() >= 40) {
            player->addGold(-40);
            player->getInv()->addItem(new Armor("Knight Boots", 40, "+5 HP", 5));
        }
        else {
            cout << "\n>>> [!] Purchase Failed: Ya toh Gold kam hai ya selection galat hai!" << endl;
        }
    }
}

void GameEngine::saveGame() {
    if (player == nullptr) return;

    ofstream outFile("data/save.txt");
    
    if (outFile.is_open()) {
        outFile << currentLevel << endl;
        outFile << difficulty << endl;
        outFile << player->getName() << endl;
        outFile << player->getHp() << endl;
        outFile << player->getMaxHp() << endl;
        outFile << player->getStamina() << endl;
        outFile << player->getGold() << endl;

        int count = player->getInv()->getCount();
        outFile << count << endl;

        for (int i = 0; i < count; i++) {
            outFile << player->getInv()->getItem(i)->getName() << endl;
        }

        outFile.close();
        cout << ">>> Progress, Stats, and Inventory saved successfully!" << endl;
    } else {
        cout << ">>> ERROR: Save directory 'data/' not found!" << endl;
    }
}

void GameEngine::loadGame() {
    ifstream inFile("data/save.txt");
    
    if (!inFile) {
        cout << "\n[!] No save file found." << endl;
        return;
    }

    if (inFile.peek() == ifstream::traits_type::eof()) {
        cout << "\n[!] Save file is empty." << endl;
        inFile.close();
        return;
    }

    try {
        string pName;
        int lvl, diff, currentHp, mHp, stm, gld, invCount;

        inFile >> lvl >> diff >> pName >> currentHp >> mHp >> stm >> gld >> invCount;
        
        if (player != nullptr) delete player;
        
        player = new Player(pName, 1); 
        player->addGold(gld - 50); 
        currentLevel = lvl;
        difficulty = diff;

        string itemName;
        getline(inFile, itemName);

        for (int i = 0; i < invCount; i++) {
            getline(inFile, itemName);
            
            if (itemName == "Healing Potion") 
                player->getInv()->addItem(new Consumables("Healing Potion", 25, "Heals 50 HP", 50));
            else if (itemName == "Stamina Potion") 
                player->getInv()->addItem(new Consumables("Stamina Potion", 20, "Restores 40 STM", 40));
            else if (itemName == "Steel Sword") 
                player->getInv()->addItem(new Weapon("Steel Sword", 100, "+15 DMG", 15));
            else if (itemName == "Iron Shield") 
                player->getInv()->addItem(new Armor("Iron Shield", 80, "+10 DEF", 10));
            else if (itemName == "Knight Helmet") 
                player->getInv()->addItem(new Armor("Knight Helmet", 50, "+10 HP", 10));
            else if (itemName == "Knight Chestplate") 
                player->getInv()->addItem(new Armor("Knight Chestplate", 120, "+30 HP", 30));
            else if (itemName == "Knight Leggings") 
                player->getInv()->addItem(new Armor("Knight Leggings", 90, "+20 HP", 20));
            else if (itemName == "Knight Boots") 
                player->getInv()->addItem(new Armor("Knight Boots", 40, "+5 HP", 5));
        }

        cout << ">>> Game Loaded! Welcome back, " << pName << "." << endl;

    } catch (...) {
        cout << ">>> Error: Save file corrupted." << endl;
    }
    inFile.close();
}

void GameEngine::showInfo() {
    ifstream infoFile("data/info.txt");
    string line;
    cout << "\n--- GUIDEBOOK ---" << endl;
    if (infoFile.is_open()) {
        while (getline(infoFile, line)) cout << line << endl;
        infoFile.close();
    } 
    else 
        cout << "Error: data/info.txt missing." << endl;
    
}