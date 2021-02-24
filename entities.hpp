#ifndef __ENTITIES_HPP__
#define __ENTITIES_HPP__

#include <string>
#include "attacks.hpp"

using namespace std;

class Entity {
    protected:
        int health;
        int strength;
    public:
        void setHealth(int damage){ health -= damage;}
        int getHealth() {return health;}
        void setStrength(int newStrength){strength = newStrength;}
        int getStrength(){return strength;}
        virtual void attack(Entity*) = 0; //calculates how much damage to give to enemy
        virtual void takeAttack(int) = 0; //calculates how much of the above damage to intake
};

class Monster : public Entity {
    private:
        void takeAttack(int damage) {setHealth(damage);}
    public:
        Monster(int h = 100, int s = 10){health = h; strength = s;}
        void attack(Entity* enemy){
            enemy->takeAttack( this->getStrength() );
        }
};

class Character : public Entity {
    private:
        int defense;
        int speed;
        CharacterAttack* attackType = nullptr;
        string attackString;
        void takeAttack(int);
    public:
        Character();
        ~Character();
        void setDefense(int a){ defense = a; }
        int getDefense(){ return defense; }
        void setSpeed(int a){ speed = a; }
        int getSpeed(){ return speed; }
        void setAttackType(CharacterAttack*);
        CharacterAttack* getAttackType() { return attackType; }
        void setAttackString(string s){ attackString = s; }
        string getAttackString(){ return attackString; }
        void attack(Entity*);
};

#endif //__ENTITIES_HPP__
