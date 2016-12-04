/* Search file tree recursively to find duplicate files */

#include <iostream>
#include <list>
#include "boost/filesystem.hpp"
//#include <limits.h>

using namespace std;
using namespace boost::filesystem;

list<string> get_filelist(string path);
list<long> get_sizelist(list<string> filelist);

int main(int argc, char* argv[]) {

  list<string> filelist1;  // list of strings
  list<string> filelist2;
  list<string>::iterator file_ptr;
  //list<string>::iterator file_ptr2;
  
  list<long> sizelist1;
  list<long> sizelist2;
  list<long>::iterator size_ptr1;
  list<long>::iterator size_ptr2;

  string path1 = argc > 1 ? argv[1] : ".";
  string path2 = argc > 2 ? argv[2] : "";
  
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
    
  
  /*
  // List all files recursivley and store in list
  try {
    for (recursive_directory_iterator end, dir(path1); dir != end; ++dir ) {
      //std::cout << dir->path().filename() << "\n"; // just last bit
      if (!is_directory(dir->path().string())) { // Store file path in list if not directory
	filelist1.push_back(dir->path().string()); 
	//sizelist1.push_back(file_size(dir->path().string()));
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

  filelist1.sort();
  
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
  
  for (file_ptr1 = filelist1.begin(); file_ptr1 != filelist1.end(); file_ptr1++){
    //  cout << *file_ptr++ << endl;
    cout << *file_ptr1 << endl;
  }
  cout << "Number of files: " << filelist1.size() << endl;
  */

  filelist1 = get_filelist(path1);
  // get file sizes and store results in a list
  for (file_ptr = filelist1.begin(); file_ptr != filelist1.end(); file_ptr++) {
    sizelist1.push_back(file_size(*file_ptr));
  }

  if (argc > 2) {
    filelist2 = get_filelist(path2);
    for (file_ptr = filelist2.begin(); file_ptr != filelist2.end(); file_ptr++) {
      sizelist2.push_back(file_size(*file_ptr));
    }
  }

  
  
  /*
  list<long> sizelist = get_sizelist(filelist);
  size_ptr1 = sizelist.begin();
  for (file_ptr1 = filelist.begin(); file_ptr1 != filelist.end(); file_ptr1++){
    //  cout << *file_ptr++ << endl;
    cout << *file_ptr1 << endl;
    cout << "size : " << *size_ptr1++ << " B" << endl;
  }
  cout << "Number of files: " << filelist.size() << endl;
  */
  
  
  
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

list<string> get_filelist(string path) {

  list<string> filelist;

  // List all files recursivley and store in list
  try {
    for (recursive_directory_iterator end, dir(path); dir != end; ++dir ) {
      //std::cout << dir->path().filename() << "\n"; // just last bit
      if (!is_directory(dir->path().string())) { // Store file path in list if not directory
	filelist.push_back(dir->path().string()); 
	//sizelist1.push_back(file_size(dir->path().string()));
      }
    } 
  } // catch 'permission denied' cases
  catch(filesystem_error &ex){cout << ex.what() << "\n";}

  filelist.sort();
  return filelist;
}
