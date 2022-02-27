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
        if(s.at(0) == ' ' || ispunct(s.at(0))) {
          translation += s.at(0);
          s = s.substr(1);
          c = 'A' - 1;
        }
          else if(s.find(test) == 0) {
            translation += c;
            s = s.substr(test.length());
            c = 'A' - 1;
          } else {
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
