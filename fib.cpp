#include <iostream>
#include <vector>

using namespace std;

int n = 47;

int fib(int n) {
  
  if (n <= 2) {
    return 1;
  }
  else{
    return fib(n-1) + fib(n-2);
  }
  
}


vector<int> m(n);
int fib2(int n) {

  if (m[n] > 0) {
    return m[n];
  }
  else {
    if (n <= 2) {
      m[n] = 1;
    }
    else {
      m[n] = fib2(n-1) + fib2(n-2);
    }
  }
  return m[n];
}

int main() {
  
  for (int i = 1 ; i < n; i++) {
    cout << fib2(i) << endl;
  }
  
  return 0;
}


