#ifndef __PROTOENCHANT_HPP__
#define __PROTOENCHANT_HPP__

#include "protoITEMS.hpp"

//-------------------------------ENCHANTS---------------------

class Weapon_Enchant: public Weapon {
    protected:
        Weapon* enchItem;
    public:
        Weapon_Enchant(int Dmg, int useInput, std::string input, Weapon* object = nullptr): Weapon(Dmg, input), enchItem(object) { dmgVal = Dmg; }
        ~Weapon_Enchant(){delete enchItem;}
};

class Consumable_Enchant: public Consumable {
    protected:
        Consumable* enchItem = nullptr;
    public:
        Consumable_Enchant(int uses, std::string input, Consumable* object = nullptr): Consumable(uses, input), enchItem(object) {}
        ~Consumable_Enchant(){delete enchItem;}
};

//------------------------------WEAPON_ENCHANTS--------------

class FireEnchant: public Weapon_Enchant {
    public:
        FireEnchant(Weapon* object): Weapon_Enchant(5, 10, "Fiery", object) {}
        std::string getName(){return name + ' ' + enchItem->getName();}
        std::string getDescription() {
           std::string output = "Name: " + getName() + '.';
            output = output + " Damage: " + std::to_string(getDmg()) + '(' + std::to_string(dmgVal) + "+" + std::to_string(enchItem->getDmg()) + ").";
            output = output + " Weapon Type: " + enchItem->getType() + '.';
           return output;
        }
        int getDmg(){return dmgVal + enchItem->getDmg();}

};

#endif