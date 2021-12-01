#if !defined(RECTANGLE_H)
#define RECTANGLE_H

#include "Shape.h"

class Rectangle: public Shape{
public:
    Rectangle(double dHeight, double dWidth);
    virtual ~Rectangle();
    void scale(double dScaleFactor);
    double area();
    double perimeter();

};

#endif
