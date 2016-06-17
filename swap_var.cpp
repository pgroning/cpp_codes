// Swap variables

#include <iostream>
using namespace std;

void int_swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


int main()
{
  int a = 3;
  int b = 7;

  cout << "Swapping integer variables a and b" << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "a + b = " << a+b << endl;
  cout << "Swapping..." << endl;
  int_swap(&a, &b);
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "a + b = " << a+b << endl;
}
