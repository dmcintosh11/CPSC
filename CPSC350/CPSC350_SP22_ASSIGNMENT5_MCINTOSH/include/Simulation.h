//Header file for Simulation.cpp to run the registrar and load the input file
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Student.h"
#include "Window.h"
#include "GenQueue.h"
#include <string>


using namespace std;

class Simulation {
public:
  //Constructors and destructor
  Simulation();
  Simulation(string fileName);
  ~Simulation();

  //Loads a file into the program and turns each int on every line
  void readFile(string inputFile);
  //Runs the registrar and iterates through the informatoin from the file to start it
  void run();

private:
  GenQueue<Student*>* line; //Queue of students
  Window* windows[20]; //Array of windows in the registrar
  DoublyLinkedList<int>* fileValues; //Values of every int on each line of the input file
  DoublyLinkedList<int>* studentWaits; //Values of the wait time for each student

  int numWindows; //Number of windows in the registrar
  int tick; //Holds time value and increments after each loop through the program
  ListNode<int>* cur; //The current node in fileValues to get information iteratively

  //Metrics
  int studentWaitCount;
  double avgStudentWait;
  double medianStudentWait;
  int maxStudentWait;
  int studOver10;
  double avgIdle;
  int maxIdle;
  int winOver5;

  void decrementStuds(); //Decrements student time needed
  bool registrarEmpty(); //Returns true if there are no students at the windows
  void calculateMetrics(); //Calculates all the metrics
  void printMetrics(); //Prints all the metrics to standard output

};

#endif
