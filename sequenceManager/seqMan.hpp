#ifndef __SEQMAN_HPP__
#define __SEQMAN_HPP__
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class seqMan {
    private:
        std::vector<int> numLines;
        std::vector<std::string> lines;
        int currSectSeq = 0;
        std::ifstream dia;
    public:
            //No string input or text file location results in the constructor not attempting to open a file. The class remains uninitialized. Use file() to initialize post-construction.
        seqMan(std::string seq = "$X"); 
            //Just closes the std::ifstream. Nothing fancy.
        ~seqMan();
            //Used to change the text file post-construction.
        void file(std::string seq = "$X");
            //Clears numLines, lines, and resets curreSectSeq to zero.
        void clear();
            //Searches within the open text file for any line that begins the input. The input must be formatted as "[<INSERT LABEL>]" followed by the line numbers of subsequences. This line is called the Label.
            //These subsequences predefine what outputs in OUT(). Subsequences follow the form "[LABEL] # # # # ..." where the # is the number of lines per subsequence.
            //When added together, the total number of lines for # must equal to the total number of lines belonging to the sequence after the Label.
        void sequence(std::string input = "$X", std::ostream& out = std::cout);
            //Prints the current subsequence. Each recurrent call outputs the following subsequence, and once it reaches the last subsequence, circles back to the first one.
            //Passing an index to one of the subsequences prints out that subsequence, and will set currSectSeq to that passed in index
        void OUT(int seq = -1, std::ostream& = std::cout);
            //Checks if lines.size() == 0 or otherwise the class would have no output for OUT()
        bool is_empty();
            //Returns the current value of currSectSeq
        int currSeq();
};

#endif