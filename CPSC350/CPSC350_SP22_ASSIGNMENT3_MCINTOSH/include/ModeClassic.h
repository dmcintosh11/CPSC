//Header file for ModeClassic.cpp
//Subclass of GameMode that creates rules for classic mode
#if !defined MODECLASSIC_H
#define MODECLASSIC_H

#include "GameMode.h"

class ModeClassic : public GameMode {
protected:
  //Methods to count neighbors for each edge case
   int topLeftCorner(int row, int column);
   int topRightCorner(int row, int column);
   int bottomLeftCorner(int row, int column);
   int bottomRightCorner(int row, int column);
   int bottomEdgeNotCorner(int row, int column);
   int topEdgeNotCorner(int row, int column);
   int leftEdgeNotCorner(int row, int column);
   int rightEdgeNotCorner(int row, int column);

public:
  //Constructor and destructor
  ModeClassic();
  ~ModeClassic();

};

#endif
