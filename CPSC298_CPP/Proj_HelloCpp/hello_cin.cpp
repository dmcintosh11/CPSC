/// @file hello_cin.cpp
/// @brief Outputs a string entered by the user to standard output.
/// @author Dylan McIntosh
#include <iostream>
using namespace std;
int main() {
  string strMessage;
  cout << "Please type a single word message." << endl;
  cin >> strMessage;
  cout << "Message: " << strMessage << endl; 
  return 0;
}
