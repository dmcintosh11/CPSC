/// @file leibnitz_pi_converge.cpp
/// @brief Prints a more accurate value of pi in each iteration
/// @author Dylan McIntosh
#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;

int main() {
  double piOver4 = 0;
  int k = 0;

  cout << fixed;
  cout << setprecision(DBL_DIG);

  for(int n = 2; n <= 1048576; n*=2) {
    for(k = 0; k <= n; k++) {
      piOver4 += (pow(-1.0, k)) / ((2 * k) + 1);
    }
    cout << "PI: " << piOver4 * 4 << "; n: " << n << endl;

    piOver4 = 0;
  }


}
