//Header file for SyntaxChecker.cpp
#if !defined(SYNTAXCHECKER_H)
#define SYNTAXCHECKER_H

#include <string>
#include "LinkedList.h"

class SyntaxChecker {
  public:
    //Constructor Destructor
    SyntaxChecker();
    ~SyntaxChecker();
    //Handles checking for delimiter syntax of input string
    bool processInput(std::string in); //returns false if syntax is incorrect
  private:
    //Stack of chars to store delimiters
    GenStack<char> *delimiters;
    //Tracks what line of the file the checker is on
    int lineCount;

    //Auxilary functions to help check delimiter properties
    bool isDelimiter(char cur);
    bool isOpening(char cur);
    bool isMatch(char opener, char closer);
    char expectedCloser(char opener);
    char expectedOpener(char closer);


};

#endif
