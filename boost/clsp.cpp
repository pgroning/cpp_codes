#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

using namespace std;
using namespace boost::filesystem;

void help();

class Dir {
private:
  path p;
  
public:
  Dir(path p);  // constructor
  path get_path();
  int is_absolute();
  path rel_path();
  void list_all();
};

int main(int argc, char* argv[]) {

  /* Get input parameters */
  if (argc > 1 && !strcmp(argv[1], "-h")) {
    help(); // call help function
    exit(0);
  }

  int n = argc > 1 ? argc : 2;

  for (int i = 1; i < n; i++) {

    path p(argc > 1 ? argv[i] : ".");
    Dir dir(p);
    
    if (dir.is_absolute()) {
      cout << dir.rel_path().string() << endl;
      exit(0);
    }
  
    if (is_directory(dir.get_path())) { // list all files in directory
      dir.list_all();
    }
    else {
      if (exists(dir.get_path())) {
	cout << canonical(dir.get_path()).string() << endl;
	//cout << canonical(p).string() << endl;
      }
      else {
	cout << "clsp: cannot access '" << dir.get_path().string() <<	\
	  "' : No such file or directory\n";
      }
    }
    
  }

  /*
  cout << path.string() << endl;
  cout << path.root_name().c_str() << endl;
  cout << path.root_directory().string() << endl;
  cout << path.relative_path().string() << endl;
  cout << path.parent_path().string() << endl;
  cout << path.filename().string() << endl;
  cout << path.stem().string() << endl;
  cout << path.extension().string() << endl;

  cout << "--------" << endl;
  string abspath = absolute(path).string();
  cout << abspath << endl;
  cout << canonical(path) << endl;
  cout << path.is_relative() << endl;
  cout << path.is_absolute() << endl;
  */
  return 0;
}

Dir::Dir(path p) : p(p) {} // sets the member p equal to variable p


path Dir::get_path() {
  return p;
}

int Dir::is_absolute() {
  return p.is_absolute();
}

void Dir::list_all() {

  for (auto& f : boost::make_iterator_range(directory_iterator(p), {})) {
    cout << canonical(f.path()).string() << endl;
  } 
  
}


path Dir::rel_path() {
  
  path wd("."); // current working directory
  path pwd(absolute(wd));
  if (p.root_directory() != pwd.root_directory()) {
    return p;
    //cout << p.string() << endl; // return p if root paths are different
  }
  else {
    path::const_iterator fromIter = pwd.begin();
    path::const_iterator toIter = p.begin();
    
    // Loop through both paths as long as they are the same
    while (fromIter != p.end() && toIter != pwd.end() &&	\
	   (*toIter) == (*fromIter)) {
      ++toIter;
      ++fromIter;
    }
    
    path relPath;
    ++fromIter;
    while (fromIter != pwd.end()) {
      relPath /= "..";
      ++fromIter;
    }
    while (toIter != p.end()) {
      relPath /= *toIter;
      ++toIter;
    }
    
    //cout << relPath.string() << endl;
    return relPath;
    
  }
  
}



void help() {
  cout << "clsp:\n";
  cout << "Usage: clsp [Options]... [FILE]...\n";
  cout << "List FILEs (the current directory by default) with absolute or relative paths.\nThe program is making use of the Boost C++ library.\n\n";
  
  cout << "Options:\n";
  cout << "-h     : Show this help message and exit\n";
  cout << "\nWritten by P. Groningsson\n";
}
