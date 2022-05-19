#include "DBHandler.h"
#include <fstream>

using namespace std;

DBHandler::DBHandler() {
  facTree = FacultyTree();
  studTree = StudentTree();
  load();

  //facStack = DoublyLinkedList<FacultyTree>();
  //studStack = DoublyLinkedList<StudentTree>();
}

DBHandler::~DBHandler() {

}

void DBHandler::run() {
  int in = 0;;
  while(in != 14) { //When input is 14, program exits
    in = promptUser();
    int id = -1;
    int studID = -1;
    int facID = -1;
    Faculty f;
    Student s;

    fillEmptyAdvisors();

      if(in == 1)
      {
        if(studTree.isEmpty()) {
          cout << "No student records" << endl;
        } else {
          printAllStudents();
        }

      }
      if(in == 2)
      {
        if(facTree.isEmpty()) {
          cout << "No Faculty records" << endl;
        } else {
          printAllFaculty();
        }
      }
      if(in == 3)
      {
        id = promptID();

        if(!studIDExists(id)) {
          cout << "Student ID doesn't exist" << endl;
        } else {
          getStudent(id).printInfo();
        }

      }
      if(in == 4)
      {
        id = promptID();
        if(!facIDExists(id)) {
          cout << "Faculty ID doesn't exist" << endl;
        } else {
          getFaculty(id).printInfo();
        }
      }
      if(in == 5)
      {
        id = promptID();
        if(!studIDExists(id)) {
          cout << "Student ID doesn't exist" << endl;
        } else {
          Student s = getStudent(id);
          if(!s.hasAdvisor()) {
            cout << "Student has no advisor" << endl;
          } else {
            facID = getStudent(id).getAdvisor();
            getFaculty(facID).printInfo();
            cout << "-----------" << endl;
          }
        }
      }
      if(in == 6)
      {
        id = promptID();
        if(!facIDExists(id)) {
          cout << "Faculty ID doesn't exist" << endl;
        } else {
          DoublyLinkedList<int> ids = getFaculty(id).getAdvisees();
          ListNode<int>* cur = ids.getFrontPtr();
          if(cur == NULL) {
            cout << "Faculty has no advisees" << endl;
          } else {
            cout << "Advisees are: " << endl;
          }

          while(cur != NULL) {
            int studID = cur->data;
            getStudent(studID).printInfo();
            cout << "-----------" << endl;
            cur = cur->next;
          }
        }
      }
      if(in == 7)
      {
        //updateStack();
        s = promptForStudent();
        addStudent(s);
      }
      if(in == 8)
      {
        //updateStack();
        id = promptID();
        studTree.deleteStudent(id);
        unassignStud(id);
      }
      if(in == 9)
      {
        //updateStack();
        f = promptForFaculty();
        addFaculty(f);
      }
      if(in == 10)
      {
        //updateStack();
        id = promptID();
        facTree.deleteFaculty(id);
        unassignFac(id);
      }
      if(in == 11)
      {
        //updateStack();
        studID = -1;
        facID = -1;
        cout << "Enter student ID: " << endl;
        cin >> studID;
        cout << "Enter faculty ID: " << endl;
        cin >> facID;
        if(!studIDExists(studID) || !facIDExists(facID)) {
          cout << "ID doesn't exist" << endl;
        } else if(getStudent(studID).getAdvisor() != facID){
          deleteAdvisee(getStudent(studID).getAdvisor(), studID);
          setAdvisor(studID, facID);
          addAdvisee(facID, studID);

        } else {
          cout << "Student already has that advisor" << endl;
        }

      }
      if(in == 12)
      {
        //updateStack();
        studID = -1;
        facID = -1;
        cout << "Enter student ID: " << endl;
        cin >> studID;
        cout << "Enter faculty ID: " << endl;
        cin >> facID;
        if(!studIDExists(studID) || !facIDExists(facID)) {
          cout << "ID doesn't exists" << endl;
        } else {
          s = getStudent(studID);
          if(s.getAdvisor() == facID){
            studTree.setAdvisor(studID, -1);
            deleteAdvisee(facID, studID);
          } else {
            cout << "Student does not have this advisor" << endl;
          }
        }

      }
      if(in == 13)
      {
        /*
        if(facStack.isEmpty()) {
        cout << "Nothing to rollback" << endl;
        } else {
        recall()
        }
        */
       cout << "Feature not yet implemented" << endl;

      }



  }
  save();
}

