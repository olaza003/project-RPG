#ifndef __ATTACKS_HPP__
#define __ATTACKS_HPP__

#include "entities.hpp"

class CharacterAttack
{
   public:
	virtual ~CharacterAttack() = default;

	virtual int attack(Character* player, Monster* enemy) = 0;

};

class WarriorAttack: public CharacterAttack
{
   public:
	int attack(Character* player, Monster* enemy)
	{
		int damage = player -> getStrength();
		damage += enemy -> getStrength();
		return damage;
	}
};

class KnightAttack: public CharacterAttack
{
   public:
        int attack(Character* player, Monster* enemy)
        {
                int damage = player -> getStrength();
                damage += player -> getDefense();
                return damage;
        }
};

class HunterAttack: public CharacterAttack
{
   public:
        int attack(Character* player, Monster* enemy)
        {
                int damage = player -> getStrength();
                damage += player -> getSpeed();
                return damage;
        }
};

#endif //__ATTACKS_HPP__
