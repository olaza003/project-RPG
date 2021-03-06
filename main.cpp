#include <iostream>
#include "story.hpp"
#include "sequenceManager/seqMan.hpp"
#include "items/protoITEMS/protoITEMS.hpp"
#include "items/protoItems/protoENCHANT.hpp"

seqMan dia;
string userInput;

void quick_intro(Character*);
vector<Monster*> mobs; //fill with pre-generated Monsters
vector<string> preFightDia;

int main() {

    Character player;
    quick_intro(&player);

    int floorCounter = 0;

    while(floorCounter < 5){
        dia.sequence(preFightDia.at(floorCounter));

        bool check = battle(&player, mobs.at(floorCounter));

    }
    

    return 0;
}

string whichSequence(int val)
{
    if(val == 0) return "[SEQ_ONE]";
    else if(val == 1) return "[SEQ_TWO]";
    else if(val == 2) return "[SEQ_THREE]";
    else if(val == 3) return "[SEQ_FOUR]";
}

void quick_intro(Character* player){
    dia.file("Dialogue/Introduction.txt"); dia.sequence("[INTRODUCTION]");
    dia.OUT();
    //cin >> userInput; player.setName(userInput);
    dia.OUT();
    CharacterCreation(player);
    dia.OUT();
    //output list of weapons
    //cin >> item choices
    dia.OUT();
    //player's choice outputs
}
