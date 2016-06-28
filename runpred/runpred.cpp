/* Running prediction program */

#include "runperf.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>  // used for stringstream
#include <iomanip>  // used for setprecision

//#include <limits.h>
//#include <sys/stat.h>
//#include <stdio.h>
//#include <dirent.h>

using namespace std;

void help();

float str2time(string);

int main(int argc, char* argv[])
{
  
  string timestr;
  float runtime;
  string diststr;
  float distance;
  float distance_new = -1.0;
  float weightchange = 0.0;
  
  if (argc == 1) { // no argument is given. call help function
    help();
    exit(0);
  }

  /* Get input parameters */
  for (int i = 1; i < argc; i++) {
    if (!strcmp(argv[i],"-h")) {
      help();
      exit(0);
    } else if (!strcmp(argv[i],"-t")) {
      timestr = argv[i+1];
      runtime = str2time(timestr);
    } else if (!strcmp(argv[i],"-d")) {
      diststr = argv[i+1];
      stringstream(diststr) >> distance; //in km
    } else if (!strcmp(argv[i],"-p")) {
      diststr = argv[i+1];
      stringstream(diststr) >> distance_new; //in km
    } else if (!strcmp(argv[i],"-w")) {
      diststr = argv[i+1];
      stringstream(diststr) >> weightchange; //in percent
    } 
  }

  runperf run(runtime, distance);
  run.pace_calc();
  cout << "Pace =  " << run.get_pace() << " [m:ss]/km" << endl;
  run.VO2max_calc();
  cout << "VO2max = " << setprecision(4) << run.get_VO2max() << endl;
  if (distance_new >= 0) {
    cout << "----Performance prediction----\n";
    run.predict(distance_new, weightchange);
    cout << "Predicted time = " << run.get_predtime() << " [h:mm:ss]\n"; 
    cout << "Predicted pace = " << run.get_predpace() << " [m:ss]/km\n";
  }
  
}

void help()
{
  cout << "Prediction of running performance by calculating VO2max.\n\n";
  cout << "Usage: runpred [Options]... [ARGS]...\n\n";
  cout << "Options:\n";
  cout << "-h     : Show this help message and exit\n";
  cout << "-t     : Running time\n";
  cout << "-d     : Running distance\n";
  cout << "-p     : Running distance for performance prediction\n";
  cout << "-w     : Body weight change in percentage (for performance prediction)\n";
}

float str2time(string str)
{
  float hour, min, sec;

  hour = 0;
  size_t p = str.find(":");
  stringstream(str.substr(0,p)) >> min;
  stringstream(str.substr(++p)) >> sec;
  
  str = str.substr(p);
  p = str.find(":");
  if (p!=string::npos) { // match was found
    hour = min;
    min = sec;
    stringstream(str.substr(++p)) >> sec;
  }
  float runtime = hour*60 + min + sec/60; // minutes

  return runtime;
}
