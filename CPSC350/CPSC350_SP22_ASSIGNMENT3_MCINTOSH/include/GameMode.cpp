#include "GameMode.h"
#include "GameBoard.h"
#include <iostream>
#include <string>
#include <fstream>

//Default constructor that gets user input for preferences on how to run program
GameMode::GameMode() {
  //Prompts user for how to generate the GameBoard
  cout << "Would you like to generate a random configuration, or input a file?" << endl;
  string generation = "";
  while(generation != "1" && generation != "2") { //Continues prompting until user inputs correctly
    cout << "Enter 1 for random; 2 for file input" << endl;
    cin >> generation;

  }

  //Proceeds to random generation
  if(generation == "1") {
    rows = 0;

    //Prompts user for rows input until it is input correctly
    while(rows < 2) {
      cout << "Enter rows(greater than 2): " << endl;
      cin >> rows;

    }

    cols = 0;

    //Prompts user for cols until it is input correctly
    while(cols < 2) {
      cout << "Enter cols(greater than 2): " << endl;
      cin >> cols;

    }

    float popDense = -1.0;

    //Prompts user for popDense until it is input correctly
    while(popDense < 0 || popDense >= 1) {
      cout << "Enter population density(between 0 and 1): " << endl;
      cin >> popDense;

    }

    //Creates GameBoard with users preferences
    currentGen = new GameBoard(rows, cols, popDense);


  } else { //File input scenario

    loadFile(); //Function to handle loading a file
  }
  genNum = 1;

  nextGen = new GameBoard(*currentGen); //Creates another GameBoard to represent the next generation to help check for stability in game




}

//Destructor that deletes GameBoard objects
GameMode::~GameMode() {
  delete currentGen;
  delete nextGen;
}

//Used eveytime the next generation should be calculated and counts the neighbors for each cell in the board and carries out game rules
void GameMode::processGen() {
  //Loops through board
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      //Counts neighbors at current cell
      int neighbors = countNeighbors(r, c);


      if(neighbors < 2) { //Cell becomes empty with less than 2 neighbors
        nextGen->setPos(r, c, '-');
      } else if(neighbors == 2) { //Cell remains the same with 2 neighbors
        nextGen->setPos(r, c, currentGen->getPos(r, c));
      } else if(neighbors == 3) { //Cell becomes alive with 3 neighbors
        nextGen->setPos(r, c, 'X');
      } else if(neighbors > 3) { //Cell becomes empty with over 3 neighbors
        nextGen->setPos(r, c, '-');
      }
    }
  }

  genNum++; //Increments generation number

  swapBoards(); //Swaps references of board because the next generation becomes the current generation


}

//Returns generation number
int GameMode::getGen() {
  return genNum;
}

//Prints current generation board to standard output
void GameMode::printCurGen() {
  currentGen->printBoard();
}

//Prints next generation board to standard output
void GameMode::printNextGen() {
  nextGen->printBoard();
}

//Checks if the board is stable and if the game should keep going by comparing the current generatino to the next
bool GameMode::isStable() {
  bool check = true;

  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      //If a cell in one generation differes from that same cell in the next generation, the game should continue
      if(currentGen->getPos(r, c) != nextGen->getPos(r, c)) {
        check = false;
      }
    }
  }
  //If all cells are empty in the board the game should end
  if(currentGen->isEmpty()) {
    check = true;
  }
  return check;
}

//Counts the alive neighbors of given position
int GameMode::countNeighbors(int row, int col) {
  //Determines which edge case scenario this position falls into based on the coordinates
  if(row == 0) {
    if(col == 0) {
      return topLeftCorner(row, col);
    } else if(col == cols - 1) {
      return topRightCorner(row, col);
    } else {
      return topEdgeNotCorner(row, col);
    }
  } else if(row == rows - 1) {
      if(col == 0) {
        return bottomLeftCorner(row, col);
      } else if(col == cols - 1) {
        return bottomRightCorner(row, col);
      } else {
        return bottomEdgeNotCorner(row, col);
      }
  } else if(col == 0) {
    return leftEdgeNotCorner(row, col);

  } else if(col == cols - 1) {
    return rightEdgeNotCorner(row, col);

  } else {
    return countNeighborsNoEdge(row, col); //Normal non edge case scenario
  }
}

//Counts the neighbors of given cell that is not touching the edge of the board, this case is the same for all game modes
int GameMode::countNeighborsNoEdge(int row, int col) {
  int count = 0;
  //Checks the 8 sourrounding positions
    count += isPosAlive(row-1, col-1);
    count += isPosAlive(row-1, col);
    count += isPosAlive(row-1, col+1);
    count += isPosAlive(row, col-1);
    count += isPosAlive(row, col+1);
    count += isPosAlive(row+1, col-1);
    count += isPosAlive(row+1, col);
    count += isPosAlive(row+1, col+1);
    return count;
}

//Checks if given cell contains char 'X'
int GameMode::isPosAlive(int row, int col) {
  return (currentGen->getPos(row, col)) == 'X';
}

//Swaps references of current generation and next generation
void GameMode::swapBoards() {

  GameBoard* temp = currentGen;
  currentGen = nextGen;


  nextGen = temp;

}

//Handles user input related to loading a file into the game
void GameMode::loadFile() {
  //Prompts for file to open
  cout << "Enter file name/file path of text file: " << endl;
  string fileName = "";
  cin >> fileName;

  fstream inFile;
  string stringBoard = "";

  //Creates and opens file object
  inFile.open(fileName);

  //If successfully opened
  if (inFile.is_open()) {
    string cur = "";
    getline(inFile, cur);
    rows = stoi(cur);
    getline(inFile, cur);
    cols = stoi(cur);
    while(getline(inFile, cur)) {
        stringBoard += cur;
    }
    inFile.close();
  }

   currentGen = new GameBoard(rows, cols, stringBoard);
}

//Returns a string of current generation game board
string GameMode::curGenToString() {
  return currentGen->toString();
}
