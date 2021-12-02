#include "Circle.h"
#include <math.h>

Circle::Circle(double dHeight, double dWidth) : Shape(dHeight, dWidth) {
  strType = "Circle";
}

Circle::~Circle() {

}

void Circle::scale(double dScaleFactor) {
  height *= dScaleFactor;
  width *= dScaleFactor;
}

double Circle::perimeter() {
  return M_PI * width;
}

double Circle::area() {
  return .25 * M_PI * pow(width, 2);
}
