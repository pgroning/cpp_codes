#include <iostream>
using namespace std;

class saying
{
public:
  void say()
  {
    cout << "cool saying" << endl;
  }
};


int main()
{
  saying sayobj;
  sayobj.say();
  return 0;
}
