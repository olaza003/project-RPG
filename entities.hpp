#ifndef __ENTITIES_HPP__
#define __ENTITIES_HPP__

#include <string>
#include <iostream>
#include "attacks.hpp"

using namespace std;

class Entity {
    protected:
        int health;
        int strength;
        bool defend = false;
        bool dodge = false;
        bool dodgeAttempt = false;
    public:
        void setHealth(int damage)
        {
            health -= damage;
            if (health > 100)
                health = 100;
            if (health < 0)
                health = 0;
        }
        int getHealth() {return health;}
        void setStrength(int newStrength){strength = newStrength;}
        int getStrength(){return strength;}
        void setDefend(bool def){defend = def;}
        bool getDefend(){return defend;}
        void setDodgeAttempt(bool is_dodge){dodgeAttempt = is_dodge;}
        virtual void attack(Entity*) = 0; //calculates how much damage to give to enemy
        virtual void takeAttack(int) = 0; //calculates how much of the above damage to intake
};

class Monster : public Entity {
    private:
        void takeAttack(int damage)
        {
            if (defend)
            {
                setHealth(damage / 2);
                cout << "BLOCKED" << endl;
                cout << "Damage dealt: " << damage / 2 << endl;
                defend = false;
            }
            
            else
            {
                setHealth(damage);
                cout << "Damage dealt: " << damage << endl;
            }
        }
    public:
        Monster(int h = 100, int s = 20){health = h; strength = s;}
        void attack(Entity* player){
            defend = false;
            player->takeAttack( this->getStrength() );
        }
};

class Character : public Entity {
    private:
        int defense;
        int speed;
        int heals;
        CharacterAttack* attackType = nullptr;
        string attackString;
        void takeAttack(int);
    public:
        Character();
        ~Character();
        void setDefense(int d){ defense = d; }
        int getDefense(){ return defense; }
        void setSpeed(int s){ speed = s; }
        int getSpeed(){ return speed; }
        void setHeals(int heal){ heals = heal; }
        int getHeals(){ return heals; }
        void setDodge(bool dod){ dodge = dod; }
        bool getDodge(){ return dodge; }
        void setAttackType(CharacterAttack*);
        CharacterAttack* getAttackType() { return attackType; }
        void setAttackString(string s){ attackString = s; }
        string getAttackString(){ return attackString; }
        void attack(Entity* enemy);
};

#endif //__ENTITIES_HPP__
