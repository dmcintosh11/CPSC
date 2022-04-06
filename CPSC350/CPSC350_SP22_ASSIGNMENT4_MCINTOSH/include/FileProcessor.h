//Header file for FileProcessor.cpp

#if !defined(FILEPROCESSOR_H)
#define FILEPROCESSOR_H

#include <string>
#include "SyntaxChecker.h"

class FileProcessor {
  public:
    //Constructor Destructor
    FileProcessor();
    ~FileProcessor();
    //Handles taking the fileName as input and converting file into a string and processing user input
    void processFile(std::string in);
  private:
    //SyntaxChecker object
    SyntaxChecker* checker;
    //Auxilary function to make processFile simpler
    std::string readFile(std::string in);
};

#endif
