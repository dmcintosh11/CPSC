//Implementation of Student.h to simulate a student in the registrar
#include "Student.h"

//Constructor
Student::Student() {
  timeNeeded = 0;
  waitTime = 0;
  tickAdded = 0;
}

//Overloaded constructor that takes in t, time needed and tickAdd, tick time the student was created in the queue
Student::Student(int t, int tickAdd) {
  timeNeeded = t;
  waitTime = 0;
  tickAdded = tickAdd;
}

//Destructor
Student::~Student() {

}

//Returns waitTime
int Student::getWait() {
  return waitTime;
}

//Returns timeNeeded
int Student::getTime() {
  return timeNeeded;
}

//Returns tickAdded
int Student::getTick() {
  return tickAdded;
}

//Increments waitTime
void Student::incrementIdle() {
  waitTime++;
}

//Decrements timeNeeded
bool Student::decrementTime() {
  timeNeeded--;
}
