#include <iostream>
#include "Person.h"
#include "Faculty.h"
#include "FacultyTree.h"
#include "Student.h"
#include "StudentTree.h"
#include "DBHandler.h"

int main() {
  

  DBHandler sim = DBHandler();
  sim.run();
}
