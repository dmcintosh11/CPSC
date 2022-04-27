//Header file for Student.cpp
//Simulates a student in the registrar
#ifndef STUDENT_H
#define STUDENT_H

class Student {
public:
  //Constructor
  Student();
  //Overloaded constructor
  Student(int t, int tickAdd);
  //Destructor
  ~Student();

  //Getters and incrementers/decrementers
  int getWait();
  int getTime();
  int getTick();
  void incrementIdle();
  bool decrementTime();

private:
  int tickAdded; //Tick time that the student was added to the queue
  int waitTime; //Time that the student has waited
  int timeNeeded; //Time the student needs to fulfill request

};

#endif
