#include "CentralPolygonalNumbers.h"
#include <iostream>
#include <string>
#include <fstream>

CentralPolygonalNumbers::CentralPolygonalNumbers() {
  max = 0;
  nums = new int[max + 1];

  for(int i = 0; i <= max; ++i) {
    nums[i] = ((i * i) + i + 2) / 2;
  }
}

CentralPolygonalNumbers::CentralPolygonalNumbers(int m) {
  max = m;
  nums = new int[max + 1];

  for(int i = 0; i <= max; ++i) {
    nums[i] = ((i * i) + i + 2) / 2;
  }
}

CentralPolygonalNumbers::~CentralPolygonalNumbers() {
  delete[] nums;
  std::cout << "~CentralPolygonalNumbers called" << std::endl;
}

void CentralPolygonalNumbers::display() {
  for(int i = 0; i <= max; ++i) {
    std::cout << "n: " << i << "; Max number of pieces: " << nums[i] << std::endl;
  }
}

bool CentralPolygonalNumbers::save(std::string fileName) {
  std::ofstream ofsNumbers;
  ofsNumbers.open(fileName);

  for(int i = 0; i <= max; ++i) {
    ofsNumbers << nums[i] << std::endl;
  }

  ofsNumbers.close();
}
