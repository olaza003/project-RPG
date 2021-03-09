#ifndef __BATTLE_TEST_HPP__
#define __BATTLE_TEST_HPP__

#include <iostream>
#include "../entities.hpp"
#include "../attacks.hpp"
#include "../items/protoITEMS/protoITEMS.hpp"
#include "../items/protoITEMS/protoENCHANT.hpp"
#include "../story.hpp"


//PlayerDefendAttack Suite
    TEST(PlayerDefendAttack, 2Damage)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        defend(player);
        enemy -> attack(player);
        EXPECT_EQ(98, player -> getHealth());
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
        EXPECT_EQ(90, player -> getHealth());
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
        EXPECT_EQ(98 , player -> getHealth());
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
        srand(3);
        dodge(player);
        enemy -> attack(player);
        EXPECT_EQ(90, player -> getHealth());
        delete player;
        delete enemy;
    }


//TestHeal Suite
    TEST(TestHeal, Heal1)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        player -> storeItem(new Potion());
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
        player -> storeItem(new Potion());
        heal(player);
        enemy -> attack(player);
        EXPECT_EQ(90, player -> getHealth());
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
        player -> storeItem(new Potion());
        heal(player);
        enemy -> attack(player);
        EXPECT_EQ(90, player -> getHealth());
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
        player -> storeItem(new Potion());
        heal(player);
        enemy -> attack(player);
        EXPECT_EQ(90, player -> getHealth());
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
    TEST(TestEnemyAction, Defend)
    {
        srand(4);
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        enemyAction(player, enemy);
        EXPECT_EQ(100, player -> getHealth());
        delete player;
        delete enemy;
    }

    TEST(TestEnemyAction, Attack)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        srand(3);
        player -> attack(enemy);
        enemyAction(player, enemy);
        EXPECT_EQ(90, player -> getHealth());
        EXPECT_EQ(false, enemy -> getDefend());
        delete player;
        delete enemy;
    }


//TestReport Suite
    TEST(TestReport, FloorZero0)
    {
        Character* player = new Character();
        std::stringstream ss;
        Report(player, 0, ss);
        EXPECT_EQ(ss.str(), ">>Number of monsters killed: 0\n>>Number of items: 0\n>>Items in inventory: \n>>INVENTORY EMPTY\n");
        delete player;
    }

    TEST(TestReport, FloorSix3Weapons)
    {
        Character* player = new Character();
        player -> storeItem(new Sword());
        player -> storeItem(new Bow());
        player -> storeItem(new Dagger());
        std::stringstream ss;
        Report(player, 6, ss);
        EXPECT_EQ(ss.str(), ">>Number of monsters killed: 6\n>>Number of items: 3\n>>Items in inventory: \n\n[1] Sword\nDamage: 4\nWeapon Type: Sword\n\n[2] Bow\nDamage: 3\nWeapon Type: Bow\n\n[3] Dagger\nDamage: 2\nWeapon Type: Dagger\n");
        delete player;
    }

    TEST(TestReport, FloorOne3Potions)
    {
        Character* player = new Character();
        player -> storeItem(new Potion());
        player -> storeItem(new Potion());
        player -> storeItem(new Potion());
        std::stringstream ss;
        Report(player, 1, ss);
        EXPECT_EQ(ss.str(), ">>Number of monsters killed: 1\n>>Number of items: 3\n>>Items in inventory: \n\n[1] Potion\nUses: 3\n\n[2] Potion\nUses: 3\n\n[3] Potion\nUses: 3\n");
        delete player;
    }


//TestUpgrade Suite
    TEST(TestUpgrade, WarriorStat)
    {
        Character* player = new Character();
        std::istringstream iss("w");
        menuOp = read(iss);
        CharacterCreation(player);
        Upgrade(player);
        EXPECT_EQ(player -> getStrength(), 15);
        delete player;
    }

    TEST(TestUpgrade, KnightStat)
    {
        Character* player = new Character();
        std::istringstream iss("k");
        menuOp = read(iss);
        CharacterCreation(player);
        Upgrade(player);
        EXPECT_EQ(player -> getDefense(), 10);
        delete player;
    }

    TEST(TestUpgrade, HunterStat)
    {
        Character* player = new Character();
        std::istringstream iss("h");
        menuOp = read(iss);
        CharacterCreation(player);
        Upgrade(player);
        EXPECT_EQ(player -> getSpeed(), 10);
        delete player;
    }


