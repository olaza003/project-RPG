#ifndef __STORAGE_HPP__
#define __STORAGE_HPP__
#include "protoITEMS.hpp"
#include "protoENCHANT.hpp"
#include <iostream>
#include <vector>
#include "../../entities.hpp"

using namespace std;

class Entity;

class Storage 
{
    protected:
        std::vector<Item*> storage;
 	EnchantFactory EnchFa;
	int storage_len = 0;
   
    public:
        Storage() { }
        ~Storage()
        {
	    for(auto it: storage)
		delete it;
                storage.clear();
        }
        void add_Item(Item* item){ storage.push_back(item);
	   storage_len++;
	}
	Weapon* getItem(int);
	bool weaponInStorage();
        bool consumInStorage();
	void DisplayStorage(std::ostream& cout);
	void heal(Entity*);
	void displayPotion();
        int getLength(){ return storage_len;}
	void refill();
};

#endif
