#include "entities.hpp"
#include "attacks.hpp"
#include <iostream>
#include <cctype>

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
