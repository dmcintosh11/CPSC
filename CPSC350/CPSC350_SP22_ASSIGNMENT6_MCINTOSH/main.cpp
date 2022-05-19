#include <iostream>
#include "Person.h"
#include "Faculty.h"
#include "FacultyTree.h"
#include "Student.h"
#include "StudentTree.h"
#include "DBHandler.h"

int main() {
  /*Faculty *f = new Faculty(1, "John", "Associate", "Mathematics");
  f->printInfo();

  Faculty *f2 = new Faculty(1, "Timble", "Dean", "Biology");
  f2->printInfo();

  Faculty *s = new Faculty(1, "Jim", "Sophomore", "Mathematics", 3.6);
  s->printInfo();

  Faculty *s2 = new Faculty(1, "Lawn", "Junior", "Data Science", 3.2);
  s2->printInfo();

  cout << (*s==*s2) << endl;
  cout << (s2>s) << endl;

  cout << (*f==*f2) << endl;
  cout << (f2>f) << endl; */

/*  Student *f = new Student(5, "Jim", "Sophomore", "Mathematics", 3.0);
  f->printInfo();

  Student *f2 = new Student(2, "Lawn", "Junior", "Data Science", 3.2);
  //s2->printInfo();
  //
  Student *f3 = new Student(7, "John", "Junior", "Data Science", 2.8);

  Student *f4 = new Student(3, "Tom", "Senior", "Physics", 4.0);

  StudentTree* tree = new StudentTree();
  tree->addStudent(*f); */

/*  DoublyLinkedList<int> dl = DoublyLinkedList<int>();
  dl.insertFront(2);
  dl.insertFront(6);
  //cout << dl.getFront() << endl;


  Faculty *f = new Faculty(5, "Jim", "Sophomore", "Mathematics", dl);
  //cout <<"YUMYUM" << endl;
  //f->printInfo();

  Faculty *f2 = new Faculty(2, "Lawn", "Junior", "Data Science");
  //s2->printInfo();
  //
  Faculty *f3 = new Faculty(7, "John", "Junior", "Data Science");

  Faculty *f4 = new Faculty(3, "Tom", "Senior", "Physics");

  FacultyTree* tree = new FacultyTree();
  tree->addFaculty(*f);
tree->printAllAscending();
cout << tree->getAdvisees(5).getSize() << endl;
cout << tree->getAdvisees(5).getFront() << endl;
  //tree->addFaculty(*f);
  tree->addFaculty(*f2);
  tree->addFaculty(*f3);
  tree->addFaculty(*f4);
  tree->printAllAscending();
  tree->find(3)->key.printInfo();
  tree->deleteFaculty(5);
  tree->printAllAscending();
  cout << tree->contains(5) << endl; */

  DBHandler sim = DBHandler();
  sim.run();
}
