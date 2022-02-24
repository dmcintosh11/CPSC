//Header file for FileProcessor.cpp

#if !defined(FILEPROCESSOR_H)
#define FILEPROCESSOR_H

#include <string>
#include "Translator.h"

class FileProcessor {
  public:
    FileProcessor();
    ~FileProcessor();
    void processFile(std::string in, std::string out);
  private:
    Translator t;
};

#endif
