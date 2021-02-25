#include <iostream>
#include "protoITEMS.hpp"
#include "protoENCHANT.hpp"

using namespace std;

class TESTCONSUMABLE: public Consumable {
    public:
        TESTCONSUMABLE(int use = 3, std::string nameInput = "TESTCON"): Consumable(use, nameInput) {}
        std::string getType() { return "TEST TYPE.";}
        std::string getDescription() {return "Name: " + name;}
        void use(Entity* object) {
            cout << "Output.\n";
        }
};

int main() {
    EnchantFactory EnchFa;
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

    Weapon* hi = new FireEnchant_Wea(new Sword());
    Item* bye =  EnchFa.FireEnchant(new Bow(1, "Broken Bow"));
    Consumable* wha = new FireEnchant_Con(new TESTCONSUMABLE());
    cout << hi->getDescription() << endl;
    cout << bye->getDescription() << endl;
    cout << wha->getDescription() << endl;

    delete hi;
    delete bye;
    delete wha;

    return 0;
}