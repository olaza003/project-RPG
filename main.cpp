#include <iostream>
#include "story.hpp"
#include "sequenceManager/seqMan.hpp"
#include "items/protoITEMS/protoITEMS.hpp"
#include "items/protoItems/protoENCHANT.hpp"

void Setup();

seqMan dia;
string userInput;

void quick_intro(Character*);
vector<Monster*> mobs; //fill with pre-generated Monsters
vector<string> currSeqDia;
vector<string> preFightDia;
void preFightDialogue();
void postFightDialogue();
void closeGameHandle();

int main() {
    Setup();
    Character player;
    quick_intro(&player); //dia set to STORY_ONE.txt

    int floorCounter = 0;

    while(floorCounter < 3){
        dia.sequence( preFightDia.at(floorCounter) );
        preFightDialogue();

        gameOver( &player, mobs.at(floorCounter), floorCounter);

        ++floorCounter;
        postFightDialogue();
    }
    
    dia.sequence("[EPILOGUE]");
    dia.OUT();

    closeGameHandle();

    return 0;
}

void Setup(){
    mobs.push_back(new Monster());
    mobs.push_back(new Monster());
    mobs.push_back(new Monster());
    mobs.push_back(new Monster());
    mobs.push_back(new Monster());
    currSeqDia.push_back("[FLOOR_ONE]");
    currSeqDia.push_back("[FLOOR_TWO]");
    currSeqDia.push_back("[FLOOR_THREE]");
    currSeqDia.push_back("[FLOOR_FOUR]");
    currSeqDia.push_back("[FLOOR_FIVE]");
    preFightDia.push_back("[FLOOR_ONE_ENTER]");
    preFightDia.push_back("[FLOOR_TWO_ENTER]");
    preFightDia.push_back("[FLOOR_THREE_ENTER]");
    preFightDia.push_back("[FLOOR_FOUR_ENTER]");
    preFightDia.push_back("[FLOOR_FIVE_ENTER]");

}

void closeGameHandle(){}

void quick_intro(Character* player){
    dia.file("Dialogue/STORY_ONE.txt"); dia.sequence("[INTRODUCTION]");
    dia.OUT(); //ask for player name
    //cin >> userInput; player.setName(userInput);

    dia.OUT(); //ask for character class
    CharacterCreation(player);

    dia.OUT(); //ask for itens for player to take
    //output list of weapons
    //cin >> item choices

    dia.OUT(); //verify choices
    //player's choice outputs
}

void preFightDialogue(){

}