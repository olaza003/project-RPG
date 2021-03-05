#include "seqMan.hpp"

seqMan::seqMan(std::string seq) {
    if(seq != "$X"){
        filename = seq;
    }
}

seqMan::~seqMan() {clear();}

void seqMan::file(std::string seq) {
    if(seq == "$X") {return;}
    filename = seq;
    clear();
}

void seqMan::sequence(std::string input, std::ostream& out){
    if(input == "$X"){out << "No Input" << std::endl; return;}
    if(dia.is_open()){dia.close();}
    dia.open(filename.c_str(), std::ifstream::in);
    if(!dia.is_open()){throw std::invalid_argument("Could not locate file");}
    clear();
    std::string hold;
    std::stringstream strHold;
    int intHold; int totalnumLines = 0;
    while(getline(dia, hold)){
        strHold << hold;
        if(strHold >> hold){
            if(hold == input){
                if(strHold >> intHold){
                    do{
                        numLines.push_back( intHold );
                        totalnumLines += intHold;
                    } while(strHold >> intHold);

                    for(int i = 0; i < totalnumLines; ++i){
                        getline(dia, hold); lines.push_back( hold );
                    }
                }
                else {
                    std::string hvyHold;
                    strHold.clear(); strHold.str(std::string()); hold.clear();
                    while(getline(dia, hold)){
                        hvyHold = hold;
                        strHold << hold;
                        if(strHold >> hold){
                            if(hold.at(0) == '['){break;}
                        }
                        lines.push_back( hvyHold ); ++totalnumLines;
                        hold.clear();
                        strHold.clear();
                        strHold.str(std::string());
                    }
                    numLines.push_back( totalnumLines );
                }
                dia.close();
                clearBad();
                return;
        }}
        hold.clear();
        strHold.clear();
        strHold.str(std::string());
    }
    out << "CANNOT FIND \"" << input << "\" IN FILE: \"" << filename << "\"" << std::endl; 
    errorFlag = true;
    dia.close();
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

std::string seqMan::strOUT(int seq) {
    std::string out;
    if( seq != -1 && seq < numLines.size() ){ currSectSeq = seq; }
    int output = 0;
    if(is_empty()){return "";}
    if(currSectSeq == numLines.size()) { currSectSeq = 0; }
    for(int i = 0; i < currSectSeq; ++i){ output += numLines.at(i); }
    for(int i = output; i < output + numLines.at(currSectSeq); ++i){ out += lines.at(i) + '\n'; }
    ++currSectSeq;

    return out;
}

bool seqMan::bad() const {return errorFlag;}
void seqMan::clearBad() {errorFlag = false;}
void seqMan::clear() { numLines.clear(); lines.clear(); currSectSeq = 0; errorFlag = 0;}
bool seqMan::is_empty(){ return !lines.size(); }
int seqMan::currSeq() const { return currSectSeq; }
std::string seqMan::getCWF() const {return filename;}