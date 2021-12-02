#if !defined(CENTRALPOLYGONALNUMNERS_H)
#define CENTRALPOLYGONALNUMNERS_H

#include <string>

class CentralPolygonalNumbers {
  public:
    CentralPolygonalNumbers();
    CentralPolygonalNumbers(int m);
    ~CentralPolygonalNumbers();
    void display();
    bool save(std::string fileName);

  private:
    int max;
    int* nums;
};

#endif
