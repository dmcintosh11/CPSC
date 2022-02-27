//Class to translate letters in English to the correspondnding Tutnese phrase

#include "TutModel.h"
#include <iostream>

  TutModel::TutModel() {

  }

  TutModel::~TutModel() {

  }

  //Takes a string as input and uses Model.cpp methods to find the mathcing character in English to Tutnese phrases and outputs translation from Tutnese to English
  std::string TutModel::translatePhrase(std::string s) {
    std::string translation = "";
    for(char c = 'A'; c <= 'z'; ++c) {

      if(s.length() > 0) {
        std::string test = m.translateSingleCharacter(c);
        //Checks to see if string 's' starts with a space or punctuation
        if(s.at(0) == ' ' || ispunct(s.at(0))) {
          translation += s.at(0);
          s = s.substr(1);
          c = 'A' - 1;
        }
          //Checks to see if the English to Tut translation of char 'c' is at the beginning of string 's'
          else if(s.find(test) == 0) {
            translation += c; //Adds English translation of phrase to string 'translation'
            s = s.substr(test.length()); //Shortens string 's' to everything after the phrase that was just translated
            c = 'A' - 1; //Resets for loop to go back through the alphabet
          } 
          //Checks to see if the next phrase is a double letter translation and if so, appends the English characters to the end of string 'translation'
          else {
            std::string testDouble = m.translateDoubleCharacter(c);
            if(s.find(testDouble) == 0) {
              translation += c;
              translation += c;
              s = s.substr(testDouble.length());
              c = 'A' - 1;

          }
        }

      }

    }

    return translation;
  }
