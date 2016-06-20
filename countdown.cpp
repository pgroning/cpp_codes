#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
//#include <thread>
//#include <chrono>

using namespace std;

inline string concatenate (const string& a, const string& b)
{
  return a+b;
}


int main()
{

  string instr; 
  int a;
  cout << "Give a number to countdown : ";
  getline(cin,instr);
  stringstream(instr) >> a;

  /*  while (a > 0) {
    cout << a << "," << flush;
    --a;
    usleep(1000 * 1000); // takes microseconds
  }
  cout << 0 << endl;
  */
  do {
    cout << a << "," << flush;
    --a;
    usleep(1000 * 1000); // takes microseconds
  } while (a > 0);
  cout << 0 << endl;

  string cstr = concatenate("hello ","world");
  cout << cstr << endl;

  return 0;
}
