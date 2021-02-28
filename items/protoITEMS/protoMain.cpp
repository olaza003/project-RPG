#include <iostream>
#include "protoITEMS.hpp"
#include "storage.cpp"

using namespace std;

int main() {
    Item* list[6];

    list[0] = new Sword();
    list[1] = new Sword(7, "Sharp Sword");
    list[2] = new Bow();
    list[3] = new Bow(1, "Broken Bow");
    list[4] = new Wand();
    list[5] = new Wand(3, "Slightly Better Wand");

    for(int i = 0; i < 6; ++i){
        cout << list[i]->getDescription() << endl;
        delete list[i];
    }
    
    Storage store;
    store.add_Item(new Sword());
    store.add_Item(new Bow(1, "Broken Bow"));
    store.add_Item(new Wand(3, "Slightly Better Wand"));

    store.DisplayStorage();
    
    Item* lh = store.getItem(2);
    store.DisplayStorage();
    store.getItem(2);
    
    delete lh;
    return 0;
}
