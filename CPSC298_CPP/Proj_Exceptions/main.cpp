//#include "sigma.h"
#include <iostream>
#include <string>
#include <stdexcept>



unsigned long sigma(unsigned long n) {
  unsigned long sum = 0;

  try {
    if(n < 1) {
      std::string strMessage = "Precondition of n >= 1 violated; the value of n is invalid " + std::to_string(n) +
                                " (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";
      throw std::runtime_error(strMessage);
    }

    for(int i = 1; i <= n; ++i) {
      sum += i;
    }

    if(sum != (n*(n + 1)) / 2) {
      std::string strMessage = "Postcondition of sum == (n*(n + 1)) / 2 not met; " + std::to_string(sum) +
                                " (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";
      throw std::runtime_error(strMessage);
    }
  }

  catch(std::runtime_error & ex) {
    std::cout << "Exception: " << ex.what() << std::endl;
    std::cout << "Cannot compute sum; returning 0" << std::endl;

    sum = 0;
  }

  return sum;
}

int main() {

  int sum = sigma(5);
  std::cout << "sigma(5) = " << sum << std::endl;
  sum = sigma(0);
  std::cout << "sigma(0) = " << sum << std::endl;


  return 0;
}
