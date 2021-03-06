#include "entities.hpp"
#include "attacks.hpp"
#include "story.cpp"
#include "gtest/gtest.h"

TEST(CharacterCreation, CheckWarrior)
{
    Character* player = new Character();
    CharacterCreation(player);
    EXPECT_EQ(player -> getAttackString(), "Warrior");
    delete player;
}

TEST(CharacterCreation, CheckKnight)
{
    Character* player = new Character();
    CharacterCreation(player);
    EXPECT_EQ(player -> getAttackString(), "Knight");
    delete player;
}

TEST(CharacterCreation, CheckHunter)
{
    Character* player = new Character();
    CharacterCreation(player);
    EXPECT_EQ(player -> getAttackString(), "Hunter");
    delete player;
}

TEST(CreationAttack, TestWarrior)
{
    Character* player = new Character();
    Monster* enemy = new Monster();
    CharacterCreation(player);
    player -> attack(enemy);
    EXPECT_EQ(enemy -> getHealth(), 88);
    delete player;
    delete enemy;
}

TEST(CreationAttack, TestKnight)
{
    Character* player = new Character();
    Monster* enemy = new Monster();
    CharacterCreation(player);
    player -> attack(enemy);
    EXPECT_EQ(enemy -> getHealth(), 92);
    delete player;
    delete enemy;
}

TEST(CreationAttack, TestHunter)
{
    Character* player = new Character();
    Monster* enemy = new Monster();
    CharacterCreation(player);
    player -> attack(enemy);
    EXPECT_EQ(enemy -> getHealth(), 88);
    delete player;
    delete enemy;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
