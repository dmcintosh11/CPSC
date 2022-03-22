//Implementation of GameBoard.h

#include "GameBoard.h"
#include <iostream>
#include <time.h>

using namespace std;

//Default constructor
GameBoard::GameBoard() {

  rows = 5;
  cols = 5;
  density = 0.5;

  board = new char*[rows];
  for(int i = 0; i < rows; ++i) {
    board[i] = new char[cols];
  }

  genRanDens();
}

//Overloaded constructor that takes the width as rows, height as cols, and popDense as the population density for bacteria
GameBoard::GameBoard(int width, int height, float popDense) {
  rows = width;
  cols = height;
  density = popDense;

  board = new char*[rows];
  for(int i = 0; i < rows; ++i) {
    board[i] = new char[cols];
  }

  genRanDens();
}

//Overloaded constructor that also takes in a string of a 2d Array from an input file to copy over to board
GameBoard::GameBoard(int width, int height, string inBoard) {
  rows = width;
  cols = height;
  density = -1;

  //Creates 2d character array
  board = new char*[rows];
  for(int i = 0; i < rows; ++i) {
    board[i] = new char[cols];
  }

  //Loops through board to set each index equal to appropriat char in the input string
  int stringIndex = 0;
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      board[r][c] = inBoard[stringIndex];
      stringIndex++;
    }
  }

}

//Copy constructor to create a deep copy of an input board
GameBoard::GameBoard(const GameBoard &copy){
    rows = copy.rows;
    cols = copy.cols;

    board = new char* [rows];
    for(int i = 0; i < rows; ++i){
        board[i] = new char[cols];
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            board[i][j] = copy.board[i][j];
        }
    }
}

//Destructor that deletes board
GameBoard::~GameBoard() {
  for(int r = 0;r < rows; ++r) {
    delete[] board[r];
  }
  delete[] board;
}

//Used for random generation of a board based upon the input population density
void GameBoard::genRanDens() {
  srand(time(NULL)); //Randomizes seed
  float random;
  //Loops through board
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      random = (float)rand()/RAND_MAX; //Generates random float between 0 and 1
      if(random < density) {
        board[r][c] = 'X'; //Alive cell
      } else {
        board[r][c] = '-'; //Empty cell
      }

    }
  }
}

//Sets a specific cell in board equal to input char, either 'X' or '-'
void GameBoard::setPos(int row, int col, char status) {
  board[row][col] = status;
}

//Returns the char in a specified position on board
char GameBoard::getPos(int row, int col) {
  return board[row][col];
}

//Returns board
char** GameBoard::getBoard() {
  return board;
}

//Prints all chars in board to standard output
void GameBoard::printBoard() {
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      cout << board[r][c];
    }
    cout << "" << endl;
  }
}

//Returns a string of all chars in board
string GameBoard::toString() {
  string s = "";
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      s+= board[r][c];
    }
    s+= "\n";
  }
  return s;
}

//Returns rows
int GameBoard::getRows() {
  return rows;
}

//Returns cols
int GameBoard::getCols() {
  return cols;
}

//Checks if every cell in board is empty (contains '-')
bool GameBoard::isEmpty() {
  bool check = true;
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      if(board[r][c] == 'X') {
        check = false;
      }
    }
  }
  return check;
}
