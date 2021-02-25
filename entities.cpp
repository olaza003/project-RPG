#include "entities.hpp"
#include "attacks.hpp"

Character::Character(){
    health = 100;
    strength = 10;
    defense = 5;
    speed = 5;
}

Character::~Character(){ delete attackType; }

void Character::takeAttack(int damage){
    if(damage - getDefense() <= 0){return;}
    else{ setHealth(damage - getDefense()); }
}

void Character::setAttackType(CharacterAttack* newType){ 
    delete attackType;
    attackType = newType;
}

void Character::attack(Entity* enemy){
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
