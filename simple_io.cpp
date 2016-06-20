#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

int main()
{
  string a_str;
  string str;

  cout << "Give me a number : ";
  getline(cin,a_str);

  // 1. Using cstdlib to convert to float
  float a = atof(a_str.c_str());
  cout << "You gave me the number " << a << endl;
  // 2. Using string sstream library
  float b;
  stringstream(a_str) >> b;
  cout << "You gave me the number " << b << endl;

  cout << "Now give me a string : ";
  getline(cin,str);
  cout << "You told me " << str << endl;

  return 0;
}

