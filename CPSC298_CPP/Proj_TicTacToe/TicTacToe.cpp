/// @file TicTacToe.cpp
/// @brief Implementation file for TicTacToe
/// @author dmcintosh@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++
///

#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() {
  grid = new char* [3];
  for(int i = 0; i < 3; ++i) {
    grid[i] = new char[3];
  }


  for(int r = 0; r < numRows; ++r) {
    for (int c = 0; c < numCols; ++c) {
      grid[r][c] = '~';
    }

  }

  currRow = -1;
  currCol = -1;

}

void TicTacToe::play() {

  while(!isOver()) {

    displayGrid();
    promptUser();
    while(!emptySpace(currRow, currCol)) {
      std::cout << "Space already filled" << std::endl;
      promptUser();
    }
    changeGrid(currRow, currCol, 1);
    displayGrid();
    if(!isOver()) {
      botTurn();
    }
    if(playerWon()) {
      std::cout << "You have won!" << std::endl;

    } else if(botWon()) {
      std::cout << "You have lost!" << std::endl;

    } else if (isDraw()) {
      std::cout << "Game is a tie!" << std::endl;
    }
  }

}

void TicTacToe::promptUser() {
  int r = -1;

  std::cout << "Enter row number: " << std::endl;
  std::cin >> r;

  while(!inBounds(r)) {
    std::cout << "Invalid entry, try again with 0, 1, or 2: " << std::endl;
    std::cin >> r;
  }

  currRow = r;

  int c = -1;

  std::cout << "Enter column number: " << std::endl;
  std::cin >> c;

  while(!inBounds(c)) {
    std::cout << "Invalid entry, try again with 0, 1, or 2: " << std::endl;
    std::cin >> c;
  }

  currCol = c;


}

//int player indicates 0 for bot and 1 for human player
void TicTacToe::changeGrid(int r, int c, int player) {
  if(player == 1)
  grid[r][c] = 'X';
    else
  grid[r][c] = 'O';

}

void TicTacToe::displayGrid() {
  for(int r = 0; r < 3; ++r) {
    for(int c = 0; c < 3; ++c) {
      std::cout << grid[r][c] << " ";
    }
    std::cout << std::endl;
  }
}

bool TicTacToe::inBounds(int in) {
  if(in < 3 && in >= 0) {
    return true;
  } else {
    return false;
  }

}

bool TicTacToe::emptySpace(int r, int c) {
  if(grid[r][c] == '~') {
    return true;

  } else {

    return false;
  }

}

void TicTacToe::botTurn() {
  for(int r = 0; r < 3; ++r) {
    for(int c = 0; c < 3; ++c) {
      if(emptySpace(r, c)) {
        changeGrid(r, c, 0);
        return;
      }
    }
  }
}

bool TicTacToe::isOver() {
  if(isDraw() || playerWon() || botWon())
    return true;
  return false;
}

bool TicTacToe::playerWon() {
  int xCount = 0;
  for(int r = 0; r < 3; ++r) {
    for(int c = 0; c < 3; ++c) {
      if(grid[r][c] == 'X')
        xCount++;
    }
    if(xCount == 3)
      return true;
    xCount = 0;
  }

  for(int c = 0; c < 3; ++c) {
    for(int r = 0; r < 3; ++r) {
      if(grid[r][c] == 'X')
        xCount++;
    }
    if(xCount == 3)
      return true;
    xCount = 0;
  }

  for(int i = 0; i < 3; ++i) {
    if(grid[i][i] == 'X')
      xCount++;
  }
  if(xCount == 3)
    return true;

  return false;
}

bool TicTacToe::botWon() {
  int oCount = 0;
  for(int r = 0; r < 3; ++r) {
    for(int c = 0; c < 3; ++c) {
      if(grid[r][c] == 'O')
        oCount++;
    }
    if(oCount == 3)
      return true;
    oCount = 0;
  }

  for(int c = 0; c < 3; ++c) {
    for(int r = 0; r < 3; ++r) {
      if(grid[r][c] == 'O')
        oCount++;
    }
    if(oCount == 3)
      return true;
    oCount = 0;
  }

  for(int i = 0; i < 3; ++i) {
    if(grid[i][i] == 'O')
      oCount++;
  }
  if(oCount == 3)
    return true;

  return false;
}

bool TicTacToe::isDraw() {
  bool check = true;
  for(int r = 0; r < 3; ++r) {
    for(int c = 0; c < 3; ++c) {
      if( grid[r][c] == '~')
        check = false;
    }
  }
  return check;
}

TicTacToe::~TicTacToe() {

  for(int i = 0; i < 3; ++i) {
    delete[] grid[i];

  }

}
