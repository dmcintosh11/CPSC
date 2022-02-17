//Header file for Model.cpp

#if !defined(MODEL_H)
#define MODEL_H

#include <string>

class Model {
public:
  Model();
  ~Model();
  std::string translateSingleCharacter(char c);
  std::string translateDoubleCharacter(char c);
};

#endif
