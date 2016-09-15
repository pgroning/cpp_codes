#include <iostream>
#include <vector>

using namespace std;

int main()
{
  cout << "Working with vector object" << endl;

  vector<double> myvec(10);
  myvec.resize(7);
  
  myvec[3] = 2.17;
  myvec.insert(myvec.begin()+5,3.14);
  for (int i = 0; i < myvec.size(); i++) {
    cout << myvec.at(i) << endl;
  }

  cout << "-------------" << endl;

  vector<double>::iterator i;
  for (i = myvec.begin(); i != myvec.end(); i++) {
    cout << *i << endl;
  }

  cout << "-------------" << endl;

  vector<string> strvec;

  strvec.insert(strvec.end(),"kalle");
  strvec.insert(strvec.end(),"oskar");
  
  for (vector<string>::iterator i = strvec.begin(); i != strvec.end(); i++) {
    cout << *i << endl;
  }

  return 0;
}

