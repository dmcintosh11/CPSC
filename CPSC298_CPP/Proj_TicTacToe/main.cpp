/// @file main.cpp
/// @brief main function file for TicTacToe
/// @author dmcintosh@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include "TicTacToe.h"
#include <iostream>

int main() {
  std::cout << "Welcome to TicTacToe!" << std::endl;

  TicTacToe* tic = new TicTacToe();

  tic->play();

  std::cout << "Thanks for playing!" << std::endl;

  delete tic;

  return 0;
}
