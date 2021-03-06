#ifndef __STORY_HPP__
#define __STORY_HPP__

#include "entities.hpp"
#include "attacks.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

char battleOp;

void CharacterCreation(Character* p)
{
    char menuOp;
    cout << ">>These are the classes you can choose from:" << endl;
    
    cout << "  || Warriors specialize in dealing damage which will help with attacking" << endl;
    cout << "  || Knights specialize in defense which will help with defending" << endl;
    cout << "  || Hunters specialize in speed which will help with dodging" << endl;
    
    cout << ">>Type 'W' for Warrior" << endl;
    cout << ">>Type 'K' for Knight" << endl;
    cout << ">>Type 'H' for Hunter" << endl;
    
    do
    {
        cin >> menuOp;
        menuOp = toupper(menuOp);
        
        switch(menuOp)
        {
            case 'W' :
                p -> setAttackType(new WarriorAttack());
                p -> setAttackString("Warrior");
                break;
            case 'K' :
                p -> setAttackType(new KnightAttack());
                p -> setAttackString("Knight");
                break;
            case 'H' :
                p -> setAttackType(new HunterAttack());
                p -> setAttackString("Hunter");
                break;
            default : cout << "Invalid Character, try again:" << endl << endl;
        }
    } while (menuOp != 'W' && menuOp != 'K' && menuOp != 'H');
}

void defend(Entity* e)
{
    e -> setDefend(true);
}

void dodge(Character* p)
{
    p -> setDodgeAttempt(true);
    int rng = rand() % 20 + 1;
    if (p -> getSpeed() + 5 >= rng)
        p -> setDodge(true);
    else
        p -> setDodge(false);
}

void heal(Character* p)
{
    if (p -> getHeals() == 0)
    {
        cout << ">>OUT OF HEALS!" << endl;
        battleOp = ' ';
        return;
    }
    
    p -> setHealth(-20);
    p -> setHeals(p -> getHeals() - 1);
    cout << ">>HEALED FOR: 20" << endl;
    cout << ">>HEALS REMAINING: " << p -> getHeals() << endl;
}

void enemyAction(Character* p, Monster* e)
{
    int rng = rand() % 10 + 1;
    if (rng >= 7)
    {
        cout << ">>ENEMY ATTACKED!" << endl;
        e -> attack(p);
    }
    else
    {
        defend(e);
    }
        
}

bool battle(Character* player, Monster* enemy)
{
    cout << ">>An enemy has appeared!" << endl;
    
    while (player -> getHealth() > 0 && enemy -> getHealth() > 0)
    {
        do
        {
            cout << endl;
            cout << ">>Player Health: " << player -> getHealth();
            cout << "     Enemy Health: " << enemy -> getHealth() << endl;
            
            cout << ">>What do you want to do?" << endl;
            cout << "  || Type 1 to attack" << endl;
            cout << "  || Type 2 to defend" << endl;
            cout << "  || Type 3 to dodge" << endl;
            //cout << "  || Type 4 to check inventory" << endl;
            cout << "  || Type 5 to heal" << endl;
            
            cin >> battleOp;
            
            switch(battleOp)
            {
                case '1' :
                    player -> setDefend(false);
                    player -> setDodge(false);
                    cout << ">>PLAYER ATTACKED!" << endl;
                    player -> attack(enemy);
                    break;
                case '2' :
                    player -> setDodge(false);
                    cout << ">>PLAYER DEFENDED!" << endl;
                    defend(player);
                    break;
                case '3' :
                    player -> setDefend(false);
                    cout << ">>PLAYER TRIED TO DODGE!" << endl;
                    dodge(player);
                    break;
                //case 4 :
                    //cout << ">>CHECKING INVENTORY!" << endl;
                    //player -> getInventory();
                    //break;
                case '5' :
                    player -> setDefend(false);
                    player -> setDodge(false);
                    cout << ">>PLAYER HEALED!" << endl;
                    heal(player);
                    break;
                default : cout << ">>ERROR, INVALID OPTION" << endl;
            }
        } while (battleOp != '1' && battleOp != '2' && battleOp != '3' && battleOp != '5');
        if (enemy -> getHealth() > 0)
            enemyAction(player, enemy);
    }
    
    if (player -> getHealth() <= 0)
    {
        return true;
    }
    else
        return false;
}

void gameOver(Character* p, Monster* e)
{
    if (battle(p, e) == true)
    {
        cout << "GAME OVER" << endl;
        //Report(p);
        exit(0);
    }
    //Upgrade(player);
}

#endif