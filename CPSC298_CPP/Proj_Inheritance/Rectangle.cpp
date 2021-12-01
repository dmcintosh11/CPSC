#include "Rectangle.h"

Rectangle::Rectangle(double dHeight, double dWidth) : Shape(dHeight, dWidth) {
  strType = "Rectangle";
}

Rectangle::~Rectangle(){

}

void Rectangle::scale(double dSccaleFactor) {
  height *= 2;
  width *= 2;
}

double Rectangle::perimeter() {
  return (width * 2) + (height * 2);
}

double Rectangle::area() {
  return width * height;
}
