#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#define PI 3.14159265358979
#define E 2.71828182845905

main()
{

  const double pi = PI;
  const double e = E;
  double value;
  string header,instr,delim;

  //-------------------------------
  cout << "Writing some contents to file..." << endl;  
  cout.precision(15);
  cout << pi << endl;
  cout << e << endl;
  ofstream outfile;
  outfile.open("testfile.txt");
  outfile.precision(15);
  outfile << "List of mathematical constants\n";
  outfile << "pi = " << pi << "\n";
  outfile << setprecision(6) << "e = " << e << "\n";
  outfile.close();
  //----------------------------------
  cout << "\n";
  cout << "Reading some contents from file" << endl;
  ifstream infile;
  infile.open("testfile.txt");
  if (infile.is_open()) {
    getline(infile,header); //Read header line
    
    while(infile >> instr >> delim >> value) {
      cout << instr << delim << value << endl;
    }

    infile.close();
  }
  return 0;
}
