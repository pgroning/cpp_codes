#include <iostream>

using namespace std;

const int n = 47;

int fib(int n) {
  
  if (n <= 2) {
    return 1;
  }
  else{
    return fib(n-1) + fib(n-2);
  }
  
}


int mem[n] = {0};
int fib2(int n) {

  if (mem[n] > 0) {
    return mem[n];
  }
  else {
    if (n <= 2) {
      mem[n] = 1;
    }
    else {
      mem[n] = fib2(n-1) + fib2(n-2);
    }
    return mem[n];  
  }
}

int main() {
  
  for (int i = 1 ; i < n; i++) {
    cout << fib2(i) << endl;
  }
  
  return 0;
}

