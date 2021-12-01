#include "Shape.h"
#include <iostream>

Shape::Shape(double dHeight, double dWidth) {
  height = dHeight;
  width = dWidth;
  strType = "Shape";
}



Shape::~Shape(){

}

void Shape::displayProperties() {

  std::cout << "Shape type: " << strType << "; Height: " << height << "; Width: " << width << std::endl;
}
