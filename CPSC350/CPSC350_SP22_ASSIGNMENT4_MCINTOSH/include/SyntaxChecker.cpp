//Implementation of SyntaxChecker.h that handles processing proper delimiter syntax of a given string
#include "SyntaxChecker.h"
#include <string>
#include <iostream>

//Constructor
SyntaxChecker::SyntaxChecker() {
  delimiters = new GenStack<char>();
  lineCount = 1;
}

//Destructor
SyntaxChecker::~SyntaxChecker() {
  delete delimiters;
}

//Iterates through the input string and returns true if the string has proper delimiter syntax
bool SyntaxChecker::processInput(std::string in) {
  char lastOut = ' '; //Char of last char popped from stack
  char current = ' '; //Current char in the input string
  bool inString = false; //bool for if the current index of the input string is inside of a string so that it ignores those delimietrs

  //Iterates through each char in the input string
  for(int i = 0; i < in.size(); ++i) {
    //Gets char at current index
    current = in.at(i);
    //Checks if current char is a quotation
    if(current == '\"') {
      inString = !inString; //Flips inString bool
    }
    //Checks if a new line is being read
    if(current == '\n') {
      lineCount++; //Increments lineCount
    } else if (!inString){ // If it is not a new line and not inside a string
        if(isDelimiter(current)) { //If current char is a delimiter

          if(isOpening(current)) { //Checks if current char is an opening delimiter
            delimiters->push(current); //Pushes opening delimiters onto stack
          } else { //If current char is a closing delimiter
            if(delimiters->isEmpty()) { //If there aren't opening delimiters in the stack there is an error
              //Gives error message
              std::cout << "Line: " << lineCount << " encountered closing delimiter: " << current << " without opening delimiter: " << expectedOpener(current) << std::endl;
              return false; //Tells FileProcessor that there was an error in delimiter syntax
            }
            //Gets the last opening delimiter from stack
            lastOut = delimiters->pop();

            if(!isMatch(lastOut, current)) { //If the delimiters aren't a match then there is an error
              //Gives error message
              std::cout << "Line: " << lineCount << "; expected " << expectedCloser(lastOut) << " and found " << current << std::endl;

              return false;//Tells FileProcessor that there was an error in delimiter syntax
            }
          }
        }
    }

  }

  //Checks if the stack still has remaining delimiters
  if(!delimiters->isEmpty()) {
    std::cout << "Reached end of file: missing " << expectedCloser(delimiters->pop()) << std::endl;
    return false;
  }

  //Resets lineCount for next file to be read
  lineCount = 1;
  //Empties the stack to reset for next file to be read
  delimiters->empty();
  //File has all correct delimiter syntax
  return true;
}

//Returns whether the given char is a delimiter or not
bool SyntaxChecker::isDelimiter(char cur) {
  return (cur == ')' || cur == ']' || cur == '}' || isOpening(cur));
}

//Returns whether the input delimiter is an opening one or not
bool SyntaxChecker::isOpening(char cur) {
  return (cur == '(' || cur == '[' || cur == '{');
}

//Returns whether the two input char delimiters are mathcing, for example () or []
bool SyntaxChecker::isMatch(char opener, char closer) {
  if(opener == '(') {
    return closer == ')';
  }
  if(opener == '[') {
    return closer == ']';
  }
  if(opener == '{') {
    return closer == '}';
  }
  return false;
}

//Returns the matching delimiter for the input opening delimiter
char SyntaxChecker::expectedCloser(char opener) {
  if(opener == '(') {
    return ')';
  }
  if(opener == '[') {
    return ']';
  }
  return '}';

}

//Returns the matching delimiter for the input closing delimiter
char SyntaxChecker::expectedOpener(char closer) {
  if(closer == ')') {
    return '(';
  }
  if(closer == ']') {
    return '[';
  }
  return '{';

}
