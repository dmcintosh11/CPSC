//Implementation of Window.h to simulate a window in the registrar
#include "Window.h"
#include "Student.h"

//Constructor
Window::Window() {
  idleTime = 0;
  timeLeft = 0;

}

//Destructor
Window::~Window() {

}

//Returns true if the window is helping a student with a request
bool Window::isOccupied() {
  return timeLeft > 0; //timeLeft == 0 represents that the window is unoccupied
}

//Stores a student object to the window to represent a student getting help at the window
bool Window::assignStudent(Student* s) {
  if(isOccupied())
    return false;
  currentStudent = s;
  timeLeft = currentStudent->getTime();
}

//Returns time window is idle
int Window::getIdle() {
  return idleTime;
}

//Returns the tick time the student arrived in the queue
int Window::getStudTick() {
  return currentStudent->getTick();
}

//Returns the time left until the window completes the request
int Window::getTime() {
  return timeLeft;
}

//Increments idle time
void Window::incrementIdle() {
  idleTime++;
}

//Decrements time left until the request is completed
bool Window::decrementTime() {
  if(timeLeft < 0)
    return false;
  timeLeft--;
}

//Decrements the student object's time left
void Window::decrementStud() {
  if(isOccupied()) {
    currentStudent->decrementTime();
  }
}
