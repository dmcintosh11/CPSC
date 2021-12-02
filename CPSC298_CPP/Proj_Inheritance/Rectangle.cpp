#include "Rectangle.h"

Rectangle::Rectangle(double dHeight, double dWidth) : Shape(dHeight, dWidth) {
  strType = "Rectangle";
}

Rectangle::~Rectangle(){

}

void Rectangle::scale(double dScaleFactor) {
  height *= dScaleFactor;
  width *= dScaleFactor;
}

double Rectangle::perimeter() {
  return (width * 2) + (height * 2);
}

double Rectangle::area() {
  return width * height;
}
