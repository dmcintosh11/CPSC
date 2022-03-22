//Header file for GameBoard.cpp
//Creates a 2D Array of characters to simulate a grid for the game

#if !defined GAMEBOARD_H
#define GAMEBOARD_H

#include <string>

using namespace std;

class GameBoard {
public:
  //Constructors and destructor
  GameBoard();
  GameBoard(int width, int height, float popDense);
  GameBoard(int width, int height, string inBoard);
  GameBoard(const GameBoard &copy);
  ~GameBoard();

  //Adjust and get information in grid in a specific cell
  void setPos(int row, int col, char status);
  char getPos(int row, int col);

  //Adjust and get information in grid
  char** getBoard();
  void printBoard();
  string toString();
  int getRows();
  int getCols();
  bool isEmpty();

private:
  char** board;
  int rows;
  int cols;
  float density;

  void genRanDens();

};
#endif
