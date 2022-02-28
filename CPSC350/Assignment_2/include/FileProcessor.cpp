#include "FileProcessor.h"
#include <fstream>
#include <iostream>

FileProcessor::FileProcessor() {

}

FileProcessor::~FileProcessor() {

}

//Method to read a specified input file and output the Tutnese translation in a txt file
void FileProcessor::processFile(std::string in, std::string out) {
  std::ifstream inFile(in);
  std::string words;


  std::ofstream outFile;
  outFile.open(out);

  while(getline(inFile, words)) {
    if(!words.empty()) {
      outFile << t.translateEnglishSentence(words) << "\n";
    } else {
      outFile << "\n";
    }
  }

  outFile.close();

  return;
}
