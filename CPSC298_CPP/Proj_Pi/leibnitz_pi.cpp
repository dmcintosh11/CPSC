/// @file leibnitz_pi.cpp
/// @brief Calculates an approximation of pi based on an input upper bound
/// @author Dylan McIntosh
#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;

int main() {
  int n = 0;
  double pi = 0;
  const double actualPi = 3.141592653589793;
  double piOver4 = 0;
  int k = 0;

  cout << fixed;
  cout << setprecision(DBL_DIG);
  cout << "Enter a non-negative integer for the upper limit: " << endl;
  cin >> n;

  for(k = 0; k <= n; k++) {
    piOver4 += (pow(-1.0, k)) / ((2 * k) + 1);

  }

  pi = piOver4 * 4;

  cout << "PI (approx): " << pi << "; n: " << setw(7) << n << endl;
  cout << "PI (actual): " << actualPi << endl;
  cout << "Decimal digits of precision: " << DBL_DIG << endl;
  cout << "Number of base 2 mantissa digits of double precision floating point value: " << DBL_MANT_DIG << endl;
  cout << "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793, 3.14) << endl;



}
