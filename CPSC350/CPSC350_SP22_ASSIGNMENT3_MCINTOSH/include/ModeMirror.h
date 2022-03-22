//Header file for ModelMirror.cpp
//Subclass of GameMode.cpp that creates rules for mirror mode
#if !defined MODEMIRROR_H
#define MODEMIRROR_H

#include "GameMode.h"

class ModeMirror : public GameMode {
protected:
  //Functions to find the amount of neighbors for each edge case
   int topLeftCorner(int row, int column);
   int topRightCorner(int row, int column);
   int bottomLeftCorner(int row, int column);
   int bottomRightCorner(int row, int column);
   int bottomEdgeNotCorner(int row, int column);
   int topEdgeNotCorner(int row, int column);
   int leftEdgeNotCorner(int row, int column);
   int rightEdgeNotCorner(int row, int column);

public:
  //Constructor
  ModeMirror();
  //Destructor
  ~ModeMirror();

};

#endif
