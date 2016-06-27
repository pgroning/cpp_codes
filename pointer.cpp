#include <iostream>
using namespace std;

int main(){

  int v[3] = {1,2,3};
  
  int *p0 = &v[0];
  int *p1 = &v[1];
  int *p2 = &v[2];
  
  cout << "p0 = " << p0 << endl;
  cout << "p1 = " << p1 << endl;
  cout << "p2 = " << p2 << endl;

  cout << "\n";
  cout << *(p0+1) << endl;
  
}
