#ifndef _POTION_HPP
#define _POTION_HPP
#include "item.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Potion
{
    protected:
        int uses = 2;
        Item* potion;
        
    public:
        Potion()
        {
            potion = new Consumable();
        }
        string use()
        {
            if(uses > 0){
            uses--;
            return "You use a potion. You have " + to_string(uses) + " left";
            }
            else
                return "You have no potion left";
        }
        void NewPotion()
        {
            uses += 2;
        }
};

#endif
