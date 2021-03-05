#include "protoITEMS.hpp"
#include "protoENCHANT.hpp"
#include <iostream>
#include <vector>

using namespace std;

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
         //   storage.shrink_to_fit(); //remove leaks 
        }
        void add_Item(Item* item){ storage.push_back(item);
	   storage_len++;
	}
        Item* getItem(int place)
        {
	   if(storage.at(place) -> getItemType() == 1)
                return storage.at(place);
            else{
            if(place >= storage.size()){
                std::cout <<" There's no item in the slot" << endl;
                return NULL;
            }
            else{
                Item* temp = storage.at(place);
                storage.erase(storage.begin() + place);
                storage_len--;
                return temp;
            }
            }
        }
        void DisplayStorage()
        {
            for(auto it : storage)
                std::cout << it -> getDescription() << endl;
        }
        void UsePotion(Item* item)
        {
            if(item -> getItemType() == 1){
                dynamic_cast<Consumable*>(item) -> Use_Item();
                std::cout << "Potion uses: " << dynamic_cast<Consumable*>(item) -> getUses() << endl;
            }
            else 
                std::cout << "Item is not consumbale" << endl;
        }
        
        int getLength(){ return storage_len;}
};
