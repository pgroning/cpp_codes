/* Search file tree recursively to find duplicate files */

#include <iostream>
#include <list>
#include "boost/filesystem.hpp"
//#include <limits.h>

using namespace std;
using namespace boost::filesystem;

int main(int argc, char* argv[]) {

  list<string> filelist1;  // list of strings
  list<string> filelist2;
  list<string>::iterator file_ptr1;
  list<string>::iterator file_ptr2;
  
  list<long> sizelist1;
  list<long> sizelist2;
  list<long>::iterator size_ptr1;
  list<long>::iterator size_ptr2;

  string path1 = argc > 1 ? argv[1] : ".";
  string path2 = argc > 2 ? argv[2] : path1;
  
  cout << "Find duplicte files under directories: " << endl;
  cout << path1 <<  endl;
  cout << path2 <<  endl;
  
  /*
  if (argc > 1) {    
    char** p;
    p = argv;
    p++;
    cout << "Directory :" << *p << endl;
  }
  */
    
  
  
  // List all files recursivley and store in list
  try {
    for (recursive_directory_iterator end, dir(path1); dir != end; ++dir ) {
      //std::cout << dir->path().filename() << "\n"; // just last bit
      if (!is_directory(dir->path().string())) { // Store file path in list if not directory
	filelist1.push_back(dir->path().string()); 
	sizelist1.push_back(file_size(dir->path().string()));
      }
    } 
  } // catch 'permission denied' cases
  catch(filesystem_error &ex){cout << ex.what() << "\n";}

  try {
    for (recursive_directory_iterator end, dir(path2); dir != end; ++dir ) {
      //std::cout << dir->path().filename() << "\n"; // just last bit
      if (!is_directory(dir->path().string())) { // Store file path in list if not directory
	filelist2.push_back(dir->path().string()); 
	sizelist2.push_back(file_size(dir->path().string()));
      }
    } 
  } // catch 'permission denied' cases
  catch(filesystem_error &ex){cout << ex.what() << "\n";}

  
  //filelist.sort();
  
  //file_ptr = filelist.begin();
  //for (int i = 0; i < filelist.size(); i++)
  //  cout << *file_ptr++ << endl;

  
  
  //file_ptr1 = filelist1.begin();
  //for (file_ptr = filelist.begin(); file_ptr != filelist.end(); file_ptr++) {
    //if (! is_directory(*file_ptr))
    //sizelist.push_back(file_size(*file_ptr));
    //cout << *file_ptr << " size " << file_size(*file_ptr) << " bytes"<< endl;
  //}

  // list files and corresponding sizes
  //file_ptr = filelist.begin();
  
  for (size_ptr1 = sizelist1.begin(); size_ptr1 != sizelist1.end(); size_ptr1++){
    //  cout << *file_ptr++ << endl;
    cout << *size_ptr1 << endl;
  }
  cout << "Number of files: " << filelist1.size() << endl;


  
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
