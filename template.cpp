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

  string str = sum<string>("Hello"," World");
  cout << str << endl;

  return 0;
}
