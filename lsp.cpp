// Convert a relative to absolute file name. Works on *nix systems

#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <stdio.h>

using namespace std;


bool fileExists(const string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}



int main(int argc, char* argv[])
{
  string inarg;
  
  //int n = sizeof(argv)/sizeof(*argv);
  if (argc > 2) { // Too many input argument are given
    cout << "Error: Too many input arguments\n";
    exit(0);
  }
  else if (argc == 2) {
    inarg = argv[1];
  }
  else {
    inarg = "";
  }

  if(!inarg.empty()) { // Check if file exists
    bool exist = fileExists(inarg);
    if (!exist) {
      string errmsg = "lsp: cannot access '"+inarg+"'";
      perror(errmsg.c_str());
      exit(EXIT_FAILURE);
    }
  }
  
  char buffer[PATH_MAX+1];
  char *result = realpath("./", buffer);
  if (result) {
    cout << buffer;
    cout << "/" << inarg << endl;
  }
  else {
    exit(EXIT_FAILURE);
  }

  return 0;
}
