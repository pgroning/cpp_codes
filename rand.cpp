#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  srand(time(NULL));

  for (int i = 0; i < 20; i++)
    cout << rand() % 6 + 1 << endl;

}
