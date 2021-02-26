#include "seqMan.hpp"

seqMan::seqMan(std::string seq) {
    if(seq != "$X"){
        dia.open(seq.c_str(), std::ifstream::in);
        if(!dia.is_open()){throw;}
    }
}

seqMan::~seqMan() {dia.close();}

void seqMan::file(std::string seq) {
    if(seq == "$X") {return;}
    if(dia.is_open()){dia.close();}
    dia.open(seq.c_str(), std::ifstream::in);
    if(!dia.is_open()){throw;}
}

void seqMan::sequence(std::string input, std::ostream& out){
    if(input == "$X"){out << "No Input"; return;}
    if(input == "#"){numLines.clear(); lines.clear();}
    std::string hold;
    std::stringstream strHold;
    int intHold; int totalnumLines = 0;
    while(getline(dia, hold)){
        strHold << hold;
        if(strHold >> hold){
            if(hold == input){
                clear();
                while(strHold >> intHold){
                    numLines.push_back( intHold );
                    totalnumLines += intHold;
                }
                for(int i = 0; i < totalnumLines; ++i){
                    getline(dia, hold); lines.push_back( hold );
                }
                return;
            }
        hold.clear();
        strHold.str(std::string());
    }}
    throw;
}

void seqMan::OUT(int seq, std::ostream& out) {
    if( seq != -1 && seq < numLines.size() ){ currSectSeq = seq; }
    int output = 0;
    if(is_empty()){return;}
    if(currSectSeq == numLines.size()) { currSectSeq = 0; }
    for(int i = 0; i < currSectSeq; ++i){ output += numLines.at(i); }
    for(int i = output; i < output + numLines.at(currSectSeq); ++i){ out << lines.at(i) << std::endl; }
    ++currSectSeq;
}

void seqMan::clear() { numLines.clear(); lines.clear(); currSectSeq = 0; }
bool seqMan::is_empty(){ return !lines.size(); }
int seqMan::currSeq(){ return currSectSeq; }