#include "Simulation.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

//Constructor
Simulation::Simulation() {
  line = new GenQueue<Student*>();
  fileValues = new DoublyLinkedList<int>();
  studentWaits = new DoublyLinkedList<int>();
  readFile("test.txt");

  studentWaitCount = 0;

  avgStudentWait = 0.0;
  medianStudentWait = 0;
  maxStudentWait = 0;
  studOver10 = 0;
  avgIdle = 0.0;
  maxIdle = 0;
  winOver5 = 0;
}

//Overloaded constructor that takes in fileName as input for file to read
Simulation::Simulation(string fileName) {
  line = new GenQueue<Student*>();
  fileValues = new DoublyLinkedList<int>();
  studentWaits = new DoublyLinkedList<int>();
  readFile(fileName); //Loads in file and sets cur to the firts node in the fileValues

  studentWaitCount = 0;

  avgStudentWait = 0.0;
  medianStudentWait = 0;
  maxStudentWait = 0;
  studOver10 = 0;
  avgIdle = 0.0;
  maxIdle = 0;
  winOver5 = 0;
}

//Destructor
Simulation::~Simulation() {
  delete line;
  delete cur;
}

//Loops through until there are no students left in the registrar and that no more will enter the registrar
void Simulation::run() {
  int nextTick = cur->data;
  //Iterates through until the end of the simulation
  while(cur != NULL || !line->isEmpty() || !registrarEmpty()) {

    //Begins to add all students associated with a tick time to the queue if the program's queue time is matched
    if(nextTick == tick) {
      std::cout << "Enter" << std::endl;
      cur = cur->next;
      int amountStudents = cur->data;
      for(int i = 0; i < amountStudents; ++i) {
        cur = cur->next;
        int curTime = cur->data;
        Student* s = new Student(curTime, tick);
        line->insert(s);


      }

      cur = cur->next;

    }
    //Iterates through all windows to increment idle times or add students to an available window from the queue
    for(int i = 0; i < numWindows; ++i) {
      Window* curWindow = windows[i];
      if(curWindow->isOccupied()) {
        curWindow->decrementTime();
      }
      //Edge case could happen where the previous if statement made the window unoccupied
      else if(!line->isEmpty() && !curWindow->isOccupied()){ //If there are Students waiting in the queue and the window isn't handling a student


        Student* nextInLine = line->remove();

        int wait = tick - nextInLine->getTick();

        if( wait > 0) {
          studentWaits->insertBack(wait);
          studentWaitCount++;
        }

        curWindow->assignStudent(nextInLine);
        curWindow->decrementTime();

      } else if(!(line->isEmpty() && cur == NULL)){
        curWindow->incrementIdle();
      }
    }


    tick++; //Increments the tick time after every loop to keep time going

  }


  printMetrics();
}

//Reads the input file and transforms all the int values collected into a vector
void Simulation::readFile(string inputFile) {
  ifstream inFile(inputFile);
  string words;
  string fileString = "";
  int lineCount = 0;


  //Iterates through every line in the file
  while(getline(inFile, words)) {
    fileValues->insertBack(stoi(words)); //Inserts all ints into a DoublyLinkedList
  }

  cur = fileValues->getFront();
  numWindows = cur->data; //Collects number of windows from file
  for(int i = 0; i < numWindows; ++i) {
    windows[i] = new Window();
  }

  //Sets cur to the first tick time value of the file
  cur = cur->next;


}

//Decremetns all of the students time needed in windows
void Simulation::decrementStuds() {
  for(int i = 0; i < numWindows; ++i) {
    windows[i]->decrementTime();
  }
}

//Returns true if there are no occupied windows in the registrar
bool Simulation::registrarEmpty() {
  bool check = true;
  for(int i = 0; i < numWindows; ++i) {
    if(windows[i]->isOccupied())
      check = false;
  }
  return check;
}

//Calculates all of the metrics
void Simulation::calculateMetrics() {
  //Grabs first student wait node
  ListNode<int>* cur = studentWaits->getFront();
  int max = 0;
  int i = 0;
  //Iterates through all student wait times and begins calculating metrics
  while(cur != NULL) {
    int curWait = cur->data;
    if(studentWaitCount/2 == i) {
      medianStudentWait = curWait;
    }
    avgStudentWait += curWait;
    if(curWait > max)
      max = curWait;
    if(curWait > 10)
      studOver10++;
    cur = cur->next;
    ++i;
  }


  maxStudentWait = max;
  if(studentWaitCount > 0) {
    avgStudentWait /= studentWaitCount;
  }



  //Iterates through all windows to gather idle time information and calculates window metrics
  max = 0;
  for(int i = 0; i < numWindows; ++i) {
    Window* curWindow = windows[i];
    int idle = curWindow->getIdle();
    avgIdle += idle;
    if(idle > max)
      max = idle;
    if(idle > 5)
      winOver5++;
  }

  maxIdle = max;
  avgIdle /= numWindows;
}

//Prints all of the metrics
void Simulation::printMetrics() {
  calculateMetrics(); //First calls the method to calculate them

  std::cout << "Students" << std::endl;
  std::cout << "~~~~~~~~~~" << std::endl;

  std::cout << "\nAverage Student Wait: " << avgStudentWait << std::endl;
  std::cout << "Median Student Wait: " << medianStudentWait << std::endl;
  std::cout << "Longest Student Wait: " << maxStudentWait << std::endl;
  std::cout << "Number of Students waiting over 10 minutes: " << studOver10 << std::endl;

  std::cout << "\nWindows" << std::endl;
  std::cout << "~~~~~~~~~~" << std::endl;

  std::cout << "\nAverage Window Idle: " << avgIdle << std::endl;
  std::cout << "Longest Window Idle: " << maxIdle << std::endl;
  std::cout << "Number of Windows idle over 5 minutes: " << winOver5 << std::endl;
}
