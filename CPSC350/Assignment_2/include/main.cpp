#include "TutModel.h"
#include "TutFileProcessor.h"
#include "FileProcessor.h"
#include <iostream>

int main(int argc, char** argv) {


  std::string input = argv[1];
  std::string output = argv[2];
  std::string lang = argv[3];


  if(lang.compare("E2T") == 0) {
    FileProcessor f;
    f.processFile(input, output);
  } else if(lang.compare("T2E") == 0){
    TutFileProcessor f;
    f.processFile(input, output);
  } else {
    std::cout << "Specify \"E2T\" or \"T2E\" as the third command line argument" << std::endl;
  }



  return 0;

}
