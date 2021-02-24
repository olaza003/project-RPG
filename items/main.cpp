#include "item.hpp"
#include "Potion.hpp"
#include <iostream>

using namespace std;

int main()
{
   //sword
   Item* weaponSword = new Weapon();
  // Item* temp = new Weapon();
   cout << weaponSword -> getDescription(cout) << endl;

   Item* temp  = new Sword(weaponSword);
   cout << weaponSword -> getDescription(cout) << endl;
    delete temp;
   //bow
   Item* weaponBow = new Weapon();
   temp = new Bow(weaponBow);
   cout << temp -> getDescription(cout) << endl;
   delete temp;
   //wand
   Item* weaponWand = new Weapon();
   temp = new Wand(weaponWand);
   cout << temp -> getDescription(cout) << endl;
   delete temp;

   //potion
   Potion* potion = new Potion();
   cout << potion -> use() << endl;
   cout << potion -> use() << endl;
   cout << potion -> use() << endl;
   potion -> NewPotion();
   cout << potion -> use() << endl;
   
   delete weaponSword;
   delete weaponBow;
   delete weaponWand;
   delete potion;
   return 0;
}
