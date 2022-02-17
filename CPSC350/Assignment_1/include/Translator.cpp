//

#include "Model.h"
#include "Translator.h"

Translator::Translator() {

}

Translator::~Translator() {

}

//Method that takes a string input and outputs the translation into Tutnese as a string
std::string Translator::translateEnglishWord(std::string s) {
  std::string result = "";
  char next;
  char current;
  for(int i = 0; i < s.length() - 1; ++i) {
    current = s[i];
    next = s[i+1];
    if(next == current) {
      result.append(m.translateDoubleCharacter(current));
      ++i;
    } else {
      result.append(m.translateSingleCharacter(current));
    }

  }

  if(s[(s.length() - 1)] != s[(s.length() - 2)]) {
    result.append(m.translateSingleCharacter(s[(s.length() - 1)]));
  }

  return result;
}

//Method that abstractly uses translateEnglishWord() to take an input string and output a string of the Tutnese translation
std::string Translator::translateEnglishSentence(std::string s) {
  return translateEnglishWord(s);
}
