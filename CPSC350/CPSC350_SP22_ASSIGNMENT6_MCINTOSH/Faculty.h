//Header file for Faculty.cpp
//Simulates a Faculty in the record
#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include <string>
#include "DoublyLinkedList.h"

using namespace std;

class Faculty: public Person
{
  protected:
    DoublyLinkedList<int> advisees;

  public:
    Faculty();
    Faculty(int idnum);
    Faculty(int idnum, string n, string l, string f, DoublyLinkedList<int> advs);
    Faculty(int idnum, string n, string l, string f);
    ~Faculty();

    DoublyLinkedList<int> getAdvisees();

    void setAdvisees(DoublyLinkedList<int> advs);
    void addAdvisee(int adv);
    int removeAdvisee(int adv);
    bool hasAdvisees();

    void printInfo();

    string toCSV();


};

#endif
