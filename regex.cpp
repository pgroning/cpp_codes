#include <iostream>
#include <fstream>
#include <regex>

using namespace std;


int main()
{

  string linestr;
  
  cout << "Reading some contents from file\n" << endl;
  ifstream infile;
  infile.open("testfile.txt");

  if (!infile.is_open()) {
    cout << "Error: File could not be opened" << endl;
    return 1;
  }

  //regex re ("(pi)(.*)");
  regex re ("pi");
  smatch m;
  
  while (!infile.eof()) {
    getline(infile,linestr);
    if (regex_search(linestr,m,re)) {
      cout << linestr << endl;
      cout << m.suffix().str() << endl;
    }
  }
  
  infile.close();

  return 0;
}
