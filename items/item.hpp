#ifndef _ITEM_HPP
#define _ITEM_HPP
#include <iostream>
#include <vector>
using namespace std;

class Item
{
    protected:
    string name;
    int damageValue = 0;
    
    public:
    virtual string getDescription(ostream& cout)
    {
        return name + ", Damage: " + to_string(damageValue);
    }
    
    virtual int getDamage() = 0;
    int setDamage(int val)
    {
        damageValue = val;
    }
    
    void setName(string str)
    {
        name = str;
    }
};

class Weapon: public Item
{
    public:
    Weapon(){
        name = "Fist";
        damageValue = 3;
    }
    int getDamage()
    {
        return 3;
    }
};

class Sword: public Item
{
    protected:
        Item* _itemSword;
        int echants = 0;
        void addEnchant()
        {
            echants++;
        }
    
    public: 
        Sword(Item* item)
        {
            _itemSword = item;
            _itemSword -> setName("Sword");
            _itemSword -> setDamage(_itemSword -> getDamage() + 3);
        }
        
        int getDamage()
        {
            return _itemSword ->getDamage();
        }
        
        string getDescription(ostream& cout)
        {
            return _itemSword -> getDescription(cout);
        }
};

class Bow: public Item
{
    protected:
        Item* _itemBow;
        int echants = 0;
        void addEnchant()
        {
            echants++;
        }
        
    public:
        Bow(Item* item)
        {
            _itemBow = item;
            _itemBow -> setName("Bow");
            _itemBow -> setDamage(_itemBow -> getDamage() + 4);
        }
        
        int getDamage()
        {
            return _itemBow -> getDamage();
        }
        string getDescription(ostream& cout)
        {
            return _itemBow -> getDescription(cout);
        }
};

class Wand: public Item
{
    protected:
        Item* _itemWand;
        int echants = 0;
        void addEnchant()
        {
            echants++;
        }
        
    public:
        Wand(Item* item)
        {
            _itemWand = item;
            _itemWand -> setName("Wand");
            _itemWand -> setDamage(_itemWand -> getDamage() + 2);
        }
        
        int getDamage()
        {
            return _itemWand -> getDamage();
        }
        string getDescription(ostream& cout)
        {
            return _itemWand -> getDescription(cout);
        }
};

class Consumable: public Item{
    public:
        Consumable()
        {
            name = "Potion";
            damageValue = 0;
        }
        int getDamage()
        {
            return 0;
        }
        
};

#endif
