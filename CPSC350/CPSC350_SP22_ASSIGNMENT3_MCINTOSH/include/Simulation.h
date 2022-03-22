//Header file for Simulation.cpp
//Used to create objects needed to run the game
#if !defined SIMULATION_H
#define SIMULATION_H

#include "GameMode.h"
#include <string>

class Simulation {
public:
  //Constructors and destructor
  Simulation();
  ~Simulation();
  void run(); //Runs game processes
  void printToFile(); //Used to print output to a file

private:
  GameMode* game;
  string outputStyle; //Determines how to output the information
};

#endif
