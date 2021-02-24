#ifndef __ATTACKS_HPP__
#define __ATTACKS_HPP__

#include "entities.hpp"

class Character;

class CharacterAttack
{
   public:
	virtual ~CharacterAttack() = default;
	virtual int attack(Character*) = 0;
};

class WarriorAttack: public CharacterAttack
{
   public:
	int attack(Character*);
};

class KnightAttack: public CharacterAttack
{
   public:
        int attack(Character*);
};

class HunterAttack: public CharacterAttack
{
   public:
        int attack(Character*);
};

#endif //__ATTACKS_HPP__
