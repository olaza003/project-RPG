#include "protoITEMS.hpp"
#include <iostream>
#include "../../entities.hpp"

class Entity;

void Potion::use (Entity* object)
{
    uses--;
    object ->setHealth (-20);  //use setHealth function which takes Damage   
    // we'll use negative instead to handle that
    std::cout << "Healed +20.\n";
}
