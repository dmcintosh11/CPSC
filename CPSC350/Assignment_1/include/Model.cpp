//Class to translate letters in English to the correspondnding Tutnese phrase

#include "Model.h"

  Model::Model() {

  }

  Model::~Model() {

  }

  //Method used to translate a single char input intp the corresponding Tutnese phrase as a string
  std::string Model::translateSingleCharacter(char c) {
    switch(c) {
      case 'b':
        return "bub";
      case 'B':
        return "Bub";
      case 'c':
        return "cash";
      case 'C':
        return "Cash";
      case 'd':
        return "dud";
      case 'D':
        return "Dud";
      case 'f':
        return "fuf";
      case 'F':
        return "Fuf";
      case 'g':
        return "gug";
      case 'G':
        return "Gug";
      case 'h':
        return "hash";
      case 'H':
        return "Hash";
      case 'j':
        return "jay";
      case 'J':
        return "Jay";
      case 'k':
        return "kuck";
      case 'K':
        return "Kuck";
      case 'l':
        return "lul";
      case 'L':
        return "Lul";
      case 'm':
        return "mum";
      case 'M':
        return "Mum";
      case 'n':
        return "nun";
      case 'N':
        return "Nun";
      case 'p':
        return "pub";
      case 'P':
        return "Pub";
      case 'q':
        return "quack";
      case 'Q':
        return "Quack";
      case 'r':
        return "rug";
      case 'R':
        return "Rug";
      case 's':
        return "sus";
      case 'S':
        return "Sus";
      case 't':
        return "tut";
      case 'T':
        return "Tut";
      case 'v':
        return "vuv";
      case 'V':
        return "Vuv";
      case 'w':
        return "wack";
      case 'W':
        return "Wack";
      case 'x':
        return "ex";
      case 'X':
        return "Ex";
      case 'y':
        return "yub";
      case 'Y':
        return "Yub";
      case 'z':
        return "zub";
      case 'Z':
        return "Zub";
      default:
        std::string s;
        s.push_back(c);
        return s;
    }

  }

  //Method to translate two same characters in a row (only one of the chars as an input) into the corresponding Tutnese phrase as a string
  std::string Model::translateDoubleCharacter(char c) {
    char lower = tolower(c);
    if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
      if(isupper(c)) {
        std::string s = "Squat";
        s.push_back(lower);
        return s;
      } else {
        std::string s = "squat";
        s.push_back(c);
        return s;
      }

    } else {
      if(isupper(c)) {
        std::string s = "Squa" + translateSingleCharacter(lower);
        return s;
      } else {
        std::string s = "squa" + translateSingleCharacter(lower);
        return s;
      }
    }
  }
