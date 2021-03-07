#ifndef __STORAGE_TEST_HPP__
#define __STORAGE_TEST_HPP__
#include <iostream>
#include "../items/protoITEMS/storage.hpp"
#include "../items/protoITEMS/protoITEMS.hpp"
#include "../items/protoITEMS/protoITEMS.cpp"
#include "../entities.hpp"
TEST(StoreItem, Storing){
   Storage store;
   Weapon* weapon = new Sword();
   store.add_Item(weapon);
   std::stringstream ss;
  // store.DisplayStorage(cout);
   store.DisplayStorage(ss);
   EXPECT_EQ(ss.str(),"[1]Name: Sword\n   Damage: 3\n   Weapon Type: Sword\n" );

}

TEST(NoItem, storing){
  Storage store;
  std::stringstream ss;
 // store.DisplayStorage(cout);
  store.DisplayStorage(ss);
  EXPECT_EQ(ss.str() ,"There's nothing in your inventory\n" );
}

TEST(ConsumableStore, checkingConsumable){
  Storage store;
  Item* potion = new Potion();
  store.add_Item(potion);
  EXPECT_TRUE(store.getItem(1) == nullptr);
}

TEST(StorageLen, checkLength){
  Storage store;
  store.add_Item(new Sword());
  store.add_Item(new Bow());
  EXPECT_EQ(store.getLength(), 2);
}

TEST(checkWeaponInInven, trueIfWeaponFound){
  Storage store;
  store.add_Item(new Potion());
  ASSERT_FALSE(store.weaponInStorage());
  store.add_Item(new Sword());
  ASSERT_TRUE(store.weaponInStorage());
}

TEST(removeItemFromStorage, checkNone){
  Storage store;
  store.add_Item(new Sword());
  Weapon* weapon = store.getItem(1);
  std::stringstream ss;
  store.DisplayStorage(ss);
  EXPECT_EQ(ss.str() ,"There's nothing in your inventory\n" );
  delete weapon;
}

TEST(characterWithWeapon, moreDamage){
  Character* player = new Character();
    player -> setAttackType(new KnightAttack());
    Monster* mob1 = new Monster();
    Monster* mob2 = new Monster();

    player -> attack(mob1);
    EXPECT_EQ(mob1->getHealth(), 92);

    player -> storeItem(new Sword());
    player -> changeWeapon();
    player->attack(mob2);
    EXPECT_EQ(mob2->getHealth(), 89);
}

TEST(charChangeWeapon, newWeapon){
   Character* player = new Character();
   player -> storeItem(new Sword());
   player -> changeWeapon(); 
   Weapon* weapon = player-> getWeapon();
   EXPECT_EQ(weapon-> getDescription(), "Name: Sword\n   Damage: 3\n   Weapon Type: Sword");
}

TEST(charCheckInven, UseCharToCheckStorage){
   Character* player = new Character();
   player -> storeItem(new Sword());
   std::stringstream ss;
   player -> ShowStorage(ss);
   EXPECT_EQ(ss.str(),"[1]Name: Sword\n   Damage: 3\n   Weapon Type: Sword\n" );
}

TEST(PotionHeal, healPlayer){
   Character* player = new Character();
   player -> storeItem(new Potion());
   Monster* mob = new Monster();
   mob -> attack(player);
   EXPECT_EQ(player -> getHealth(), 85);
   player-> PotionHeal(player);
   EXPECT_EQ(player->getHealth(), 100);
}
#endif
