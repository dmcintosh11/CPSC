#include "Person.h"
#include "Faculty.h"
#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

Faculty::Faculty() {
  id = 0;
  name = "None";
  level = "None";
  field = "None";
  advisees = DoublyLinkedList<int>();
}

Faculty::Faculty(int idnum) {
  id = idnum;
  name = "None";
  level = "None";
  field = "None";
  advisees = DoublyLinkedList<int>();
}

Faculty::Faculty(int idnum, string n, string l, string f) {
  id = idnum;
  name = n;
  level = l;
  field = f;
  advisees = DoublyLinkedList<int>();
}

Faculty::Faculty(int idnum, string n, string l, string f, DoublyLinkedList<int> advs) {
  id = idnum;
  name = n;
  level = l;
  field = f;
  advisees = advs;
}

Faculty::~Faculty() {

}



DoublyLinkedList<int> Faculty::getAdvisees() {
  return advisees;
}

void Faculty::setAdvisees(DoublyLinkedList<int> advs) {
  advisees = advs;
  advisees.printList(0);

}

void Faculty::addAdvisees(DoublyLinkedList<int> advs) {
  while(!advs.isEmpty()) {
    addAdvisee(advs.removeFront());
  }
}

void Faculty::addAdvisee(int adv) {
  advisees.insertBack(adv);
}

int Faculty::removeAdvisee(int adv) {
  if(hasAdvisees()) {
    return advisees.removeNode(adv);
  }
  else
    return -1;
}

bool Faculty::hasAdvisees() {
  return !advisees.isEmpty();
}

void Faculty::printInfo() {
  cout << "Name: " << name << endl;
  cout << "ID Number: " << id << endl;
  cout << "Level: " << level << endl;
  cout << "Department: " << field << endl;

}

string Faculty::toCSV() {
  return (name + ", " + to_string(id) + ", " + level + ", " + field + advisees.toCSV());

}
