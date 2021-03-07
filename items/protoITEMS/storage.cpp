#include "storage.hpp"
#include <iostream>

using namespace std;

Weapon* Storage::getItem(int place)
{
   if(place - 1 > storage_len || place < 1) return nullptr;
   
   int val = place - 1; //we would have to decrement it because the 
			//display starts at 1
   if(storage.at(val) -> getItemType() == 1){
	std::cout << "Item is not a weapon" << endl;
                return nullptr;
            }
   else{
       if(val >= storage.size()){
           std::cout <<" There's no item in the slot" << endl;
           return NULL;
        }
        else{
        Item* temp = storage.at(val);
        storage.erase(storage.begin() + val);
        storage_len--;
        return dynamic_cast<Weapon*>(temp);
       }
   }
}

bool Storage::weaponInStorage(){
   for(auto it: storage ){
      if(it -> getItemType() == 0) return true;
   }
   return false;
}

bool Storage::consumInStorage(){
   for(auto it: storage ){
     if(it -> getItemType() == 1) return true;
   }
   return false;
}


void Storage::DisplayStorage(std::ostream& cout)
{ 
  if(storage_len > 0){
    int counter = 1;
    for(auto it : storage)
       cout <<"[" << counter++ << "]" << it -> getDescription() << endl;
  }
  else cout << "There's nothing in your inventory" << endl;
}

void Storage::heal(Entity* object){
            for(auto it : storage)
            {
                if(it -> getItemType() == 1 && it -> getName() == "Potion"){
                    std::cout << "test" << endl;
                    if(dynamic_cast<Consumable*>(it) -> getUses() > 0)
                        dynamic_cast<Consumable*>(it) -> use(object);
                    else std::cout <<"Potion has " << dynamic_cast<Consumable*>(it) -> getUses() << endl;
                }
            }
        }
        
void Storage:: displayPotion()
{
   for(auto it: storage)
   {
      if(it -> getItemType() == 1){
          std::cout  << it -> getDescription() << endl;
      }
   }
}

void Storage::refill()
{
   for(auto it: storage){
     if(it -> getItemType() == 1 && it -> getName() == "Potion") 
          dynamic_cast<Consumable*>(it) -> recharge();
  }
}
