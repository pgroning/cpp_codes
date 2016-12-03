/* Search file tree recursively to find duplicate files */

#include <iostream>
#include <list>
#include "boost/filesystem.hpp"

using namespace std;
using namespace boost::filesystem;

int main() {

  cout << "Find duplicte files" << endl;

  list<string> filelist;  // list of strings
  list<string>::iterator ptr;

  // List all files recursivley and store in list
  for (recursive_directory_iterator end, dir("./"); dir != end; ++dir ) {
    //cout << dir->path().string() << endl;  // full path
    //std::cout << dir->path().filename() << "\n"; // just last bit
    filelist.push_back(dir->path().string()); // Store file path in list
  }
  filelist.sort();
  
  //ptr = filelist.begin();
  //for (int i = 0; i < filelist.size(); i++)
  //  cout << *ptr++ << endl;

  for (ptr = filelist.begin(); ptr != filelist.end(); ptr++)
    cout << *ptr << endl;
  
  /*
  filelist.push_front("Hello");
  filelist.push_back("World");
  ptr = filelist.begin();
  cout << *ptr++ << endl;
  cout << *ptr << endl;
  */
}
