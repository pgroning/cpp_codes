#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

int main(int argc, char* argv[]) {
  
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
  
  return 0;
}
