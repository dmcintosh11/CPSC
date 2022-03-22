//Implementation of ModeDoughnut.h
#include "ModeDoughnut.h"

//Constructor
ModeDoughnut::ModeDoughnut() {

}

//Destructor
ModeDoughnut::~ModeDoughnut() {

}

//Returns neighbors for top left corner cell
int ModeDoughnut::topLeftCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row, column + 1);
  count += isPosAlive(row + 1, column);
  count += isPosAlive(row + 1, column + 1);

  count += isPosAlive(rows - 1, cols - 1);
  count += isPosAlive(rows - 1, column);
  count += isPosAlive(rows - 1, column + 1);
  count += isPosAlive(row, cols - 1);
  count += isPosAlive(row + 1, cols - 1);
  return count;
}
//Returns neighbors for top right corner cell
int ModeDoughnut::topRightCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row, column - 1);
  count += isPosAlive(row + 1, column - 1);
  count += isPosAlive(row + 1, column);

  count += isPosAlive(rows - 1, 0);
  count += isPosAlive(rows - 1, column);
  count += isPosAlive(rows - 1, column - 1);
  count += isPosAlive(row, 0);
  count += isPosAlive(row + 1, 0);
  return count;
}
//Returns neighbors for bottom left corner cell
int ModeDoughnut::bottomLeftCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column + 1);
  count += isPosAlive(row, column + 1);

  count += isPosAlive(rows - 1, cols - 1);
  count += isPosAlive(0, column);
  count += isPosAlive(0, column + 1);
  count += isPosAlive(0, cols - 1);
  count += isPosAlive(row - 1, cols - 1);
  return count;
}
//Returns neighbors for bottom right corner cell
int ModeDoughnut::bottomRightCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column - 1);
  count += isPosAlive(row, column - 1);

  count += isPosAlive(0, 0);
  count += isPosAlive(row, 0);
  count += isPosAlive(row - 1, 0);
  count += isPosAlive(0, column);
  count += isPosAlive(0, column - 1);
  return count;
}
//Returns neighbors for bottom edge cell
int ModeDoughnut::bottomEdgeNotCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row, column - 1);
  count += isPosAlive(row - 1, column - 1);
  count += isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column + 1);
  count += isPosAlive(row, column + 1);

  count += isPosAlive(0, column);
  count += isPosAlive(0, column + 1);
  count += isPosAlive(0, column - 1);

  return count;
}

//Returns neighbors for top edge cell
int ModeDoughnut::topEdgeNotCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row, column - 1);
  count += isPosAlive(row + 1, column - 1);
  count += isPosAlive(row + 1, column);
  count += isPosAlive(row + 1, column + 1);
  count += isPosAlive(row, column + 1);

  count += isPosAlive(rows - 1, column);
  count += isPosAlive(rows - 1, column + 1);
  count += isPosAlive(rows - 1, column - 1);

  return count;
}
//Returns neighbors for left edge cell
int ModeDoughnut::leftEdgeNotCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row, column + 1);
  count += isPosAlive(row - 1, column + 1);
  count += isPosAlive(row - 1, column);
  count += isPosAlive(row + 1, column + 1);
  count += isPosAlive(row + 1, column);

  count += isPosAlive(row, cols - 1);
  count += isPosAlive(row - 1, cols - 1);
  count += isPosAlive(row + 1, cols - 1);

  return count;
}
//Returns neighbors for right edge cell
int ModeDoughnut::rightEdgeNotCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row + 1, column);
  count += isPosAlive(row + 1, column - 1);
  count += isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column - 1);
  count += isPosAlive(row, column - 1);

  count += isPosAlive(row, 0);
  count += isPosAlive(row - 1, 0);
  count += isPosAlive(row + 1, 0);

  return count;
}
