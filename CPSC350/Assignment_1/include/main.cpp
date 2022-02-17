#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
#include <iostream>

int main(int argc, char** argv) {

  std::string input = argv[1];
  std::string output = argv[2];

  FileProcessor f;
  f.processFile(input, output);


  return 0;

}
