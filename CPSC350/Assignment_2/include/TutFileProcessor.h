//Header file for FileProcessor.cpp

#if !defined(TUTFILEPROCESSOR_H)
#define TUTFILEPROCESSOR_H

#include <string>
#include "TutModel.h"

class TutFileProcessor {
  public:
    TutFileProcessor();
    ~TutFileProcessor();
    void processFile(std::string in, std::string out);
  private:
    TutModel m;
};

#endif
