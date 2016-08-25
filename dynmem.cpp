#include <iostream>
#include <new>

using namespace std;


main()
{
  int vlen;

  cout << "Enter a vector length: ";
  cin >> vlen;

  int *p;
  p = new (nothrow) int [vlen];
  if (p != 0) { // p is not null pointer -> Memory allocation succedeed
    for (int i=0;i<vlen;i++) {
      p[i] = i+1;
    }
  }

  cout << "You entered the length " << vlen << endl;
  for (int i=0; i<vlen;i++) {
    cout << p[i] << " ";
  }
  cout << "\n";

  delete[] p;

  return 0;
}
