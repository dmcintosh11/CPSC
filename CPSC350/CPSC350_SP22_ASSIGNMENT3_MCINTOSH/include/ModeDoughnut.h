//Header file for ModelDoughnut.cpp
//Subclass of GameMode that creates rules for Doughnut mode
#if !defined MODEDOUGHNUT_H
#define MODEDOUGHNUT_H

#include "GameMode.h"

class ModeDoughnut : public GameMode {
protected:
  //Methods for counting neighbors in each edge case
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
  ModeDoughnut();
  ~ModeDoughnut();

};

#endif
