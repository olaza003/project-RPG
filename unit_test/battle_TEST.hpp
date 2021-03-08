#ifndef __BATTLE_TEST_HPP__
#define __BATTLE_TEST_HPP__

#include <iostream>
#include "../entities.hpp"
#include "../attacks.hpp"
#include "../items/protoITEMS/protoITEMS.hpp"
#include "../items/protoITEMS/protoENCHANT.hpp"
#include "../story.hpp"


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
        player -> storeItem(new Potion());
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
        player -> storeItem(new Potion());
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


//TestReport Suite
    TEST(TestReport, FloorZero0)
    {
        Character* player = new Character();
        std::stringstream ss;
        Report(player, 0, ss);
        EXPECT_EQ(ss.str(), "Number of monsters killed: 0\nNumber of items: 0\n>>INVENTORY EMPTY\n");
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
        EXPECT_EQ(ss.str(), "Number of monsters killed: 6\nNumber of items: 3\n\n[1] Sword\nDamage: 4\nWeapon Type: Sword\n[2] Bow\nDamage: 3\nWeapon Type: Bow\n[3] Dagger\nDamage: 2\nWeapon Type: Dagger\n");
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
        EXPECT_EQ(ss.str(), "Number of monsters killed: 1\nNumber of items: 3\n\n[1] Potion\nUses: 3\n[2] Potion\nUses: 3\n[3] Potion\nUses: 3\n");
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
        EXPECT_EQ(player -> getStrength(), 13);
        delete player;
    }

    TEST(TestUpgrade, KnightStat)
    {
        Character* player = new Character();
        std::istringstream iss("k");
        menuOp = read(iss);
        CharacterCreation(player);
        Upgrade(player);
        EXPECT_EQ(player -> getDefense(), 8);
        delete player;
    }

    TEST(TestUpgrade, HunterStat)
    {
        Character* player = new Character();
        std::istringstream iss("h");
        menuOp = read(iss);
        CharacterCreation(player);
        Upgrade(player);
        EXPECT_EQ(player -> getSpeed(), 8);
        delete player;
    }


//TestEnchant Suite
    TEST(TestEnchant, NoWeapon)
    {
        Character* player = new Character();
        player -> setAttackType(new WarriorAttack());
        player -> setAttackString("Warrior");
        Victory(player);
        EXPECT_EQ(player -> getStrength(), 13);
        delete player;
    }

    TEST(TestEnchant, Potion)
    {
        Character* player = new Character();
        player -> setAttackType(new WarriorAttack());
        player -> setAttackString("Warrior");
        player -> storeItem(new Potion());
        Victory(player);
        EXPECT_EQ(player -> getStrength(), 13);
        delete player;
    }

    TEST(TestEnchant, Sword)
    {
        Character* player = new Character();
        player -> setAttackType(new WarriorAttack());
        player -> setAttackString("Warrior");
        player -> storeItem(new Sword());
        Victory(player);
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Fiery Sword. Damage: 9(5+4). Weapon Type: Sword.");
        delete player;
    }

    TEST(TestEnchant, Bow)
    {
        Character* player = new Character();
        player -> setAttackType(new WarriorAttack());
        player -> setAttackString("Warrior");
        player -> storeItem(new Bow());
        Victory(player);
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Fiery Bow. Damage: 8(5+3). Weapon Type: Bow.");
        delete player;
    }

    TEST(TestEnchant, Dagger)
    {
        Character* player = new Character();
        player -> setAttackType(new WarriorAttack());
        player -> setAttackString("Warrior");
        player -> storeItem(new Dagger());
        Victory(player);
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Fiery Dagger. Damage: 7(5+2). Weapon Type: Dagger.");
        delete player;
    }


//TestNewItem Suite
    TEST(TestNewItem, T1Sword)
    {
        Character* player = new Character();
        player -> setAttackType(new WarriorAttack());
        player -> setAttackString("Warrior");
        fillWeapons();
        NewItem(player, 0);
        player -> changeWeapon();
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Bronze Sword\nDamage: 9\nWeapon Type: Sword");
    }

    TEST(TestNewItem, T2Bow)
    {
        Character* player = new Character();
        player -> setAttackType(new KnightAttack());
        player -> setAttackString("Knight");
        fillWeapons();
        NewItem(player, 1);
        player -> changeWeapon();
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Bamboo Bow\nDamage: 13\nWeapon Type: Bow");
    }

    TEST(TestNewItem, T3Dagger)
    {
        Character* player = new Character();
        player -> setAttackType(new HunterAttack());
        player -> setAttackString("Hunter");
        fillWeapons();
        NewItem(player, 2);
        player -> changeWeapon();
        EXPECT_EQ(player -> getWeapon() -> getDescription(), "Gold Dagger\nDamage: 17\nWeapon Type: Dagger");
    }


//TestBattle Suite
    TEST(TestBattle, TestWin)
    {
        Character* player = new Character();
        Monster* enemy = new Monster();
        player -> setAttackType(new WarriorAttack());
        player -> storeItem(new Potion());
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
        player -> storeItem(new Potion());
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
    fillWeapons();
    player -> storeItem(new Potion());
    bool game = gameOver(player, enemy, 0);
    EXPECT_EQ(0, enemy -> getHealth());
    EXPECT_EQ(false, game);
    delete player;
    delete enemy;
}

TEST(TestGameOver, Loss)
{
    Character* player = new Character();
    Monster* enemy = new Monster();
    player -> setAttackType(new WarriorAttack());
    player -> setAttackString("Warrior");
    fillWeapons();
    player -> storeItem(new Potion());
    bool game = gameOver(player, enemy, 1);
    EXPECT_EQ(0, player -> getHealth());
    EXPECT_EQ(true, game);
    delete player;
    delete enemy;
}


#endif
