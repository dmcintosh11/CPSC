//Implementation of ModeMirror
#include "ModeMirror.h"

//Constructor
ModeMirror::ModeMirror() {

}

//Destructor
ModeMirror::~ModeMirror() {

}

//Returns neighbors for top left corner cell
int ModeMirror::topLeftCorner(int row, int column){
  int count = 0;
  count += 2 * isPosAlive(row, column + 1);
  count += 2 * isPosAlive(row + 1, column);
  count += isPosAlive(row + 1, column + 1);

  count += 3 * isPosAlive(row, column);
  return count;
}
//Returns neighbors for top right corner cell
int ModeMirror::topRightCorner(int row, int column){
  int count = 0;
  count += 2 * isPosAlive(row, column - 1);
  count += isPosAlive(row + 1, column - 1);
  count += 2 * isPosAlive(row + 1, column);

  count += 3 * isPosAlive(row, column);
  return count;
}
//Returns neighbors for bottom left corner cell
int ModeMirror::bottomLeftCorner(int row, int column){
  int count = 0;
  count += 2 * isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column + 1);
  count += 2 * isPosAlive(row, column + 1);

  count += 3 * isPosAlive(row, column);
  return count;
}
//Returns neighbors for bottom right corner cell
int ModeMirror::bottomRightCorner(int row, int column){
  int count = 0;
  count += 2 * isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column - 1);
  count += 2 * isPosAlive(row, column - 1);

  count += 3 * isPosAlive(row, column);
  return count;
}
//Returns neighbors for bottom edge cell
int ModeMirror::bottomEdgeNotCorner(int row, int column){
  int count = 0;
  count += 2 * isPosAlive(row, column - 1);
  count += isPosAlive(row - 1, column - 1);
  count += isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column + 1);
  count += 2 * isPosAlive(row, column + 1);

  count += isPosAlive(row, column);

  return count;
}
//Returns neighbors for top edge cell
int ModeMirror::topEdgeNotCorner(int row, int column){
  int count = 0;
  count += 2 * isPosAlive(row, column - 1);
  count += isPosAlive(row + 1, column - 1);
  count += isPosAlive(row + 1, column);
  count += isPosAlive(row + 1, column + 1);
  count += 2 * isPosAlive(row, column + 1);

  count += isPosAlive(row, column);

  return count;
}
//Returns neighbors for top left edge cell
int ModeMirror::leftEdgeNotCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row, column + 1);
  count += isPosAlive(row - 1, column + 1);
  count += 2 * isPosAlive(row - 1, column);
  count += isPosAlive(row + 1, column + 1);
  count += 2 * isPosAlive(row + 1, column);

  count += isPosAlive(row, column);

  return count;
}
//Returns neighbors for top right edge cell
int ModeMirror::rightEdgeNotCorner(int row, int column){
  int count = 0;
  count += 2 * isPosAlive(row + 1, column);
  count += isPosAlive(row + 1, column - 1);
  count += 2 * isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column - 1);
  count += isPosAlive(row, column - 1);

  count += isPosAlive(row, column);

  return count;
}
