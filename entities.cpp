#include <iostream>
#include "entities.hpp"
#include "attacks.hpp"

Character::Character(){
    health = 100;
    strength = 10;
    defense = 5;
    speed = 5;
    heals = 3;
}

Character::~Character(){ delete attackType; }

void Character::takeAttack(int damage){
    if (defend)
    {
        defend = false;
        damage /= 2;
        if (damage - getDefense() <= 0)
        {
            cout << "BLOCKED" << endl;
            cout << "Damage taken: 0" << endl;
            return;
        }
        setHealth(damage - getDefense());
        cout << "BLOCKED" << endl;
        cout << "Damage taken: " << damage - getDefense() << endl;
        return;
    }
    else
    {
        if (dodge)
        {
            dodge = false;
            cout << "DODGE SUCCESSFUL" << endl;
            cout << "Damage taken: 0" << endl;
            return;
        }
        else
        {
            if (damage - getDefense() <= 0)
            {
                cout << "Damage taken: 0" << endl;
                return;
            }
            setHealth(damage - getDefense());
            cout << "Damage taken: " << damage - getDefense() << endl;
        }
    }
}

void Character::setAttackType(CharacterAttack* newType){ 
    delete attackType;
    attackType = newType;
}

void Character::attack(Entity* enemy){
    defend = false;
    enemy->takeAttack( attackType->attack(this) );
}


int WarriorAttack::attack(Character* player){ 
    return player->getStrength() + 2; 
}

int KnightAttack::attack(Character* player){
    return player->getStrength() - (player->getDefense() / 2);
}

int HunterAttack::attack(Character* player){
    return player->getStrength() + (player->getSpeed() / 2); 
}
