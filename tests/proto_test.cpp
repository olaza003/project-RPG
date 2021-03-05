#include "gtest/gtest.h"
#include "../items/protoITEMS/protoITEMS.hpp"
#include "../items/protoITEMS/protoENCHANT.hpp"
#include <iostream>

TEST(Enchant, DirectEnchantWeaponClassCall_SWORD){
    Weapon* obj1 = new FireEnchant_Wea(new Sword());
    Weapon* obj2 = new FireEnchant_Wea(new Sword(5, "Not"));
    EXPECT_EQ(obj1->getDescription(), "Name: Fiery Sword. Damage: 8(5+3). Weapon Type: Sword.");
    EXPECT_EQ(obj2->getDescription(), "Name: Fiery Not. Damage: 10(5+5). Weapon Type: Sword.");
    EXPECT_EQ(obj1->getDmg(), 8);
    EXPECT_EQ(obj2->getDmg(), 10);
    EXPECT_EQ(obj1->getType(), "Fire Enchantment");
    EXPECT_EQ(obj2->getType(), "Fire Enchantment");
    delete obj1; delete obj2;
}

TEST(Enchant, DirectEnchantWeaponClassCall_BOW){
    Weapon* obj1 = new FireEnchant_Wea(new Bow());
    Weapon* obj2 = new FireEnchant_Wea(new Bow(7, "A"));
    EXPECT_EQ(obj1->getDescription(), "Name: Fiery Bow. Damage: 9(5+4). Weapon Type: Bow.");
    EXPECT_EQ(obj2->getDescription(), "Name: Fiery A. Damage: 12(5+7). Weapon Type: Bow.");
    EXPECT_EQ(obj1->getDmg(), 9);
    EXPECT_EQ(obj2->getDmg(), 12);
    EXPECT_EQ(obj1->getType(), "Fire Enchantment");
    EXPECT_EQ(obj2->getType(), "Fire Enchantment");
    delete obj1; delete obj2;
}

TEST(Enchant, DirectEnchantWeaponClassCall_WAND_ONE){
    Weapon* obj1 = new FireEnchant_Wea(new Wand());
    Weapon* obj2 = new FireEnchant_Wea(new Wand(1, "Duck"));
    EXPECT_EQ(obj1->getDescription(), "Name: Fiery Wand. Damage: 7(5+2). Weapon Type: Wand.");
    EXPECT_EQ(obj2->getDescription(), "Name: Fiery Duck. Damage: 6(5+1). Weapon Type: Wand.");
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
    EXPECT_EQ(obj1->getDescription(), "Name: Fiery Sword. Damage: 8(5+3). Weapon Type: Sword.");
    EXPECT_EQ(obj2->getDescription(), "Name: Fiery Not. Damage: 10(5+5). Weapon Type: Sword.");
    EXPECT_EQ(dynamic_cast<Weapon*>(obj1)->getDmg(), 8);
    EXPECT_EQ(dynamic_cast<Weapon*>(obj2)->getDmg(), 10);
    EXPECT_EQ(obj1->getType(), "Fire Enchantment");
    EXPECT_EQ(obj2->getType(), "Fire Enchantment");
    delete obj1; delete obj2;
}

TEST(Enchant, EnchantFactory_BOW){
    EnchantFactory EnchFac;
    Item* obj1 = EnchFac.FireEnchant(new Bow());
    Item* obj2 = EnchFac.FireEnchant(new Bow(7, "A"));
    EXPECT_EQ(obj1->getDescription(), "Name: Fiery Bow. Damage: 9(5+4). Weapon Type: Bow.");
    EXPECT_EQ(obj2->getDescription(), "Name: Fiery A. Damage: 12(5+7). Weapon Type: Bow.");
    EXPECT_EQ(dynamic_cast<Weapon*>(obj1)->getDmg(), 9);
    EXPECT_EQ(dynamic_cast<Weapon*>(obj2)->getDmg(), 12);
    EXPECT_EQ(obj1->getType(), "Fire Enchantment");
    EXPECT_EQ(obj2->getType(), "Fire Enchantment");
    delete obj1; delete obj2;
}

TEST(Enchant, EnchantFactory_WAND){
    EnchantFactory EnchFac;
    Item* obj1 = EnchFac.FireEnchant(new Wand());
    Item* obj2 = EnchFac.FireEnchant(new Wand(1, "Duck"));
    EXPECT_EQ(obj1->getDescription(), "Name: Fiery Wand. Damage: 7(5+2). Weapon Type: Wand.");
    EXPECT_EQ(obj2->getDescription(), "Name: Fiery Duck. Damage: 6(5+1). Weapon Type: Wand.");
    EXPECT_EQ(dynamic_cast<Weapon*>(obj1)->getDmg(), 7);
    EXPECT_EQ(dynamic_cast<Weapon*>(obj2)->getDmg(), 6);
    EXPECT_EQ(obj1->getType(), "Fire Enchantment");
    EXPECT_EQ(obj2->getType(), "Fire Enchantment");
    delete obj1; delete obj2;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}