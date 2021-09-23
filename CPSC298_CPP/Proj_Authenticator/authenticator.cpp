/// @file Proj_MusicalNotes.cpp
/// @brief Authenticates and compares two codes
/// @author Dylan McIntosh
#include <iostream>

using namespace std;

int main() {
  const char k_cAuthenticatorCodeCharacter1 = 'E';
  const char k_cAuthenticatorCodeCharacter2 = 'C';
  const char k_cAuthenticatorCodeCharacter3 = 'A';

  string authenticator = "ECA";

  char MessageChar1;
  char MessageChar2;
  char MessageChar3;

  string message = "";

  const int checksum = 5;
  int messageChecksum;

  cout << "Enter the first character" << endl;
  cin >> MessageChar1;

  cout << "Enter the second character" << endl;
  cin >> MessageChar2;

  cout << "Enter the third character" << endl;
  cin >> MessageChar3;

  message += MessageChar1;
  message += MessageChar2;
  message += MessageChar3;

  cout << "Authenticator code: " << authenticator << endl;
  cout << "Input message: " << message << endl;

  if (MessageChar1 == k_cAuthenticatorCodeCharacter1 && MessageChar2 == k_cAuthenticatorCodeCharacter2 && MessageChar3 == k_cAuthenticatorCodeCharacter3) {
    cout << "Message is authentic" << endl;
  } else {
    cout << "Message is invalid" << endl;
  }

  if (message == authenticator) {
    cout << "Concurrence: message is authentic" << endl;
  } else {
    cout << "Concurrence: message is invalid" << endl;
  }

  messageChecksum =(int(MessageChar1) + int(MessageChar2) + int(MessageChar3)) % 7;

  cout << "------------------------" << endl << "Characterization of Message: " << endl;

  if (messageChecksum == checksum) {
    cout << "Message checksum is valid: " << checksum << endl;;
  } else {
    cout << "Message checksum is invalid: " << messageChecksum << "; Expected: " << checksum << endl; ;
  }

  cout << "ASCII values of each character in message: " << int(MessageChar1) << ", " << int(MessageChar2) << ", " << int(MessageChar3) << endl;
  cout << "Sum of ASCII values in message: " << int(MessageChar1) + int(MessageChar2) + int(MessageChar3) << endl;

  if( MessageChar1 != k_cAuthenticatorCodeCharacter1) {
    cout << "First characters do not match: Message: " << MessageChar1 << "; Auhtenticator: " << k_cAuthenticatorCodeCharacter1 << endl;
  }
  if( MessageChar2 != k_cAuthenticatorCodeCharacter2) {
    cout << "Second characters do not match: Message: " << MessageChar2 << "; Auhtenticator: " << k_cAuthenticatorCodeCharacter2 << endl;
  }
  if( MessageChar3 != k_cAuthenticatorCodeCharacter3) {
    cout << "Third characters do not match: Message: " << MessageChar3 << "; Auhtenticator: " << k_cAuthenticatorCodeCharacter3 << endl;
  }

  if( message != authenticator) {
    if (message < authenticator) {
      cout << "Message code (" << message << ") is lexicographically less than the Authenticator code (" << authenticator << ")" << endl;
    } else {
      cout << "Message code (" << message << ") is lexicographically greater than the Authenticator code (" << authenticator << ")" << endl;
    }
  }
}
