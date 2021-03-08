#include "storage.hpp"
#include <iostream>

using namespace std;

Weapon* Storage::getItem(int place)
{
   if(place - 1 > storage_len || place < 1) return nullptr;
   
   int val = place - 1; //we would have to decrement it because the 
			//display starts at 1
   if(storage.at(val) -> getItemType() == 1){
	std::cout << ">>ERROR: ITEM IS NOT A WEAPON" << endl;
                return nullptr;
            }
   else{
       if(val >= storage.size()){
           std::cout <<">>NO ITEM IN SLOT" << endl;
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
    cout << endl;
    for(auto it : storage)
       cout <<"[" << counter++ << "] " << it -> getDescription() << endl;
  }
  else cout << ">>INVENTORY EMPTY" << endl;
}

bool Storage::heal(Entity* object){
            for(auto it : storage)
            {
                if(it -> getItemType() == 1 && it -> getName() == "Potion"){
                    if(dynamic_cast<Consumable*>(it) -> getUses() > 0)
                    {
                        cout << ">>PLAYER HEALED!" << endl;
                        dynamic_cast<Consumable*>(it) -> use(object);
                        std::cout <<">>POTIONS LEFT: " << dynamic_cast<Consumable*>(it) -> getUses() << endl;
                        return true;
                    }
                    else
                    {
                        std::cout << ">>ERROR: POTION EMPTY, CHOOSE ANOTHER OPTION" << endl;
                    }
                }
            }
            return false;
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
