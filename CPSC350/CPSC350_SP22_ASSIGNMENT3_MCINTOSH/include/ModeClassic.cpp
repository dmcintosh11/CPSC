//Implementation of ModeClassic.h
#include "ModeClassic.h"

//Constructor
ModeClassic::ModeClassic() {

}

//Destructor
ModeClassic::~ModeClassic() {

}

//Returns neighbors for top left corner cell
int ModeClassic::topLeftCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row, column + 1);
  count += isPosAlive(row + 1, column);
  count += isPosAlive(row + 1, column + 1);
  return count;
}
//Returns neighbors for top right corner cell
int ModeClassic::topRightCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row, column - 1);
  count += isPosAlive(row + 1, column - 1);
  count += isPosAlive(row + 1, column);
  return count;
}
//Returns neighbors for bottom left corner cell
int ModeClassic::bottomLeftCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column + 1);
  count += isPosAlive(row, column + 1);
  return count;
}
//Returns neighbors for bottom right corner cell
int ModeClassic::bottomRightCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column - 1);
  count += isPosAlive(row, column - 1);
  return count;
}
//Returns neighbors for bottom edge cell
int ModeClassic::bottomEdgeNotCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row, column - 1);
  count += isPosAlive(row - 1, column - 1);
  count += isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column + 1);
  count += isPosAlive(row, column + 1);

  return count;
}
//Returns neighbors for top edge cell
int ModeClassic::topEdgeNotCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row, column - 1);
  count += isPosAlive(row + 1, column - 1);
  count += isPosAlive(row + 1, column);
  count += isPosAlive(row + 1, column + 1);
  count += isPosAlive(row, column + 1);

  return count;
}
//Returns neighbors for left edge cell
int ModeClassic::leftEdgeNotCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row, column + 1);
  count += isPosAlive(row - 1, column + 1);
  count += isPosAlive(row - 1, column);
  count += isPosAlive(row + 1, column + 1);
  count += isPosAlive(row + 1, column);

  return count;
}
//Returns neighbors for right edge cell
int ModeClassic::rightEdgeNotCorner(int row, int column){
  int count = 0;
  count += isPosAlive(row + 1, column);
  count += isPosAlive(row + 1, column - 1);
  count += isPosAlive(row - 1, column);
  count += isPosAlive(row - 1, column - 1);
  count += isPosAlive(row, column - 1);

  return count;
}
