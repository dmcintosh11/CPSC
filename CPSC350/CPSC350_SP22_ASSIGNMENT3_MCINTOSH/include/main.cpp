#include <iostream>
#include <random>
#include "GameBoard.h"
#include "GameMode.h"
#include "ModeClassic.h"
#include "Simulation.h"

using namespace std;

int main() {

  //Creates simulation object
 Simulation* sim = new Simulation();

 //Runs game
 sim->run();

 //Deallocates memory
 delete sim;



  return 0;
}
