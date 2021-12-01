#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

int main() {
  Rectangle* shapeRectangle = new Rectangle(2.0, 3.0);
  Circle* shapeCircle = new Circle(2.0, 2.0);

  Shape* shapes[2];

  shapes[0] = shapeCircle;
  shapes[1] = shapeRectangle;

  for(int i = 0; i < 2; ++i) {
    shapes[i]->displayProperties();
    std::cout << "Area: " << shapes[i]->area() << ", Perimeter: " << shapes[i]->perimeter() << std::endl;
    shapes[i]->scale(2);
    shapes[i]->displayProperties();
    std::cout << "Area: " << shapes[i]->area() << ", Perimeter: " << shapes[i]->perimeter() << std::endl;
  }

  delete shapes[0];
  delete shapes[1];

  return 0;
}
