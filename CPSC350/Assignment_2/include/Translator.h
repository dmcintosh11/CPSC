//Header file for Translator.cpp

#if !defined(TRANSLATOR_H)
#define TRANSLATOR_H

#include <string>
#include "Model.h"

class Translator {
public:
  Translator();
  ~Translator();
  std::string translateEnglishWord(std::string s);
  std::string translateEnglishSentence(std::string s);
private:
  Model m;

};

#endif
