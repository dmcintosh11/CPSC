#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() {
  id = 0;
  name = "None";
  level = "None";
  field = "None";
}

Person::~Person() {

}

int Person::getID() {
  return id;
}

string Person::getName() {
  return name;
}

string Person::getLevel() {
  return level;
}

string Person::getField() {
  return field;
}

bool Person::operator==(Person p) {
  return id == p.getID();
}

bool Person::operator!=(Person p) {
  return !(id == p.getID());
}

bool Person::operator>(Person p) {
  return id > p.getID();
}

bool Person::operator<(Person p) {
  return id < p.getID();
}
