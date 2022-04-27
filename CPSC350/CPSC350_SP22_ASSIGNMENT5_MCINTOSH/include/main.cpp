//Main file to run project
#include "Simulation.h"
#include "Window.h"
#include "Student.h"
#include "GenQueue.h"
#include <iostream>

int main(int argc, char** argv) {

  //Ensures only file name is input in command line
  if(argc != 2) {
    cout << "Enter only the file name as a command line argument" << endl;
    return -1;
  }

  //Gets file name from command line
  string fileName = argv[1];

  //Creates pointer to simulatino object
  Simulation* s = new Simulation("test.txt");

  //Runs simulation
  s->run();

  //Deletes simulation
  delete s;





  return 0;
}
