#if !defined(VECTOR3D_H)
#define VECTOR3D_H


#include <vector>

class Vector3D {
  public:
    Vector3D();
    Vector3D(double dX, double dY, double dZ);
    ~Vector3D();
    double dot(Vector3D vec3d);
    void display();

  private:
    std::vector<double> m_vector = {0, 0, 0};

};

#endif
