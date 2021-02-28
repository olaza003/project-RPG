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
           std::string output = "Name: " + getName() + '.';
            output = output + " Damage: " + std::to_string(getDmg()) + '(' + std::to_string(dmgVal) + "+" + std::to_string(enchItem->getDmg()) + ").";
            output = output + " Weapon Type: " + enchItem->getType() + '.';
           return output;
        }
};

class Consumable_Enchant: public Consumable {
    protected:
        Consumable* enchItem = nullptr;
    public:
        Consumable_Enchant(int uses, std::string input, Consumable* object = nullptr): Consumable(uses, input), enchItem(object) {}
        ~Consumable_Enchant(){delete enchItem;}
        std::string getName(){return name + ' ' + enchItem->getName();}
        std::string getDescription() {
            std::string output = "Name: " + getName() + '.';
            output = output + " Uses: " + std::to_string(getUses()) + '.';
            output = output + " Enchantment type: " + getType();
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


class FireEnchant_Con: public Consumable_Enchant {
    public:
        FireEnchant_Con(Consumable* object): Consumable_Enchant(object->getUses(), "Fiery", object) {}
        std::string getType() {return "Fire Enchantment";}
        void use(Entity* object){
            //cout << ">>" << object->getName() << " takes fire damage!\n";
            std::cout << "Output\n";
            //enchItem->use();
            //object->takeAttack(5);
        }
};



class EnchantFactory{
    public:
        Item* FireEnchant(Item* object){
            if(object->getItemType() == 0){
                return new FireEnchant_Wea(dynamic_cast<Weapon*>(object));
            }
            if(object->getItemType() == 1){
                return new FireEnchant_Con(dynamic_cast<Consumable*>(object));
            }
            else{return nullptr;}
        }
};

#endif