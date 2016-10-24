/* Search file tree recursively to find duplicate files */

#include <iostream>
#include <list>

using namespace std;

int main() {

  cout << "Find duplicte files" << endl;

  list<string> filelist;  // list of strings
  list<string>::iterator ptr;
  filelist.push_front("Hello");
  filelist.push_back("World");
  ptr = filelist.begin();
  cout << *ptr++ << endl;
  cout << *ptr << endl;
}
