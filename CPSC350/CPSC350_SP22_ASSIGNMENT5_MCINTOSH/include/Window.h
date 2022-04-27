//Header file for Window.cpp
//Simulates a window in the registrar
#ifndef WINDOW_H
#define WINDOW_H

#include "Student.h"

class Window {
public:

  //Constructors and Destructors
  Window();
  ~Window();

  bool isOccupied(); //Returns true if a student is currently at the window
  bool assignStudent(Student* s); //Assigns a student to the window
  int getStudTick(); //Returns the tick time the student entered the queue
  int getIdle(); //Returns the time the window idled
  int getTime(); //Returns time left for student at the window
  void incrementIdle(); //Increments idle time
  bool decrementTime(); //Decrements time left for student at the window
  void decrementStud(); //Decrements  time left for the student object left at window

private:
  int idleTime; //Stores time the window is idle
  Student* currentStudent; //Pointer to the student currently at the window
  int timeLeft; //Time left before the student finishes request at window

};

#endif
