#include <iostream>
#include <string>
using namespace std;

template <class T>
T sum (T a, T b)
{
  T result = a+b;
  return result;
}

int main ()
{

  int a = 3;
  int b = 4;

  int s = sum<int>(a,b);
  cout << "The sum of " << a << " and " << b << " is " << s << endl;

  string s1 = "Hello";
  string s2 = " World!";
  string str = sum(s1,s2);
  cout << str << endl;

  return 0;
}
