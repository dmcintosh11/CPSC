#if !defined(TICTACTOE_H)
#define TICTACTOE_H
/// @file TicTacToe.h
/// @brief Header file for TicTacToe
/// @author dmcintosh@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++
///

#include <vector>

class TicTacToe {

  static const int numRows = 3;
  static const int numCols = 3;

private:
  char** grid;
  int currRow;
  int currCol;

public:
  TicTacToe();

  void play();

  ~TicTacToe();

private:
  void promptUser();

  bool inBounds(int in);

  bool emptySpace(int r, int c);

  void botTurn();

  bool isOver();

  void changeGrid(int r, int c, int player);

  void displayGrid();

  bool isDraw();

  bool botWon();

  bool playerWon();




};


#endif
