//Header file for DBHandler.cpp
//Runs the data base and keeps track of trees
#ifndef DBHANDLER_H
#define DBHANDLER_H

#include "Faculty.h"
#include <string>
#include "GenStack.h"
#include "BST.h"
#include "Student.h"
#include "FacultyTree.h"
#include "StudentTree.h"
#include <iostream>

using namespace std;

class DBHandler
{
  private:
    FacultyTree facTree;
    StudentTree studTree;


  public:
    DBHandler();
    ~DBHandler();

    void run();

    void fillEmptyAdvisors();
    void fillEmptyAdvisees(DoublyLinkedList<int> advisees);

    Faculty getFaculty(int id);
    Student getStudent(int id);
    void addStudent(Student s);
    void addFaculty(Faculty f);
    void setAdvisor(int studID, int facID);
    void addAdvisee(int facID, int studID);
    void deleteAdvisee(int facID, int studID);

    bool studIDExists(int id);
    bool facIDExists(int id);
    void unassignFac(int id);
    void unassignStud(int id);

    int promptUser();
    int promptID();
    Student promptForStudent();
    Faculty promptForFaculty();

    void printStudents(int id);
    void printAllStudents();
    void printAllFaculty();
    void displayStudent(int id);
    void displayFaculty(int id);

    void save();
    void load();





};

#endif
