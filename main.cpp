#include <iostream>
#include "story.hpp"
#include "sequenceManager/seqMan.hpp"
#include "items/protoITEMS/protoITEMS.hpp"
#include "items/protoITEMS/protoENCHANT.hpp"

void Setup();

seqMan dia;
string userInput;

void quick_intro(Character*);
vector<Monster*> mobs; //fill with pre-generated Monsters
vector<string> currSeqDia;
vector<string> preFightDia;
std::string CharacterName;
void preFightDialogue(int);
void postFightDialogue(int);
void closeGameHandle();

int main() {
    srand(time(0));
    Setup();
    Character player;
    quick_intro(&player); //dia set to STORY_ONE.txt

    int floorCounter = 0;
    bool isGameOver;

    cin.clear();
    cin.ignore(1, '\n');

    while(floorCounter < 3){
        dia.sequence( preFightDia.at(floorCounter) );
        preFightDialogue(floorCounter);
        isGameOver = gameOver( &player, mobs.at(floorCounter), floorCounter);
        
        if(isGameOver){
            closeGameHandle();
            exit(0);
        }

        postFightDialogue(floorCounter);
        ++floorCounter;
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

void closeGameHandle(){
    for(int i = 0; i < mobs.size(); ++i){
        delete mobs.at(i);
    }
}

void quick_intro(Character* player){
    dia.file("Dialogue/STORY_ONE.txt"); dia.sequence("[INTRODUCTION]");
    dia.OUT(); //ask for player name
    cout << ">>ENTER CHARACTER NAME: "; getline(cin, CharacterName);

    dia.OUT(); //ask for character class
    CharacterCreation(player);

    //dia.OUT(); //ask for itens for player to take
    //output list of weapons
    //cin >> item choices

    //dia.OUT(); //verify choices
    //player's choice outputs
}

void preFightDialogue(int floor){
    string hold;
    for(int i = 0; i < 30; ++i){
        cout << "-----";
    } cout << endl;
    dia.sequence( preFightDia.at(floor) );
    for(int i = 0; i < dia.getNumSubSeq(); ++i){
        dia.OUT(); 
        cout << ">>::::PRESS ENTER TO CONTINUE::::<< "; getline(std::cin, hold);
    }
}

void postFightDialogue(int floor) {
    string hold;
    cin.clear();
    cin.ignore(1, '\n');
    for(int i = 0; i < 30; ++i){
        cout << "-----";
    } cout << endl;
    dia.sequence( currSeqDia.at(floor) );
    for(int i = 0; i < dia.getNumSubSeq(); ++i){
        dia.OUT(); 
        cout << ">>::::PRESS ENTER TO CONTINUE::::<< "; getline(std::cin, hold);
    }
}
