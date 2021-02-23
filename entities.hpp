#ifndef __ENTITIES_HPP__
#define __ENTITIES_HPP__

#include "attacks.hpp"

class Character;
class Monster;

class Entity
{
   protected:
	int health;
	int strength;
   public:
	virtual ~Entity() = default;
	
	void setHealth(int damage)
        {
                health = health - damage;
        }

        int getHealth()
        {
                return health;
        }


	void setStrength(int newStrength)
	{
		strength = newStrength;
	}

	int getStrength()
	{
		return strength;
	}

	virtual void attack(Character* player, Monster* enemy) = 0;
};

class Monster: public Entity
{
   public:
	Monster(h, st)
	{
		health = h;
		strength = st;
	}

        void attack(Character* player, Monster* enemy)
	{
		player -> setHealth(enemy -> getStrength());
	}
};

class Character: public Entity
{
   private:
        int defense;
        int speed;
	CharacterAttack* selectAttack = nullptr;
   public:
	Character()
	{
		health = 100;
		strength = 10;
		defense = 5;
		speed = 5;
	}

	~Character()
	{
		delete selectAttack;
	}

        void setDefense(int newDefense)
        {
                defense = newDefense;
        }

        int getDefense()
        {
                return defense;
        }

	void setSpeed(int newSpeed)
        {
                speed = newSpeed;
        }

        int getSpeed()
        {
                return speed;
        }

	void setAttack(CharacterAttack* attackType)
	{
		delete selectAttack;
		selectAttack = attackType;
	}

	CharacterAttack* getAttack()
	{
		return selectAttack;
	}

        void attack(Character* player, Monster* enemy)
	{
		selectAttack = player -> getAttack();
		enemy -> setHealth(selectAttack -> attack(player, enemy);
	}
};

#endif //__ENTITIES_HPP__
