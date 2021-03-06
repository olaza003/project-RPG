#ifndef __ENCHANT_TEST_HPP__
#define __ENCHANT_TEST_HPP__

#include "../items/protoITEMS/protoITEMS.hpp"
#include "../items/protoITEMS/protoENCHANT.hpp"
#include <iostream>

TEST(Enchant, DirectEnchantWeaponClassCall_SWORD){
    Weapon* obj1 = new FireEnchant_Wea(new Sword());
    Weapon* obj2 = new FireEnchant_Wea(new Sword(5, "Not"));
    EXPECT_EQ(obj1->getDescription(), "Fiery Sword\nDamage: 9(5+4)\nWeapon Type: Sword");
    EXPECT_EQ(obj2->getDescription(), "Fiery Not\nDamage: 10(5+5)\nWeapon Type: Sword");
    EXPECT_EQ(obj1->getDmg(), 9);
    EXPECT_EQ(obj2->getDmg(), 10);
    EXPECT_EQ(obj1->getType(), "Fire Enchantment");
    EXPECT_EQ(obj2->getType(), "Fire Enchantment");
    delete obj1; delete obj2;
}

TEST(Enchant, DirectEnchantWeaponClassCall_BOW){
    Weapon* obj1 = new FireEnchant_Wea(new Bow());
    Weapon* obj2 = new FireEnchant_Wea(new Bow(7, "A"));
    EXPECT_EQ(obj1->getDescription(), "Fiery Bow\nDamage: 8(5+3)\nWeapon Type: Bow");
    EXPECT_EQ(obj2->getDescription(), "Fiery A\nDamage: 12(5+7)\nWeapon Type: Bow");
    EXPECT_EQ(obj1->getDmg(), 8);
    EXPECT_EQ(obj2->getDmg(), 12);
    EXPECT_EQ(obj1->getType(), "Fire Enchantment");
    EXPECT_EQ(obj2->getType(), "Fire Enchantment");
    delete obj1; delete obj2;
}

TEST(Enchant, DirectEnchantWeaponClassCall_DAGGER_ONE){
    Weapon* obj1 = new FireEnchant_Wea(new Dagger());
    Weapon* obj2 = new FireEnchant_Wea(new Dagger(1, "Duck"));
    EXPECT_EQ(obj1->getDescription(), "Fiery Dagger\nDamage: 7(5+2)\nWeapon Type: Dagger");
    EXPECT_EQ(obj2->getDescription(), "Fiery Duck\nDamage: 6(5+1)\nWeapon Type: Dagger");
    EXPECT_EQ(obj1->getDmg(), 7);
    EXPECT_EQ(obj2->getDmg(), 6);
    EXPECT_EQ(obj1->getType(), "Fire Enchantment");
    EXPECT_EQ(obj2->getType(), "Fire Enchantment");
    delete obj1; delete obj2;
}

TEST(Enchant, EnchantFactory_SWORD){
    EnchantFactory EnchFac;
    Item* obj1 = EnchFac.FireEnchant(new Sword());
    Item* obj2 = EnchFac.FireEnchant(new Sword(5, "Not"));
    EXPECT_EQ(obj1->getDescription(), "Fiery Sword\nDamage: 9(5+4)\nWeapon Type: Sword");
    EXPECT_EQ(obj2->getDescription(), "Fiery Not\nDamage: 10(5+5)\nWeapon Type: Sword");
    EXPECT_EQ(dynamic_cast<Weapon*>(obj1)->getDmg(), 9);
    EXPECT_EQ(dynamic_cast<Weapon*>(obj2)->getDmg(), 10);
    EXPECT_EQ(obj1->getType(), "Fire Enchantment");
    EXPECT_EQ(obj2->getType(), "Fire Enchantment");
    delete obj1; delete obj2;
}

TEST(Enchant, EnchantFactory_BOW){
    EnchantFactory EnchFac;
    Item* obj1 = EnchFac.FireEnchant(new Bow());
    Item* obj2 = EnchFac.FireEnchant(new Bow(7, "A"));
    EXPECT_EQ(obj1->getDescription(), "Fiery Bow\nDamage: 8(5+3)\nWeapon Type: Bow");
    EXPECT_EQ(obj2->getDescription(), "Fiery A\nDamage: 12(5+7)\nWeapon Type: Bow");
    EXPECT_EQ(dynamic_cast<Weapon*>(obj1)->getDmg(), 8);
    EXPECT_EQ(dynamic_cast<Weapon*>(obj2)->getDmg(), 12);
    EXPECT_EQ(obj1->getType(), "Fire Enchantment");
    EXPECT_EQ(obj2->getType(), "Fire Enchantment");
    delete obj1; delete obj2;
}

TEST(Enchant, EnchantFactory_DAGGER){
    EnchantFactory EnchFac;
    Item* obj1 = EnchFac.FireEnchant(new Dagger());
    Item* obj2 = EnchFac.FireEnchant(new Dagger(1, "Duck"));
    EXPECT_EQ(obj1->getDescription(), "Fiery Dagger\nDamage: 7(5+2)\nWeapon Type: Dagger");
    EXPECT_EQ(obj2->getDescription(), "Fiery Duck\nDamage: 6(5+1)\nWeapon Type: Dagger");
    EXPECT_EQ(dynamic_cast<Weapon*>(obj1)->getDmg(), 7);
    EXPECT_EQ(dynamic_cast<Weapon*>(obj2)->getDmg(), 6);
    EXPECT_EQ(obj1->getType(), "Fire Enchantment");
    EXPECT_EQ(obj2->getType(), "Fire Enchantment");
    delete obj1; delete obj2;
}

#endif
