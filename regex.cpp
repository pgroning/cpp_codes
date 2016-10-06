//Compile: $ g++ -std=c++11 regex.cpp -o regex

#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;


int main()
{

  string linestr;
  
  cout << "Reading file...\n" << endl;
  ifstream infile;
  infile.open("testfile.txt");

  if (!infile.is_open()) {
    cout << "Error: File could not be opened" << endl;
    return 1;
  }
  
  regex re ("(pi =)(.*)");
  //regex re ("(pi)([^ ]*)");
  //regex re ("\\b(sub)([^ ]*)");
  //regex re ("pi");
  smatch m;
  
  while (!infile.eof()) {
    getline(infile,linestr);
    //cout << linestr << endl;
    //if (regex_search(linestr,m,re)) {
    if(regex_match(linestr,m,re)) {
      cout << linestr << endl;
      cout << m.size() << endl;
    }
  }
  
  infile.close();

  return 0;
}