//TestEnchant Suite
    TEST(TestEnchant, Sword)
    {
        Character* player = new Character();
        player -> setAttackType(new WarriorAttack());
        player -> setAttackString("Warrior");
        player -> storeItem(new Sword());
        Victory(player, 0);
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Fiery Sword\nDamage: 9(5+4)\nWeapon Type: Sword");
        delete player;
    }

    TEST(TestEnchant, Bow)
    {
        Character* player = new Character();
        player -> setAttackType(new KnightAttack());
        player -> setAttackString("Knight");
        player -> storeItem(new Bow());
        Victory(player, 0);
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Fiery Bow\nDamage: 8(5+3)\nWeapon Type: Bow");
        delete player;
    }

    TEST(TestEnchant, Dagger)
    {
        Character* player = new Character();
        player -> setAttackType(new HunterAttack());
        player -> setAttackString("Hunter");
        player -> storeItem(new Dagger());
        Victory(player, 0);
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Fiery Dagger\nDamage: 7(5+2)\nWeapon Type: Dagger");
        delete player;
    }


//TestNewItem Suite
    TEST(TestNewItem, T1Sword)
    {
        Character* player = new Character();
        player -> setAttackType(new WarriorAttack());
        player -> setAttackString("Warrior");
        NewItem(player, 0);
        player -> changeWeapon();
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Bronze Sword\nDamage: 7\nWeapon Type: Sword");
        delete player;
    }

    TEST(TestNewItem, T2Bow)
    {
        Character* player = new Character();
        player -> setAttackType(new KnightAttack());
        player -> setAttackString("Knight");
        NewItem(player, 1);
        player -> changeWeapon();
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Bamboo Bow\nDamage: 9\nWeapon Type: Bow");
        delete player;
    }

    TEST(TestNewItem, T3Dagger)
    {
        Character* player = new Character();
        player -> setAttackType(new HunterAttack());
        player -> setAttackString("Hunter");
        NewItem(player, 2);
        player -> changeWeapon();
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Gold Dagger\nDamage: 11\nWeapon Type: Dagger");
        delete player;
    }


//TestBattle Suite
    TEST(TestBattle, TestWin)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        player -> storeItem(new Potion());
        player -> setStrength(100);
        bool gameOver = battle(player, enemy);
        EXPECT_EQ(0, enemy -> getHealth());
        EXPECT_EQ(false, gameOver);
        delete player;
        delete enemy;
    }

    TEST(TestBattle, TestLoss)
    {
        srand(time(0));
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        player -> storeItem(new Potion());
        player -> setSpeed(-5);
        enemy -> setStrength(105);
        bool gameOver = battle(player, enemy);
        EXPECT_EQ(0, player -> getHealth());
        EXPECT_EQ(true, gameOver);
        delete player;
        delete enemy;
    }


//TestGameOver Suite
TEST(TestGameOver, Win)
{
    Character* player = new Character();
    Monster* enemy = new Monster();
    player -> setAttackType(new WarriorAttack());
    player -> setAttackString("Warrior");
    player -> storeItem(new Potion());
    player -> setStrength(100);
    bool game = gameOver(player, enemy, 0);
    EXPECT_EQ(0, enemy -> getHealth());
    EXPECT_EQ(false, game);
    delete player;
    delete enemy;
}

TEST(TestGameOver, Loss)
{
    srand(time(0));
    Character* player = new Character();
    Monster* enemy = new Monster();
    player -> setAttackType(new WarriorAttack());
    player -> setAttackString("Warrior");
    player -> storeItem(new Potion());
    player -> setSpeed(-5);
    enemy -> setStrength(105);
    bool game = gameOver(player, enemy, 1);
    EXPECT_EQ(0, player -> getHealth());
    EXPECT_EQ(true, game);
    delete player;
    delete enemy;
}


#endif