Faculty DBHandler::getFaculty(int id) {
  return facTree.find(id)->key;
}

Student DBHandler::getStudent(int id) {
  return studTree.find(id)->key;
}

void DBHandler::addStudent(Student s) {
  studTree.addStudent(s);
}

void DBHandler::addFaculty(Faculty f) {
  facTree.addFaculty(f);
}

void DBHandler::setAdvisor(int studID, int facID) {
  studTree.find(studID)->key.setAdvisor(facID);
}

void DBHandler::addAdvisee(int facID, int studID) {
  facTree.find(facID)->key.addAdvisee(studID);
}

void DBHandler::deleteAdvisee(int facID, int studID) {
  facTree.find(facID)->key.removeAdvisee(studID);
}

int DBHandler::promptID() {
  cout << "Enter ID: " << endl;
  int id = -1;
  cin >> id;
  return id;
}

bool DBHandler::studIDExists(int id) {
  studTree.contains(id);
}

bool DBHandler::facIDExists(int id) {
  facTree.contains(id);
}

void DBHandler::unassignFac(int id) {
  studTree.unassignAdvisor(id);
}

void DBHandler::unassignStud(int id) {
  facTree.unassignAdvisee(id);
}

int DBHandler::promptUser() {
  int in = 0;
  while(in < 1 || in > 14) {
    cout << "-----------" << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)"  << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)"  << endl;
    cout << "3. Find and display student information given the students id"  << endl;
    cout << "4. Find and display faculty information given the faculty id"  << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor"  << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees."  << endl;
    cout << "7. Add a new student"  << endl;
    cout << "8. Delete a student given the id"  << endl;
    cout << "9. Add a new faculty member"  << endl;
    cout << "10. Delete a faculty member given the id."  << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id."  << endl;
    cout << "12. Remove an advisee from a faculty member given the ids"  << endl;
    cout << "13. Rollback"  << endl;
    cout << "14. Exit"  << endl;
    cout << "Enter a number 1-14 to select an option" << endl;
    cin >> in;
  }

  return in;
}

//Finish prompting ALSO *********HOW TO HANDLE ADVISOR IF NO ADVISOR EXISTS
Student DBHandler::promptForStudent() {
  int id = -1;
  string name = "None";
  string level = "None";
  string field = "None";
  double GPA = 0.0;
  int advisor = -1;

  cout << "Enter student ID: " << endl;
  cin >> id;
  while(studIDExists(id)) {
    cout << "Student ID already exists" << endl;
    cout << "Enter student ID: " << endl;
    cin >> id;
  }

  cout << "Enter student name: " << endl;
  cin >> name;

  cout << "Enter student grade level: " << endl;
  cin >> level;

  cout << "Enter student major: " << endl;
  cin >> field;

  cout << "Enter student GPA: " << endl;
  cin >> GPA;

  if(facTree.isEmpty()) {
    Student s = Student(id, name, level, field, GPA);
    return s;
  } else {
    cout << "Enter faculty ID: " << endl;
    cin >> advisor;
    while(!facIDExists(advisor)) {
      cout << "Faculty ID doesn't exist" << endl;
      cout << "Enter faculty ID: " << endl;
      cin >> advisor;
    }
    Student s = Student(id, name, level, field, GPA, advisor);
    addAdvisee(advisor, id);
    return s;
  }

}

Faculty DBHandler::promptForFaculty() {
  int id = -1;
  string name = "None";
  string level = "None";
  string field = "None";

  cout << "Enter faculty ID: " << endl;
  cin >> id;
  while(facIDExists(id)) {
    cout << "Faculty ID already exists" << endl;
    cout << "Enter faculty ID: " << endl;
    cin >> id;
  }

  cout << "Enter faculty name: " << endl;
  cin >> name;

  cout << "Enter faculty level: " << endl;
  cin >> level;

  cout << "Enter faculty field: " << endl;
  cin >> field;

  Faculty f = Faculty(id, name, level, field);
  return f;

}

void DBHandler::printAllStudents() {
  studTree.printAllAscending();
}

void DBHandler::printAllFaculty() {
  facTree.printAllAscending();
}

void DBHandler::fillEmptyAdvisors() { //Gives students an advisor if they don't have one
  if(!facTree.isEmpty() && !studTree.isEmpty()) {
    DoublyLinkedList<int> advisees = studTree.fillEmptyAdv(facTree.getRoot()->key.getID());
    advisees.printList(0);
    if(!advisees.isEmpty()) {
      fillEmptyAdvisees(advisees);
    }
  }
}

