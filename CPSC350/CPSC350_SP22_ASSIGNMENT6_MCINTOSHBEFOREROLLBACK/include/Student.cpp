#include "Person.h"
#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() {
  id = 0;
  name = "None";
  level = "None";
  field = "None";
  GPA = 0.0;
  advisor = -1;
}

Student::Student(int idnum) {
  id = idnum;
  name = "None";
  level = "None";
  field = "None";
  GPA = 0.0;
  advisor = -1;
}

Student::Student(int idnum, string n, string l, string f, double g) {
  id = idnum;
  name = n;
  level = l;
  field = f;
  GPA = g;
  advisor = -1;
}

Student::Student(int idnum, string n, string l, string f, double g, int adv) {
  id = idnum;
  name = n;
  level = l;
  field = f;
  GPA = g;
  advisor = adv;
}

Student::~Student() {

}

double Student::getGPA() {
  return GPA;
}

int Student::getAdvisor() {
  return advisor;
}

void Student::setAdvisor(int adv) {
  advisor = adv;
}

void Student::removeAdvisor() {
  advisor = -1;
}

bool Student::hasAdvisor() {
  return advisor != -1;
}

void Student::printInfo() {
  cout << "Name: " << name << endl;
  cout << "ID Number: " << id << endl;
  cout << "Level: " << level << endl;
  cout << "Major: " << field << endl;
  cout << "GPA: " << GPA << endl;

}

int Student::getAdvisorID() {
  return advisor;
}

string Student::toCSV() {
  return (name + ", " + to_string(id) + ", " + level + ", " + field + ", " + to_string(GPA) + ", " + to_string(advisor));
}
