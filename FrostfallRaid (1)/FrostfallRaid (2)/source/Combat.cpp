#include "../headers/Combat.h"
#include <iostream>
#include <limits>

using namespace std;

bool CombatManager::startFight(Player& p, Enemy* e) {
    cout << "\n==================================================" << endl;
    cout << "   BATTLE INITIATED: " << p.getName() << " vs " << e->getName() << endl;
    cout << "==================================================" << endl;

    while (p.isAlive() && e->isAlive()) {
        cout << "\n[ " << p.getName() << " HP: " << p.getHp() << "/" << p.getMaxHp() 
             << " | STM: " << p.getStamina() << " ]" << endl;
        cout << "[ " << e->getName() << " HP: " << e->getHp() << "/" << e->getMaxHp() << " ]" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "1. Basic Attack" << endl;
        cout << "2. Use Inventory" << endl;
        cout << "3. Special Move" << endl;
        cout << "4. Ultimate Combo" << endl;
        cout << "Selection >> ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        if (choice == 2) {
            p.getInv()->display();
            cout << "Item Index (0 to cancel): ";
            int idx; cin >> idx;
            if (idx > 0) {
                p.getInv()->useItem(idx - 1, p);
                cout << ">>> Action preserved! You can still attack." << endl;
            }
            continue; 
        }

        int damageDealt = 0;
        if (choice == 1) {
            damageDealt = p.attack();
        } 
        else if (choice == 3 || choice == 4) {
            damageDealt = p.specialAttack(choice);
        }

        if (damageDealt == -1) {
            cout << "\n>>> [!] ATTACK FAILED: Not enough stamina!" << endl;
            cout << ">>> You fumbled your weapon due to exhaustion." << endl;
        } 
        else if (damageDealt > 0) {
            cout << "\n>>> SUCCESS: You dealt " << damageDealt << " damage!" << endl;
            e->takeDamage(damageDealt);
        }

        if (e->isAlive()) {
            int eDmg = e->attack();
            cout << ">>> " << e->getName() << " strikes back for " << eDmg << " damage!" << endl;
            p.takeDamage(eDmg);
        }

        p.regenStamina(); 
    }

    if (p.isAlive()) {
        cout << "\n************************************" << endl;
        cout << "* VICTORY!             *" << endl;
        cout << "************************************" << endl;
        cout << "Gained " << e->getGoldDrop() << " gold from the " << e->getName() << "." << endl;
        p.addGold(e->getGoldDrop());
        return true;
    }

    return false;
}