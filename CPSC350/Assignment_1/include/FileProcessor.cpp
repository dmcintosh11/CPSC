//Class used to process file I/O

#include "FileProcessor.h"
#include <fstream>

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
    outFile << t.translateEnglishSentence(words) << "\n";
  }

  outFile.close();
}
