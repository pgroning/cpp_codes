/* Search file tree recursively to find duplicate files */

#include <iostream>
#include <list>
#include "boost/filesystem.hpp"

using namespace std;
using namespace boost::filesystem;

int main(int argc, char* argv[]) {

  string path1 = argc > 1 ? argv[1] : ".";

  cout << "Find duplicte files in top directory: " << path1 <<  endl;
  
  /*
  if (argc > 1) {
    path1 = argv[1];
    cout << "Directory: " << path1 << endl;
    
    char** p;
    p = argv;
    p++;
    cout << "Directory :" << *p << endl;
  }
  */
    
  list<string> filelist;  // list of strings
  list<string>::iterator ptr;

  // List all files recursivley and store in list
  try {
    for (recursive_directory_iterator end, dir(path1); dir != end; ++dir ) {
      //cout << dir->path().string() << endl;  // full path
      //std::cout << dir->path().filename() << "\n"; // just last bit
      
      filelist.push_back(dir->path().string()); // Store file path in list
      
    } 
  } // catch 'permission denied' cases
  catch(boost::filesystem::filesystem_error &ex){std::cout << ex.what() << "\n";}
  
  filelist.sort();
  
  //ptr = filelist.begin();
  //for (int i = 0; i < filelist.size(); i++)
  //  cout << *ptr++ << endl;

  ptr = filelist.begin();
  cout << file_size(*ptr) << endl;
  
  for (ptr = filelist.begin(); ptr != filelist.end(); ptr++) {
    if (!is_directory(*ptr))
      cout << *ptr << " size " << file_size(*ptr) << " bytes"<< endl;
  }

  cout << "Number of files: " << filelist.size() << endl;
  
  /*
  filelist.push_front("Hello");
  filelist.push_back("World");
  ptr = filelist.begin();
  cout << *ptr++ << endl;
  cout << *ptr << endl;
  */
}
