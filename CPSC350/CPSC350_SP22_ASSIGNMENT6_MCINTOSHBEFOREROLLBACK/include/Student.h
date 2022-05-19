//Header file for Student.cpp
//Simulates a Student in the record
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>

using namespace std;

class Student: public Person
{
  protected:
    double GPA;
    int advisor;

  public:
    Student();
    Student(int idnum);
    Student(int idnum, string n, string l, string f, double g, int adv);
    Student(int idnum, string n, string l, string f, double g);
    ~Student();

    double getGPA();
    int getAdvisor();

    void setAdvisor(int adv);
    void removeAdvisor();
    bool hasAdvisor();

    void printInfo();
    int getAdvisorID();

    string toCSV();

};

#endif
