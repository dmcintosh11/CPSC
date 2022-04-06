//Implementation of FileProcessor.h to handle file processing
#include "FileProcessor.h"
#include <fstream>
#include <iostream>

//Constructor
FileProcessor::FileProcessor() {
  checker = new SyntaxChecker();
}

//Destructor
FileProcessor::~FileProcessor() {
  delete checker;
}

//Method to read a specified input file and handle user input to check multiple files after
void FileProcessor::processFile(std::string in) {
  std::string fileString = readFile(in);

  std::string cont = "n"; //User input of checking another file or not

  //Continues asking user for next file to process as long as the input files have no delimiter syntax errors
  while(checker->processInput(fileString)) {
    std::cout << "Delimiter syntax is correct!" << std::endl;
    std::cout << "Would you like to analyze another file? (Enter y/n)" << std::endl;
    std::cin >> cont;
    //If user doesn't want to continue processing files it exits program
    if(cont != "y") {
      return;
    }
    //This block takes user input and reads the new file
    std::cout << "Enter the file" << std::endl;
    std::cin >> in;
    fileString = readFile(in);
  }
}

//Auxilary function that takes in a fileName and converts that given file into a string and returns it
std::string FileProcessor::readFile(std::string in) {
  std::ifstream inFile(in);
  std::string words;
  std::string fileString = "";

  //Adds to output string until it reaches the end of the file
  while(getline(inFile, words)) {
    fileString += words;
    fileString += "\n";
  }

  return fileString;
}
