#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

using namespace std;
using namespace boost::filesystem;

void help();

int main(int argc, char* argv[]) {

  string inarg;
  
  /* Get input parameters */
  if (argc > 1 && !strcmp(argv[1], "-h")) {
    help(); // call help function
    exit(0);
  }

  path p(argc>1? argv[1] : ".");
  
  if (is_directory(p)) {
    cout << p << " is a directory containing:\n";

    for (auto& f : boost::make_iterator_range(directory_iterator(p), {})) {
      cout << canonical(f.path()).string() << endl;
    }
  }
  else {
    if (exists(p)) {
      cout << canonical(p).string() << endl;
    }
    else {
      cout << "clsp: cannot access '" << p.string() << \
	"' : No such file or directory\n";
    }
  }
  
  /*
  path path("../a.out");
  
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


void help() {
  cout << "clsp:\n";
  cout << "Converting relative to absolute file paths using the boost C++ \
library.\n\n";
  cout << "Usage: clsp [Options]... [ARGS]...\n\n";
  cout << "Options:\n";
  cout << "-h     : Show this help message and exit\n";
  cout << "\nWritten by P. Groningsson\n";
}
