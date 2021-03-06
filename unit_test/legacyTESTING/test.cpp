#include "../items/item.hpp"
#include "../items/Potion.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

TEST(No_Weapon, Fist){
  std::stringstream ss;
  Item* weapon = new Weapon();
 // cout << weapon -> getDescription(ss) << endl;
  EXPECT_EQ(weapon -> getDescription(cout), "Fist, Damage: 3");
}

TEST(Sword, initiateSword){
   Item* weaponSword = new Weapon();
   weaponSword = new Sword(weaponSword);
 //  cout << weaponSword -> getDescription(cout) << endl;
   EXPECT_EQ(weaponSword -> getDescription(cout), "Sword, Damage: 6");
}

TEST(Bow, initiateBow){
   Item* weaponBow = new Weapon();
   weaponBow = new Bow(weaponBow);
 //  cout << weaponBow -> getDescription(cout) << endl;
   EXPECT_EQ(weaponBow -> getDescription(cout), "Bow, Damage: 7");
}

TEST(Wand, intiateWand){
   Item* weaponWand = new Weapon();
   weaponWand = new Wand(weaponWand);
 //  cout << weaponWand -> getDescription(cout)<< endl;
   EXPECT_EQ(weaponWand -> getDescription(cout), "Wand, Damage: 5");
}

TEST(Potion, testingVariety){
   Potion* potion = new Potion();
   cout << potion -> use() << endl;
   cout << potion -> use() << endl;
   EXPECT_EQ(potion -> use(), "You have no potion left");
   potion -> NewPotion();
   EXPECT_EQ(potion -> use(), "You use a potion. You have 1 left");
}

TEST(StorageOfWeapons, vectorIntialize){
   Item* weaponBow = new Weapon();
   weaponBow = new Bow(weaponBow);
   
   Item* weaponWand = new Weapon();
   weaponWand = new Wand(weaponWand);
   
   vector<Item*> vectItems;
   vectItems.push_back(weaponWand);
   vectItems.push_back(weaponBow);
   //cout have the choice determine which item to get by the user
   EXPECT_EQ(vectItems[0] -> getDescription(cout), "Wand, Damage: 5");
 // cout << "obtaining weapon in vector[1]: " << vectItems[0] -> getDescription(cout) << endl;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
