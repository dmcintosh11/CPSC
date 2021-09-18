#include <iostream>
#include <cmath>

using namespace std;
int main() {
  double dTwelfthRootOfTwo = 1.059463094359;
  long iTwoRaisedToPowerNu = 1;
  int nu = 0;
  int k = 0;
  double currentFreq = 0;
  static int soundSpeed = 345;
  static double referenceFreq = 16.35;

  cout << "Reference Frequency: " << referenceFreq << " Hz" << endl;
  cout << "Speed of Sound: " << soundSpeed << " m/s" << endl;

  currentFreq = referenceFreq;
  cout << "Note: C0; nu: " << nu << "; k: " << k << "; Frequency: " << referenceFreq << " Hz; Wavelength: " << soundSpeed/currentFreq * 100 << " cm" << endl;

  nu = 0;
  k = 1;
  iTwoRaisedToPowerNu = pow(2, nu);
  currentFreq = referenceFreq * iTwoRaisedToPowerNu * pow(dTwelfthRootOfTwo, k);
  cout << "Note: C#0; nu: " << nu << "; k: " << k << "; Frequency: " << currentFreq << " Hz; Wavelength: " << soundSpeed/currentFreq * 100 << " cm" << endl;

  nu = 0;
  k = 2;
  iTwoRaisedToPowerNu = pow(2, nu);
  currentFreq = referenceFreq * iTwoRaisedToPowerNu * pow(dTwelfthRootOfTwo, k);
  cout << "Note: D0; nu: " << nu << "; k: " << k << "; Frequency: " << currentFreq << " Hz; Wavelength: " << soundSpeed/currentFreq * 100 << " cm" << endl;

  nu = 4;
  k = 0;
  iTwoRaisedToPowerNu = pow(2, nu);
  currentFreq = referenceFreq * iTwoRaisedToPowerNu * pow(dTwelfthRootOfTwo, k);
  cout << "Note: C4; nu: " << nu << "; k: " << k << "; Frequency: " << currentFreq << " Hz; Wavelength: " << soundSpeed/currentFreq * 100 << " cm" << endl;

  nu = 7;
  k = 3;
  iTwoRaisedToPowerNu = pow(2, nu);
  currentFreq = referenceFreq * iTwoRaisedToPowerNu * pow(dTwelfthRootOfTwo, k);
  cout << "Note: D#7; nu: " << nu << "; k: " << k << "; Frequency: " << currentFreq << " Hz; Wavelength: " << soundSpeed/currentFreq * 100 << " cm" << endl;

  nu = 8;
  k = 0;
  iTwoRaisedToPowerNu = pow(2, nu);
  currentFreq = referenceFreq * iTwoRaisedToPowerNu * pow(dTwelfthRootOfTwo, k);
  cout << "Note: C8; nu: " << nu << "; k: " << k << "; Frequency: " << currentFreq << " Hz; Wavelength: " << soundSpeed/currentFreq * 100 << " cm" << endl;
}
