#include "item.hpp"
#include "Potion.hpp"
#include <iostream>

using namespace std;

int main()
{
   //sword
   Item* weaponSword = new Weapon();
   cout << weaponSword -> getDescription(cout) << endl;
   
   weaponSword = new Sword(weaponSword);
   cout << weaponSword -> getDescription(cout) << endl;

   //bow
   Item* weaponBow = new Weapon();
   weaponBow = new Bow(weaponBow);
   cout << weaponBow -> getDescription(cout) << endl;

   //wand
   Item* weaponWand = new Weapon();
   weaponWand = new Wand(weaponWand);
   cout << weaponWand -> getDescription(cout) << endl;

   //potion
   Potion* potion = new Potion();
   cout << potion -> use() << endl;
   cout << potion -> use() << endl;
   cout << potion -> use() << endl;
   potion -> NewPotion();
   cout << potion -> use() << endl;
   return 0;
}
