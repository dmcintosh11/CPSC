//Header file for Person.cpp
//Person is to be super class to Student and Faculty
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
  protected:
    int id;
    string name;
    string level;
    string field;
  public:
    Person();
    ~Person();

    int getID();
    string getName();
    string getLevel();
    string getField();

    bool operator==(Person p);
    bool operator!=(Person p);
    bool operator<(Person p);
    bool operator>(Person p);

};

#endif
