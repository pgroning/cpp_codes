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
  list<string>::iterator file_ptr1;
  list<string>::iterator file_ptr2;
  
  list<long> sizelist1;
  list<long> sizelist2;
  list<long>::iterator size_ptr1;
  list<long>::iterator size_ptr2;

  list<string> matchlist1;
  list<string> matchlist2;
  
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
    
  
  filelist1 = get_filelist(path1);
  // get file sizes and store results in a list
  for (file_ptr1 = filelist1.begin(); file_ptr1 != filelist1.end(); file_ptr1++) {
    sizelist1.push_back(file_size(*file_ptr1));
  }

  if (argc > 2) { // compare files between two file trees
    filelist2 = get_filelist(path2);
    for (file_ptr2 = filelist2.begin(); file_ptr2 != filelist2.end(); file_ptr2++)
      sizelist2.push_back(file_size(*file_ptr2));
   
    file_ptr1 = filelist1.begin();
    for (size_ptr1=sizelist1.begin(); size_ptr1!=sizelist1.end(); size_ptr1++) {
      
      file_ptr2 = filelist2.begin();
      for (size_ptr2=sizelist2.begin(); size_ptr2!=sizelist2.end(); size_ptr2++) {
	
	if (*size_ptr1 > 0  && *size_ptr1 == *size_ptr2) { // check if file sizes match
	  matchlist1.push_back(*file_ptr1);
	  matchlist2.push_back(*file_ptr2);
	  //cout << *size_ptr1 << " " << *size_ptr2 << endl;
	  //cout << *file_ptr1 << " " << *file_ptr2 << endl;
	}
	file_ptr2++;
      }
      file_ptr1++;
    }
      
  }
  else { // compare files within a single file tree
    file_ptr1 = filelist1.begin();
    for (size_ptr1=sizelist1.begin(); size_ptr1!=sizelist1.end(); size_ptr1++) {
      size_ptr2 = size_ptr1;
      size_ptr2++;  // avoid comparing a file against itself
      file_ptr2 = file_ptr1;
      file_ptr2++;
      for (; size_ptr2!=sizelist1.end(); size_ptr2++) {
	if (*size_ptr1 > 0 && *size_ptr1 == *size_ptr2) { // check if file sizes match
	  matchlist1.push_back(*file_ptr1);
	  matchlist2.push_back(*file_ptr2);
	  //cout << *size_ptr1 << " " << *size_ptr2 << endl;
	  //cout << *file_ptr1 << " " << *file_ptr2 << endl;
	}
	file_ptr2++;
      }
      file_ptr1++;
    }
  }

  file_ptr2 = matchlist2.begin();
  for (file_ptr1 = matchlist1.begin(); file_ptr1 != matchlist1.end(); file_ptr1++) {
    cout << *file_ptr1 << " : " << *file_ptr2 << endl;
    file_ptr2++;
  }
  
  // cout << "Number of files: " << filelist.size() << endl;
  
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
