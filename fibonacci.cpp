#include <iostream>

using namespace std;


int fib(int n) {

  int f;
  int f2 = 0, f1 = 1;

  for (int i = 0; i < n; i++) {
    f = f1 + f2;
    f2 = f1;
    f1 = f;
  }
  
  return f;
}


int fibr(int n) {
  int f;
  
  if (n <=1) f = 1;
  else f = fibr(n-1) + fibr(n-2);
  return f;
}

int main()
{

  for (int i=1; i < 40; i++) {
    cout << fibr(i) << endl;
  }
  
  return 0;
}
