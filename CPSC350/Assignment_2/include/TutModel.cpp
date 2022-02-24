//Class to translate letters in English to the correspondnding Tutnese phrase

#include "TutModel.h"

  TutModel::TutModel() {

  }

  TutModel::~TutModel() {

  }

  std::string TutModel::translatePhrase(std::string s) {
    std::string translation = "";
    for(char c = 'A'; c <= 'z'; ++c) {
      if(s.length() > 0) {
        std::string test = m.translateSingleCharacter(c);
        if(s.find(test) == 0) {
          translation += c;
          s = s.substr(test.length() - 1);
          c = 'A' - 1;
        } else {
          std::string testDouble = m.translateDoubleCharacter(c);
          if(s.find(testDouble) == 0) {
            translation += (c + c);
            s = s.substr(testDouble.length() - 1);
            c = 'A' - 1;

          }
        }

      }

      return translation;
    }

    return translation;
  }
