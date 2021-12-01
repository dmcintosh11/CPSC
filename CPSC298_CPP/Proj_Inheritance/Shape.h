#if !defined(SHAPE_H)
#define SHAPE_H

#include <string>

class Shape {
public:
  Shape(double dHeight, double dWidth);
  virtual ~Shape();
  virtual void scale(double scaleFactor) = 0;
  virtual double area() = 0;
  virtual double perimeter() = 0;
  virtual void displayProperties();

protected:
  double height;
  double width;
  std::string strType;

};

#endif
