#include <iostream>

using namespace std;

main()
{

  string s[2];

  s[0] = "Hello C++";
  s[1] = "My string example";

  for (int i=0;i<2;i++) {
    cout << s[i] << endl;
  }

  cout << "Dimension of string array = " << sizeof(s)/sizeof(*s) << endl;
  cout << *s << endl;

  cout << "--------" << endl;

  char const * p[] = {"Hello C++","My string example"};

  char const **pp = p;
  *pp = "tjena ba";
  for (int i=0;i<2;i++) {
    pp++;
    cout << *pp << endl;
  }
  cout << "----------" << endl;

  int j = 77;
  int *pj = &j;
  cout << ++*pj << endl;


  return 0;
}

