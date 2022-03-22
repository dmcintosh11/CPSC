//Header file for abstract class GameMode.cpp
//Sets basic common ground rules and fuctions for each game mode to be inherited
//S
#if !defined GAMEMODE_H
#define GAMEMODE_H

#include "GameBoard.h"
#include <string>

class GameMode {
public:
  //Constructors and destructor
  GameMode();
  ~GameMode();

  //Methods used to help run the game
  void processGen();
  int getGen();
  void printCurGen();
  void printNextGen();
  bool isStable();
  int countNeighbors(int row, int col);
  int countNeighborsNoEdge(int row, int col);
  int isPosAlive(int row, int col);
  void swapBoards();
  void loadFile();
  string curGenToString();

protected:
  GameBoard* currentGen; //Instance of the GameBoard that represents the current state
  GameBoard* nextGen; //Instance of the GameBoard that represents the next generation state
  int genNum; //Number of current generations
  int cols;
  int rows;

  //Edge case methods to count the amount of neighbors in each cell to be defined in the different game mode subclasses
  virtual int topLeftCorner(int row, int column) = 0;
  virtual int topRightCorner(int row, int column) = 0;
  virtual int bottomLeftCorner(int row, int column) = 0;
  virtual int bottomRightCorner(int row, int column) = 0;
  virtual int bottomEdgeNotCorner(int row, int column) = 0;
  virtual int topEdgeNotCorner(int row, int column) = 0;
  virtual int leftEdgeNotCorner(int row, int column) = 0;
  virtual int rightEdgeNotCorner(int row, int column) = 0;
};

#endif
