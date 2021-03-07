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
vector<Weapon*> T1weapons;
vector<Weapon*> T2weapons;
vector<Weapon*> T3weapons;
EnchantFactory enchantments;

void fillWeapons()
{
    T1weapons.push_back(new Sword(9, "Bronze Sword"));
    T1weapons.push_back(new Bow(8, "Wooden Bow"));
    T1weapons.push_back(new Dagger(7, "Bronze Dagger"));
    T2weapons.push_back(new Sword(14, "Silver Sword"));
    T2weapons.push_back(new Bow(13, "Bamboo Bow"));
    T2weapons.push_back(new Dagger(12, "Silver Dagger"));
    T3weapons.push_back(new Sword(19, "Gold Sword"));
    T3weapons.push_back(new Bow(18, "Crossbow"));
    T3weapons.push_back(new Dagger(17, "Gold Dagger"));
}

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
            cout << "  || Type 4 to check inventory" << endl;
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
                case '4' :
                    cout << ">>CHECKING INVENTORY!" << endl;
                    player -> changeWeapon();
                    break;
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

void Report(Character* p, int floor)
{
    cout << "Number of monsters killed: " << floor << endl;
    cout << "Number of items: " << p -> getStorage() -> getLength() << endl;
}

void Upgrade(Character* p)
{
    char upgradeOp;
    cout << "You defeated the enemy!" << endl;
    cout << "What would you like to do?" << endl;
    
    cout << "Type 1 to level up your dedicated stat" << endl;
    cout << "Type 2 to enchant one of your weapons" << endl;
    
    do
    {
        cin >> upgradeOp;
        
        switch(upgradeOp)
        {
            case '1' :
                if (p -> getAttackString() == "Warrior")
                {
                    p -> setStrength(p -> getStrength() + 1);
                    cout << "New Strength: " << p -> getStrength() << endl;
                }
                else if (p -> getAttackString() == "Knight")
                {
                    p -> setDefense(p -> getDefense() + 1);
                    cout << "New Defense: " << p -> getDefense() << endl;
                }
                else if (p -> getAttackString() == "Hunter")
                {
                    p -> setSpeed(p -> getSpeed() + 1);
                    cout << "New Speed: " << p -> getSpeed() << endl;
                }
                break;
            case '2' :
                p -> changeWeapon();
                p -> setWeapon(enchantments.FireEnchant(p -> getWeapon()));
                break;
            default : cout << "Invalid Character, try again:" << endl << endl;
        }
    } while (upgradeOp != '1' && upgradeOp != '2');
}

void NewItem(Character* p, int floor)
{
    cout << "You found a new weapon!" << endl;
    int val = 0;
    if (floor == 0)
    {
        if (p -> getAttackString() == "Warrior")
            val = 0;
        else if (p -> getAttackString() == "Knight")
            val = 1;
        else if (p -> getAttackString() == "Hunter")
            val = 2;
        p -> getStorage() -> add_Item(T1weapons.at(val));
        T1weapons.erase(T1weapons.begin() + val);
    }
    else if (floor == 1)
    {
        if (p -> getAttackString() == "Warrior")
            val = 0;
        else if (p -> getAttackString() == "Knight")
            val = 1;
        else if (p -> getAttackString() == "Hunter")
            val = 2;
        p -> getStorage() -> add_Item(T2weapons.at(val));
        T2weapons.erase(T2weapons.begin() + val);
    }
    else if (floor == 2)
    {
        if (p -> getAttackString() == "Warrior")
            val = 0;
        else if (p -> getAttackString() == "Knight")
            val = 1;
        else if (p -> getAttackString() == "Hunter")
            val = 2;
        p -> getStorage() -> add_Item(T3weapons.at(val));
        T3weapons.erase(T3weapons.begin() + val);
    }
}

void gameOver(Character* p, Monster* e, int floor)
{
    if (battle(p, e) == true)
    {
        cout << "GAME OVER";
        Report(p, floor);
        exit(0);
    }
    Upgrade(p);
    NewItem(p, floor);
}

#endif
