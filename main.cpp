#include "entities.hpp"
#include "attacks.hpp"
#include <iostream>

using namespace std;

int main() 
{
    Character* player = new Character();
    Entity* mob = new Monster();
    player->setAttackType(new WarriorAttack());

    cout << "Monster stats: \n   Health: " << mob->getHealth() << endl << "   Strength: " << mob->getStrength() << endl;
    cout << "Player  stats: \n   Health: " << player->getHealth() << endl << "   Strength: " << player->getStrength() << endl;
    		    cout << "   Defense: " << player->getDefense() << endl << "   Speed: " << player->getSpeed() << endl;
    
    cout << "Player Health before attack: " << player->getHealth() << endl;
    mob->attack(player); cout << ">> Monster attacks the player!\n";
    cout << "Player Health after attack:  " << player->getHealth() << endl;
    cout << "Monster Health before attack: " << mob->getHealth() << endl;
    player->attack(mob); cout << ">> Player attacks the monster!\n";
    cout << "Monster Health after attack:  " << mob->getHealth() << endl;

    delete player;
    return 0;
}

