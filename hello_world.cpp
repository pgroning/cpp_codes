// Hello world program

#include <iostream>
using namespace std;

int main()
{
  int slen;
  char s[] = "tjoohoo";
  string str1 = "greetings";
  string str2 = "everyone";
  string str3;

  slen = str1.size();

  str3 = str1 + " " + str2 + "!";

  cout << "Hello World program!" << endl;
  cout << "s : " << s << endl;
  cout << "str1 : " << str1 << endl;
  cout << "size of str1 = " << slen << endl;
  cout << str3 << endl;

  return 0;
}

