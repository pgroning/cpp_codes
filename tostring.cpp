#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string IntToString(int a) {
  ostringstream temp;
  temp << a;
  return temp.str();
}

template <typename T>
string NumToString(T a) {
  ostringstream s;
  s << a;
  return s.str();
}

int main()
{

  int i = 3;
  cout << IntToString(i) << endl;
  string istr = IntToString(i);
  cout << istr << endl;

  double x = 3.14;
  string nstr = NumToString(x);
  cout << nstr << endl;

  double d = stod(nstr);
  cout << d/2 << endl;

  return 0;
}
