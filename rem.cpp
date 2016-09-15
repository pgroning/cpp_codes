#include <iostream>

using namespace std;

int main()
{

  /*  string piguess;
  cout << "What number is pi? :" << endl;
  getline(cin, piguess);

  cout << "Your guess is " << stof(piguess) << endl;

  if (stod(piguess) == 3.14) {
    cout << "...and you're right!" << endl;
  }
  else {
    cout << "You're wrong!" << endl;
  }
  */

  const double PI = 3.141592653589793;
  cout << "Pi is " + to_string(PI) << endl;
  
  return 0;
}
