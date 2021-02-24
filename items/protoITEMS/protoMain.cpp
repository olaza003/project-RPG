#include <iostream>
#include "protoITEMS.hpp"

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

    delete[] list;
    return 0;
}