#if !defined(CIRCLE_H)
#define CIRCLE_H

#include "Shape.h"

class Circle: public Shape {
public:
    Circle(double dHeight, double dWidth);
    virtual ~Circle();
    void scale(double dScaleFactor);
    double area();
    double perimeter();

};

#endif
