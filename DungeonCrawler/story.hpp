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
char menuOp;
EnchantFactory enchantments;


char read(istream& input)
{
    char in;
    input >> in;
    return in;
}

void CharacterCreation(Character* p)
{
    p -> getStorage() -> add_Item(new Potion());
    cout << ">>These are the classes you can choose from:" << endl;
    
    cout << "  || Warriors specialize in dealing damage which will help with attacking" << endl;
    cout << "  || Knights specialize in defense which will help with defending" << endl;
    cout << "  || Hunters specialize in speed which will help with dodging" << endl;
    
    cout << ">>Choose your class:" << endl;
    
    cout << "  || [W] WARRIOR" << endl;
    cout << "  || [K] KNIGHT" << endl;
    cout << "  || [H] HUNTER" << endl;
    
    do
    {
        menuOp = read(cin);
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
            default : cout << ">>ERROR: INVALID OPTION" << endl << endl;
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
    int rng = rand() % 30 + 1;
    if (p -> getSpeed() + 10 >= rng)
        p -> setDodge(true);
    else
        p -> setDodge(false);
}


void heal(Character* p)
{
    if (!p -> PotionHeal())
    {
        battleOp = ' ';
    }
}

 
void enemyAction(Character* p, Monster* e)
{
    int rng = rand() % 10 + 1;
    if (rng <= 8)
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
    cout << endl << ">>An enemy has appeared!" << endl;
    
    while (player -> getHealth() > 0 && enemy -> getHealth() > 0)
    {
        do
        {
            cout << endl;
            cout << ">>Player Health: " << player -> getHealth();
            cout << "     Enemy Health: " << enemy -> getHealth() << endl;
            
            cout << ">>What do you want to do?" << endl;
            cout << "  || [1] ATTACK" << endl;
            cout << "  || [2] DEFEND" << endl;
            cout << "  || [3] DODGE" << endl;
            cout << "  || [4] CHANGE WEAPON" << endl;
            cout << "  || [5] HEAL" << endl;
            
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
                    cout << ">>CHANGING WEAPON!" << endl;
                    player -> changeWeapon();
                    break;
                case '5' :
                    player -> setDefend(false);
                    player -> setDodge(false);
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

void Report(Character* p, int floor, ostream& cout)
{
    cout << ">>Number of monsters killed: " << floor << endl;
    cout << ">>Number of items: " << p -> getStorage() -> getLength() << endl;
    cout << ">>Items in inventory: " << endl;
    p -> ShowStorage(cout);
}

void Upgrade(Character* p)
{
    cout << endl;
    if (p -> getAttackString() == "Warrior")
    {
        p -> setStrength(p -> getStrength() + 5);
        cout << "NEW STRENGTH: " << p -> getStrength() << endl;
    }
    else if (p -> getAttackString() == "Knight")
    {
        p -> setDefense(p -> getDefense() + 5);
        cout << "NEW DEFENSE: " << p -> getDefense() << endl;
    }
    else if (p -> getAttackString() == "Hunter")
    {
        p -> setSpeed(p -> getSpeed() + 5);
        cout << "NEW SPEED: " << p -> getSpeed() << endl;
    }
}

void Enchant(Character* p)
{
    cout << endl;
    p -> changeWeapon();
    if (p -> getWeapon() != nullptr)
    {
        cout << endl << ">>NEW ENCHANTED WEAPON: " << endl;
        p -> setWeapon(enchantments.FireEnchant(p -> getWeapon()));
        cout << p -> getWeapon() -> getDescription() << endl;
    }
    else
    {
        cout << ">>ERROR: NO WEAPON, LEVELING UP STAT..." << endl;
        Upgrade(p);
    }
}

void NewItem(Character* p, int floor)
{
    vector<string> tierTypeName = {"Bronze Sword","Silver Sword", "Gold Sword",
                                    "Wooden Bow","Bamboo Bow","Crossbow",
                                    "Bronze Dagger","Silver Dagger","Gold Dagger"};

    cout << endl << ">>A weapon was dropped!" << endl;
    int val = 0;
    Item* hold;
    if (p -> getAttackString() == "Warrior")
        hold = new Sword(7 + 3*floor, tierTypeName.at(floor));

    else if (p -> getAttackString() == "Knight")
        hold = new Bow(6 + 3*floor, tierTypeName.at(floor + 3));

    else if (p -> getAttackString() == "Hunter")
        hold = new Dagger(5 + 3*floor, tierTypeName.at(floor + 6));

    p -> getStorage() -> add_Item(hold);
    cout << hold -> getDescription() << endl;
}

void Victory(Character* p, int floor)
{
    char victoryOp;
    p -> setHealth(-100);
    p -> refillPotion();
    cout << endl << ">>You defeated the enemy!" << endl;
    NewItem(p, floor);
    cout << ">>What would you like to do?" << endl;
    
    cout << "  || [1] LEVEL UP STAT" << endl;
    cout << "  || [2] ENCHANT" << endl;
    
    do
    {
        cin >> victoryOp;
        
        switch(victoryOp)
        {
            case '1' :
                Upgrade(p);
                break;
            case '2' :
                Enchant(p);
                break;
            default : cout << ">>ERROR: INVALID OPTION" << endl << endl;
        }
    } while (victoryOp != '1' && victoryOp != '2');
}

bool gameOver(Character* p, Monster* e, int floor)
{
    if (battle(p, e) == true)
    {
        cout << endl << "GAME OVER" << endl << endl;
        Report(p, floor, cout);
        return true;
    }
    Victory(p, floor);
    return false;
}

#endif
