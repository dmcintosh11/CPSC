//Main file to run checking the syntax of multiple files
#include "LinkedList.h"
#include "FileProcessor.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

  //Ensures only file name is input in command line
  if(argc != 2) {
    cout << "Enter only the file name as a command line argument" << endl;
    return -1;
  }

  //Gets file name from command line
  string fileName = argv[1];

  //Creates object to run processing the file
  FileProcessor* f = new FileProcessor();

  //Process input file
  f->processFile(fileName);


  return 0;
}
