#include "entities.hpp"
#include "attacks.hpp"
#include <iostream>

using namespace std;

int main()
{
	Entity* player = new Character();
	Entity* enemy = new Monster(50,10);
	player -> setAttack(new WarriorAttack);
	player -> attack(player, enemy);

	cout << enemy -> getHealth();

	return 0;
}
