// Convert a relative to absolute file name. Works on *nix systems

#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

using namespace std;


bool fileExists(const string& filename) // Checks for file existence
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}


string abs_path(const string& inarg)
{
  char buffer[PATH_MAX+1];
  char *result = realpath("./", buffer);
  if (!result) {
    exit(EXIT_FAILURE);
  }
  string filesep = "/";
  string absfile = buffer + filesep + inarg;
  return absfile;
}


void listdir() // List all files in directory
{
  DIR *dir; 
  struct dirent *ent;

  string abspath;
  
  if ((dir = opendir ("./")) != NULL) {
    /* print all the files and directories within directory */
    while ((ent = readdir (dir)) != NULL) {
      abspath = abs_path(ent->d_name);
      cout << abspath << endl;
    }
    closedir (dir);
  } else {
    /* could not open directory */
    perror ("");
    exit(EXIT_FAILURE);    
  }
  
}


void help() // Print help text
{
  cout << "Usage: lsp [FILE1] [FILE2]...\n";
  cout << "List FILEs with absolute paths.\n\n";
  cout << "Options:\n";
  cout << " -h   : show this help message and exit\n";
}

int main(int argc, char* argv[])
{
  string inarg;

  if (argc < 2) { // No input argument is given
    listdir();
    exit(0);
  }

  if (!strcmp(argv[1],"-h")) { // call help function
    help();
    exit(0);
  }

  for (int i = 1; i < argc; i++) {
    
    inarg = argv[i];
    
    if(!inarg.empty()) { // Check if file exists
      bool exist = fileExists(inarg);
      if (!exist) {
        string errmsg = "lsp: cannot access '"+inarg+"'";
        perror(errmsg.c_str());
        exit(EXIT_FAILURE);
      }
    }
    
    // Print absolute path
    string abspath = abs_path(inarg);
    cout << abspath << endl;

  }

  return 0;
}
