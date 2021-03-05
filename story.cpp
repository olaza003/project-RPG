#include "entities.hpp"
#include "attacks.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

void CharacterCreation(Character* p)
{
    char menuOp;
    cout << "Which character do you want to make?" << endl;
    
    cout << "Warriors specialize in dealing damage which will help with attacking" << endl;
    cout << "Knights specialize in defense which will help with defending" << endl;
    cout << "Hunters specialize in speed whihc will help with dodging" << endl;
    
    cout << "Type 'W' for Warrior" << endl;
    cout << "Type 'K' for Knight" << endl;
    cout << "Type 'H' for Hunter" << endl;
    
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
            default : cout << "Invalid Character, try again:" << endl;
        }
    } while (menuOp != 'W' && menuOp != 'K' && menuOp != 'H');
}

void defend(Entity* e)
{
    e -> setDefend();
}

void dodge(Character* p)
{
    //srand(time(0));
    int rng = rand() % 20 + 1;
    if (p -> getSpeed() + 5 >= rng)
        p -> setDodge(true);
}

void heal(Character* p)
{
    if (p -> getHeals() == 0)
    {
        cout << "Out of heals, try doing something else" << endl;
        return;
    }
    
    p -> setHealth(-20);
    p -> setHeals(p -> getHeals() - 1);
}

void enemyAction(Character* p, Monster* e)
{
    //srand(time(0));
    int rng = rand() % 10 + 1;
    if (rng >= 7)
        e -> attack(p);
    else
        defend(e);
}

bool battle(Character* player, Monster* enemy)
{
    int battleOp;
    cout << "An enemy has appeared!" << endl;
    
    while (player -> getHealth() > 0 && enemy -> getHealth() > 0)
    {
        do
        {
            cin >> battleOp;
            
            cout << "Player Health: " << player -> getHealth() << endl;
            cout << "Enemy Health: " << enemy -> getHealth() << endl;
            
            cout << "What do you want to do?" << endl;
            cout << "Type 1 to attack" << endl;
            cout << "Type 2 to defend" << endl;
            cout << "Type 3 to dodge" << endl;
            //cout << "Type 4 to check inventory" << endl;
            cout << "Type 5 to heal" << endl;
            
            switch(battleOp)
            {
                case 1 :
                    player -> attack(enemy);
                    break;
                case 2 :
                    defend(player);
                    break;
                case 3 :
                    dodge(player);
                    break;
                //case 4 :
                    //player -> getInventory();
                    //break;
                case 5 :
                    heal(player);
                    break;
                default : cout << "Not an option, try again" << endl;
            }
        } while (battleOp != 1 && battleOp != 2 && battleOp != 3 && battleOp != 5);
        enemyAction(player);
    }
    
    if (p -> getHealth() <= 0)
        return true;
    else
        return false;
}

void gameOver(Character* p, Monster* e)
{
    if (battle(p, e) == true)
    {
        cout << "GAME OVER";
        //Report(p);
        exit(0);
    }
    //Upgrade(player);
}