void DBHandler::fillEmptyAdvisees(DoublyLinkedList<int> advisees) { //Takes list of students that didn't have an advisor and adds them to the root faculty's advisees
  facTree.getRoot()->key.addAdvisees(advisees); //NEeds to add advisees not set
}

void DBHandler::save() {
  string s = "";
  string f = "";
  studTree.toCSV(studTree.getRoot(), s);
  facTree.toCSV(facTree.getRoot(), f);

  ofstream studFile;
  studFile.open ("masterStudent.txt");
  studFile << s;
  studFile.close();

  ofstream facFile;
  facFile.open ("masterFaculty.txt");
  facFile << f;
  facFile.close();
}

void DBHandler::load() {
  string line;
  ifstream studFile ("masterStudent.txt");
  if (studFile.is_open())
  {
    while ( getline (studFile,line) )
    {
      Student s;
      int id = -1;
      string name = "None";
      string level = "None";
      string field = "None";
      double GPA = 0.0;
      int advisor = -1;

      string currentVal = "";
      int varNum = 0;

      for(int i = 0; i < line.size(); ++i) {

        if(line[i] == (',') || i == line.size() - 1) {
          if(varNum == 0) {
            name = currentVal;
            varNum++;
            currentVal = "";
          } else if(varNum == 1) {
            id = stoi(currentVal);
            varNum++;
            currentVal = "";
          } else if(varNum == 2) {
            level = currentVal;
            varNum++;
            currentVal = "";
          } else if(varNum == 3) {
            field = currentVal;
            varNum++;
            currentVal = "";
          } else if(varNum == 4) {
            GPA = stod(currentVal);
            varNum++;
            currentVal = "";
          } else {
            currentVal += line[i];
            advisor = stoi(currentVal);

            varNum = 0;
            currentVal = "";
          }

        }
        if(line[i] != (' ') && line[i] != (',')) {
          currentVal += line[i];
        }


      }

      s = Student(id, name, level, field, GPA, advisor);
      studTree.addStudent(s);
    }
    studFile.close();
  } else {
    cout << "No student record to load" << endl;
  }


  string linef;
  ifstream facFile ("masterFaculty.txt");
  if (facFile.is_open())
  {
    while ( getline (facFile,linef) )
    {
      Faculty f;
      int id = -1;
      string name = "None";
      string level = "None";
      string field = "None";
      int advisee = -1;
      DoublyLinkedList<int> advisees = DoublyLinkedList<int>();

      string currentVal = "";
      int varNum = 0;

      for(int i = 0; i < linef.size(); ++i) {
        if(linef[i] == (',') || i == linef.size() - 1) {
          if(varNum == 0) {
            name = currentVal;
            varNum++;
            currentVal = "";
          } else if(varNum == 1) {

            id = stoi(currentVal);
            varNum++;
            currentVal = "";
          } else if(varNum == 2) {
            level = currentVal;
            varNum++;
            currentVal = "";
          } else if(varNum == 3) {
            field = currentVal;
            varNum++;
            currentVal = "";
          }
          else if(varNum == 4){

            currentVal += linef[i];
            advisee = stoi(currentVal);

            if(stoi(currentVal) != -1) {//Iterate through rest of string to add all advisees
              advisees.insertBack(advisee);

              currentVal = "";
            }
          }

        }
        if(linef[i] != (' ') && linef[i] != (',')) {
          currentVal += linef[i];
        }


      }

      if(advisee == -1) {
        f = Faculty(id, name, level, field);
        facTree.addFaculty(f);
      } else {
        f = Faculty(id, name, level, field, advisees);
        facTree.addFaculty(f);
      }

    }
    facFile.close();

  } else {
    cout << "No faculty record to load" << endl;
  }


}

void DBHandler::updateStack() {
  /*cout << "facStack size: " << facStack.getSize() << endl;
  if(facStack.getSize() == 5) {
    facTree = facStack.removeBack();
    studTree = studStack.removeBack();
  }
  facStack.insertFront(facTree);
  cout << "Between" << endl;
  studStack.insertFront(studTree); */
}

void DBHandler::recall() {
  /*facTree = facStack.removeFront();
  studTree = studStack.removeFront(); */
}
