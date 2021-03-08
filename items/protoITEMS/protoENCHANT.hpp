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
        std::string getName(){return name + ' ' + enchItem->getName();}
        std::string getDescription() {
           std::string output = getName();
            output = output + "\nDamage: " + std::to_string(getDmg()) + '(' + std::to_string(dmgVal) + "+" + std::to_string(enchItem->getDmg()) + ")";
            output = output + "\nWeapon Type: " + enchItem->getType();
           return output;
        }
};

//------------------------------WEAPON_ENCHANTS--------------

class FireEnchant_Wea: public Weapon_Enchant {
    public:
        FireEnchant_Wea(Weapon* object): Weapon_Enchant(5, 10, "Fiery", object) {}
        std::string getType() {return "Fire Enchantment";}
        int getDmg(){return dmgVal + enchItem->getDmg();}
};

class EnchantFactory{
    public:
        Weapon* FireEnchant(Weapon* object){
            if(object->getItemType() == 0){
                return new FireEnchant_Wea(object);
            }
            else{return nullptr;}
        }
};

#endif
