/* Search file tree recursively to find duplicate files */

#include <iostream>
#include <list>
#include "boost/filesystem.hpp"
//#include <limits.h>

using namespace std;
using namespace boost::filesystem;

int main(int argc, char* argv[]) {

  string path1 = argc > 1 ? argv[1] : ".";
  string path2 = argc > 2 ? argv[2] : path1;
  
  cout << "Find duplicte files under directory: " << path1 <<  endl;
  cout << "Find duplicte files under directory: " << path2 <<  endl;
  
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
  list<string>::iterator file_ptr;

  // List all files recursivley and store in list
  try {
    for (recursive_directory_iterator end, dir(path1); dir != end; ++dir ) {
      //cout << dir->path().string() << endl;  // full path
      //std::cout << dir->path().filename() << "\n"; // just last bit
      if (!is_directory(dir->path().string())) // Store file path in list if not directory
	filelist.push_back(dir->path().string()); 
      
    } 
  } // catch 'permission denied' cases
  catch(boost::filesystem::filesystem_error &ex){std::cout << ex.what() << "\n";}
  
  filelist.sort();
  
  //file_ptr = filelist.begin();
  //for (int i = 0; i < filelist.size(); i++)
  //  cout << *file_ptr++ << endl;

  list<long> sizelist;
  
  file_ptr = filelist.begin();
  for (file_ptr = filelist.begin(); file_ptr != filelist.end(); file_ptr++) {
    //if (! is_directory(*file_ptr))
    sizelist.push_back(file_size(*file_ptr));
    //cout << *file_ptr << " size " << file_size(*file_ptr) << " bytes"<< endl;
  }

  // list files and corresponding sizes
  file_ptr = filelist.begin();
  list<long>::iterator size_ptr;
  for (size_ptr = sizelist.begin(); size_ptr != sizelist.end(); size_ptr++){
    cout << *file_ptr++ << endl;
    cout << *size_ptr << endl;
  }
  cout << "Number of files: " << filelist.size() << endl;


  
  //long imax = LONG_MAX;
  //cout << imax << endl;
  
  /*
  filelist.push_front("Hello");
  filelist.push_back("World");
  ptr = filelist.begin();
  cout << *ptr++ << endl;
  cout << *ptr << endl;
  */
}
