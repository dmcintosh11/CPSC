//Header file for Model.cpp

#if !defined(TUTMODEL_H)
#define TUTMODEL_H

#include <string>
#include "Model.h"

class TutModel {
public:
  TutModel();
  ~TutModel();
  std::string translatePhrase(std::string s);
private:
  Model m;
};

#endif
