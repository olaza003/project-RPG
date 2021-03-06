#include "entities.hpp"
#include "attacks.hpp"
#include "story.cpp"
#include "gtest/gtest.h"

//PlayerDefendAttack Suite
    TEST(PlayerDefendAttack, 5Damage)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        defend(player);
        enemy -> attack(player);
        EXPECT_EQ(95, player -> getHealth());
        delete player;
        delete enemy;
    }

    TEST(PlayerDefendAttack, 10Damage)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        defend(player);
        enemy -> setStrength(30);
        enemy -> attack(player);
        EXPECT_EQ(90, player -> getHealth());
        delete player;
        delete enemy;
    }


//TestDefend Suite
    TEST(TestDefend, DefDef)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        defend(player);
        defend(enemy);
        EXPECT_EQ(true, player -> getDefend());
        EXPECT_EQ(true, enemy -> getDefend());
        delete player;
        delete enemy;
    }

    TEST(TestDefend, DefDefAttAtt)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        defend(player);
        defend(enemy);
        player -> attack(enemy);
        enemy -> attack(player);
        EXPECT_EQ(false, player -> getDefend());
        EXPECT_EQ(false, enemy -> getDefend());
        EXPECT_EQ(94, enemy -> getHealth());
        EXPECT_EQ(85, player -> getHealth());
        delete player;
        delete enemy;
    }

    TEST(TestDefend, DefDefDefAtt)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        defend(player);
        defend(enemy);
        defend(player);
        enemy -> attack(player);
        EXPECT_EQ(false, player -> getDefend());
        EXPECT_EQ(false, enemy -> getDefend());
        EXPECT_EQ(95 , player -> getHealth());
        delete player;
        delete enemy;
    }

    TEST(TestDefend, AttDefAtt)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        player -> attack(enemy);
        EXPECT_EQ(88, enemy -> getHealth());
        defend(enemy);
        EXPECT_EQ(true, enemy -> getDefend());
        player -> attack(enemy);
        EXPECT_EQ(false, player -> getDefend());
        EXPECT_EQ(false, enemy -> getDefend());
        EXPECT_EQ(82, enemy -> getHealth());
        delete player;
        delete enemy;
    }


//TestDodge Suite
    TEST(TestDodge, DodgeSuccess)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        dodge(player);
        enemy -> attack(player);
        EXPECT_EQ(100, player -> getHealth());
        delete player;
        delete enemy;
    }

    TEST(TestDodge, DodgeFail)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        srand(2);
        dodge(player);
        enemy -> attack(player);
        EXPECT_EQ(85, player -> getHealth());
        delete player;
        delete enemy;
    }


//TestHeal Suite
    TEST(TestHeal, Heal1)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        heal(player);
        EXPECT_EQ(100, player -> getHealth());
        delete player;
        delete enemy;
    }

    TEST(TestHeal, Heal2)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        heal(player);
        enemy -> attack(player);
        EXPECT_EQ(85, player -> getHealth());
        heal(player);
        EXPECT_EQ(100, player -> getHealth());
        delete player;
        delete enemy;
    }

    TEST(TestHeal, Heal3)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        heal(player);
        enemy -> attack(player);
        EXPECT_EQ(85, player -> getHealth());
        heal(player);
        EXPECT_EQ(100, player -> getHealth());
        enemy -> setStrength(30);
        enemy -> attack(player);
        EXPECT_EQ(75, player -> getHealth());
        heal(player);
        EXPECT_EQ(95, player -> getHealth());
        delete player;
        delete enemy;
    }

    TEST(TestHeal, HealMax)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        heal(player);
        enemy -> attack(player);
        EXPECT_EQ(85, player -> getHealth());
        heal(player);
        EXPECT_EQ(100, player -> getHealth());
        enemy -> setStrength(30);
        enemy -> attack(player);
        EXPECT_EQ(75, player -> getHealth());
        heal(player);
        EXPECT_EQ(95, player -> getHealth());
        enemy -> attack(player);
        EXPECT_EQ(70, player -> getHealth());
        heal(player);
        EXPECT_EQ(70, player -> getHealth());
        EXPECT_EQ(' ', battleOp);
        delete player;
        delete enemy;
    }


//TestEnemyAction Suite
    TEST(TestEnemyAction, Attack)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        enemyAction(player, enemy);
        EXPECT_EQ(85, player -> getHealth());
        delete player;
        delete enemy;
    }

    TEST(TestEnemyAction, Defend)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        srand(3);
        player -> attack(enemy);
        enemyAction(player, enemy);
        EXPECT_EQ(100, player -> getHealth());
        EXPECT_EQ(true, enemy -> getDefend());
        delete player;
        delete enemy;
    }


//TestBattle Suite
    TEST(TestBattle, TestWin)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        bool gameOver = battle(player, enemy);
        EXPECT_EQ(0, enemy -> getHealth());
        EXPECT_EQ(false, gameOver);
        delete player;
        delete enemy;
    }

    TEST(TestBattle, TestLoss)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        bool gameOver = battle(player, enemy);
        EXPECT_EQ(0, player -> getHealth());
        EXPECT_EQ(true, gameOver);
        delete player;
        delete enemy;
    }


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
