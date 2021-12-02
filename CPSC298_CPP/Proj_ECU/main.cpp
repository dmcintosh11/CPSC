#include <iostream>
#include "ElectronicControlUnit.h"


int main() {

  ElectronicControlUnit* ECU = new ElectronicControlUnit();

  std::cout << "Enter X to turn of ignition or enter a steering wheel button (A, B or E)" << std::endl;
  std::cout << "\t\t(A)\n\t(F)\t(G)\t(B)\n\t(E)\t\t(E)\n\t\t(D)" << std::endl;

  char in = 'o';
  std::cin >> in;

  while(in != 'x' && in != 'X') {
    std::cout << "\t\t(A)\n\t(F)\t(G)\t(B)\n\t(E)\t\t(E)\n\t\t(D)" << std::endl;
    ECU->handleCommand(in);
    std::cin >> in;
  }

  std::cout << "Program terminated" << std::endl;

  return 0;
}
