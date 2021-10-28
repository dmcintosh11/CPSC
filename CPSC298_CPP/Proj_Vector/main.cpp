#include "Vector3D.h"
//#include <vector>
#include <iostream>
#include <math.h>

int main() {

  double const PI = 3.14159265;

  double Fx = 10.0 * std::cos(45 * PI/180.0);
  double Fy = 10.0 * std::sin(45 * PI/180.0);
  double Fz = 0;

  double Dx = 10.0;
  double Dy = 0.0;
  double Dz = 0.0;

  Vector3D vec3dForce(Fx, Fy, Fz);
  Vector3D vec3dDisplacement(Dx, Dy, Dz);

  vec3dForce.display();
  vec3dDisplacement.display();

  double dWork = vec3dForce.dot(vec3dDisplacement);
  std::cout << "Work: " << dWork << std::endl;

  return 0;
}
