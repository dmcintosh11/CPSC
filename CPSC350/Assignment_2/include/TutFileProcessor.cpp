//Class used to process file I/O

#include "TutFileProcessor.h"
#include <fstream>

TutFileProcessor::TutFileProcessor() {

}

TutFileProcessor::~TutFileProcessor() {

}

//Method to read a specified input file and output the Tutnese translation in a txt file
void TutFileProcessor::processFile(std::string in, std::string out) {
  std::ifstream inFile(in);
  std::string words;


  std::ofstream outFile;
  outFile.open(out);

  while(getline(inFile, words)) {
    outFile << m.translatePhrase(words) << "\n";
  }

  outFile.close();
}
