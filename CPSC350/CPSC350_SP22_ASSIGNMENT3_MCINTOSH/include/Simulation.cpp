#include "Simulation.h"
#include "GameMode.h"
#include "ModeClassic.h"
#include "ModeDoughnut.h"
#include "ModeMirror.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>

using namespace std;

//Constructor to get user input for preferences and create proper GameMode object
Simulation::Simulation() {

  //Prompts for how the user would like the output
  cout << "How would you like the output?" << endl;

  while(outputStyle != "1" && outputStyle != "2" && outputStyle != "3") {
    cout << "Enter 1 for a pause between generations; 2 for pressing enter between generations; 3 for outputting to a file" << endl;
    cin >> outputStyle;
  }

  //Prompts user for which game mode to run
  cout << "What boundary mode would you like?" << endl;
  string bound = "";
  while(bound != "1" && bound != "2" && bound != "3") {
    cout << "Enter 1 for Classic; 2 for Doughnut; 3 for Mirror" << endl;
    cin >> bound;
  }

  //Creates proper GameMode object based on choice selected by user
  if(bound == "1") {
    game = new ModeClassic();
  } else if(bound == "2") {
    game = new ModeDoughnut();
  } else {
    game = new ModeMirror();
  }


}

//Destructor
Simulation::~Simulation() {
  delete game;
}

//Main function to run the game
void Simulation::run() {
  cin.get();

  if(outputStyle == "3") {
    printToFile();
  } else {
    cout << 0 << endl;
    game->printCurGen();

    cout << "Generation #: " << game->getGen() << endl;
    game->printCurGen();

    game->processGen();




    while(!game->isStable()) {
      if(outputStyle == "1") {
        usleep(1000000);
      } else if(outputStyle == "2") {
        cin.get();
      }
      cout << "Generation #: " << game->getGen() << endl;
      game->printCurGen();

      game->processGen();


    }
  }

  cout << "Press \"enter\" to exit the program: " << endl;

  cin.get();
}

//Used to direct output into an output file
void Simulation::printToFile() {
  //Prompts for output file name
  string out = "";
  string fileName;
  cout << "Enter the name of the output file: " << endl;
  cin >> fileName;

  //Creates output file object
  ofstream outFile (fileName);
  //Checks if file opened properly
  if (outFile.is_open())
  {
    outFile << 0 << endl;
    outFile << game->curGenToString();

    outFile << "Generation #: " << game->getGen() << endl;
    outFile << game->curGenToString();

    game->processGen();


    //Continues  processing repeatedly until the game stabilizes
    while(!game->isStable()) {
      outFile << "Generation #: " << game->getGen() << endl;
      outFile << game->curGenToString();

      game->processGen();


    }

    outFile.close();
  }
}
