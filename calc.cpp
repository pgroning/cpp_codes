#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class arithmetics {

public:
  void real_add(double a, double b);
  void real_sub(double a, double b);
  void real_mult(double a, double b);
  void real_div(double a, double b);

};


void arithmetics::real_add(double a, double b) {
  double result = a+b;
  cout << result << endl;
}

void arithmetics::real_sub(double a, double b) {
  double result = a-b;
  cout << result << endl;
}

void arithmetics::real_mult(double a, double b) {
  double result = a*b;
  cout << result << endl;
}

void arithmetics::real_div(double a, double b) {
  double result = a/b;
  cout << result << endl;
}


main(int argc, char* argv[])
{
  double a = 0;
  double b = 0;
  char* op;
  string x1,x2;
  arithmetics m;

  x1 = argv[1];
  x2 = argv[3];
  op = argv[2];
  stringstream(x1) >> a;
  stringstream(x2) >> b;

  
  if (!strcmp(op,"+")) {
    m.real_add(a, b);
  }
  else if (!strcmp(op,"-")) {
    m.real_sub(a, b);
  }
  else if(!strcmp(op,"*")) {
    m.real_mult(a, b);
  }
  else if(!strcmp(op,"/")) {
    m.real_div(a, b);
  }
  else {
    cout << "Error: Unrecognized operator" << endl;
    exit(0);
  }

  return 0;
}
