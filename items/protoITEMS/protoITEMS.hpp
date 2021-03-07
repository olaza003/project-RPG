#ifndef __PROTOITEMS_HPP__
#define __PROTOITEMS_HPP__
#include <iostream>
#include <string>

class Entity;

class Item {
    protected:
        std::string name;
        int itemType; //0 for weapons. 1 for Consumables.
    public:
        Item(std::string input = "No Name"): name(input) {};
        virtual ~Item() = default;
        void setName(std::string input){name = input;}
        int getItemType() {return itemType;}
        virtual std::string getName(){return name;}
        virtual std::string getType() = 0; //abstract function
        virtual std::string getDescription() = 0; //abstract function
};

class Weapon : public Item { //getDescription() is not overloaded. Weapon remains abstract
    protected:
        int dmgVal;
    public:
        Weapon(int Dmg, std::string name): Item(name), dmgVal(Dmg) {itemType = 0;}
        void setDmg(int dmg){dmgVal = dmg;}
        virtual int getDmg(){return dmgVal;}
};

class Consumable: public Item{ //getDescription is not overloaded. Adds new virtual function. Is abstract
    protected:
        int uses;
    public:
        Consumable(int useInput, std::string nameInput): Item(nameInput), uses(useInput) {itemType = 1;}
        int getUses() {return uses;}
        virtual void use(Entity*) = 0;
	void Use_Item(){uses--;} //added this function
	void recharge(){uses = 3;}
};

class Potion: public Consumable{
    public:
        Potion(int use = 3, std::string nameInput = "Potion"): Consumable(use, nameInput) {}
        std::string getType() { return "Potion";}
        std::string getDescription() {return "Name: " + name + "\n   uses: " + std::to_string(this ->getUses());}
        void use(Entity*);
};

//------------------------WEAPONS-----------------------

class Sword: public Weapon {
    public:
        Sword(int Dmg = 3, std::string input = "Sword"): Weapon(Dmg, input) {}
        std::string getType() {return "Sword";}
        std::string getDescription(){
            return "Name: " + name + "\n   Damage: " + std::to_string(dmgVal) + "\n   Weapon Type: Sword";
        }
};

class Bow: public Weapon {
    public:
        Bow(int Dmg = 4, std::string input = "Bow"): Weapon(Dmg, input) {}
        std::string getType() {return "Bow";}
        std::string getDescription(){
            return "Name: " + name + "\n   Damage: " + std::to_string(dmgVal) + "\n   Weapon Type: Bow";
        }
};

class Dagger: public Weapon {
    public:
        Dagger(int Dmg = 2, std::string input = "Dagger"): Weapon(Dmg, input) {}
        std::string getType() {return "Dagger";}
        std::string getDescription(){
            return "Name: " + name + "\n   Damage: " + std::to_string(dmgVal) + "\n   Weapon Type: Wand";
        }
};

//------------------------CONSUMABLES-------------------



#endif
