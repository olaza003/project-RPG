#include "protoITEMS.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Storage 
{
    protected:
        std::vector<Item*> storage;
    
    public:
        Storage() { }
        ~Storage()
        {
	    for(auto it: storage)
		delete it;
            storage.clear();
         //   storage.shrink_to_fit(); //remove leaks 
        }
        void add_Item(Item* item){ storage.push_back(item);}
        Item* getItem(int place)
        {
            if(place >= storage.size()){
                std::cout <<" There's no item in the slot" << endl;
                return NULL;
            }
            else{
                Item* temp = storage.at(place);
                storage.erase(storage.begin() + place);
                return temp;
            }
        }
        void DisplayStorage()
        {
            for(auto it : storage)
                std::cout << it -> getDescription() << endl;
        }
    
};
