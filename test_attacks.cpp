#include "entities.hpp"
#include "attacks.hpp"
#include "gtest/gtest.h"

TEST(CharacterCreation, NewPlayer)
{
	Character* player = new Character();
	EXPECT_EQ(100, player -> getHealth());
	EXPECT_EQ(10, player -> getStrength());
	EXPECT_EQ(5, player -> getDefense());
	EXPECT_EQ(5, player -> getSpeed());
}

TEST(CharacterCreation, NewMonster)
{
        Entity* enemy = new Monster();
        EXPECT_EQ(100, enemy -> getHealth());
        EXPECT_EQ(10, enemy -> getStrength());
}

TEST(Mutators, SetHealth)
{
	Character* player = new Character();
	Entity* enemy = new Monster();
	player -> setHealth(10);
	enemy -> setHealth(10);
	EXPECT_EQ(90, player -> getHealth());
	EXPECT_EQ(90, enemy -> getHealth());
}

TEST(Mutators, SetStrength)
{
        Character* player = new Character();
        Entity* enemy = new Monster();
        player -> setStrength(15);
        enemy -> setStrength(20);
        EXPECT_EQ(15, player -> getStrength());
        EXPECT_EQ(20, enemy -> getStrength());
}

TEST(Mutators, SetDefense)
{
        Character* player = new Character();
        player -> setDefense(15);
        EXPECT_EQ(15, player -> getDefense());
}

TEST(Mutators, SetSpeed)
{
        Character* player = new Character();
        player -> setSpeed(10);
        EXPECT_EQ(10, player -> getSpeed());
}

TEST(Attacks, MonsterAttack)
{
	Character* player = new Character();
	Entity* enemy = new Monster();
	enemy -> attack(player);
	EXPECT_EQ(95, player -> getHealth());
}

TEST(Attacks, MonsterAttackModified)
{
        Character* player = new Character();
        Entity* enemy = new Monster();
	enemy -> setStrength(20);
        enemy -> attack(player);
        EXPECT_EQ(85, player -> getHealth());
}

TEST(Attacks, WarriorAttack)
{
	Character* player = new Character();
        Entity* enemy = new Monster();
	player -> setAttackType(new WarriorAttack());
	player -> attack(enemy);
	EXPECT_EQ(88, enemy -> getHealth());
}

TEST(Attacks, WarriorAttackModified)
{
        Character* player = new Character();
        Entity* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
	player -> setStrength(13);
        player -> attack(enemy);
        EXPECT_EQ(85, enemy -> getHealth());
}

TEST(Attacks, KnightAttack)
{
        Character* player = new Character();
        Entity* enemy = new Monster();
        player -> setAttackType(new KnightAttack());
        player -> attack(enemy);
        EXPECT_EQ(92, enemy -> getHealth());
}

TEST(Attacks, KnightAttackModified)
{
        Character* player = new Character();
        Entity* enemy = new Monster();
        player -> setAttackType(new KnightAttack());
        player -> setDefense(10);
        player -> attack(enemy);
        EXPECT_EQ(95, enemy -> getHealth());
}

TEST(Attacks, HunterAttack)
{
        Character* player = new Character();
        Entity* enemy = new Monster();
        player -> setAttackType(new HunterAttack());
        player -> attack(enemy);
        EXPECT_EQ(88, enemy -> getHealth());
}

TEST(Attacks, HunterAttackModified)
{
        Character* player = new Character();
        Entity* enemy = new Monster();
        player -> setAttackType(new HunterAttack());
        player -> setSpeed(10);
        player -> attack(enemy);
        EXPECT_EQ(85, enemy -> getHealth());
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
