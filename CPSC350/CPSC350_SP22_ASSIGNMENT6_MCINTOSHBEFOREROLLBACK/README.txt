README Assignment 6: Database

1. Dylan McIntosh
   2368740
   dmcintosh@chapman.edu
   CPSC 350-01
   Assignment 6: Database

2. main.cpp
   BST.h
   TreeNode.h
   ListNode.h
   DoublyLinkedList.h
   DBHandler.h
   DBHandler.cpp
   Person.h
   Person.cpp
   Faculty.h
   Faculty.cpp
   Student.h
   Student.cpp
   FacultyTree.h
   FacultyTree.cpp
   StudentTree.h
   StudentTree.cpp

3. Rollback feature not implemented

4. Used bst and linked list files given in slack channel to modify into a usable implementation
   Used https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int to help remember how to convert string to an int
   Used https://stackoverflow.com/questions/8810224/inheriting-from-a-template-class-in-c to help with making faculty and student trees
   Used https://localcoder.org/c-error-double-free-or-corruption-fasttop to help get over an error that took me days to solve


5. g++ -o run *.cpp
   ./run
   It will load masterStudent.txt and masterFaculty.txt to start
   You can then enter a number and follow the prompts to do the actions
   Kept referential integrity by correcting any referential issues rather than warning the user and aborting command
   **** I mainly dealt with referential integrity by using the root of the faculty tree as the default advisor and giving every student that doesn't have an advisor the default advisor****
   ****It may seem like when you delete an advisee from an advisor that it doesn't work but it just gets reassigned to the default advisor on the next loop iteration****
   **** I used csv format for saving and loading files ****
   **** I also did not get to implement the rollback feature because I could not get it to work with several different implementations***
