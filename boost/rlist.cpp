#include "boost/filesystem.hpp"
#include <iostream>

using namespace std;
using namespace boost::filesystem;

int main () {

  //path p(".");

  for (recursive_directory_iterator end, dir("./"); dir != end; ++dir ) {
    cout << dir->path().string() << endl;  // full path
    //std::cout << dir->path().filename() << "\n"; // just last bit
  }
  

  return 0;
}
