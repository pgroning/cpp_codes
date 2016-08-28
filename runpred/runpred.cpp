/* Running prediction program */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>  // used for stringstream
#include <iomanip>  // used for setprecision
#include "runperf.h"

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
  cout << "Race time predictor.\n";
  cout << "Prediction of running performance for a given distance assuming constant VO2max.\n\n";
  cout << "Usage: runpred [Options]... [ARGS]...\n\n";
  cout << "Options:\n";
  cout << "-h     : Show this help message and exit\n";
  cout << "-t     : Running time\n";
  cout << "-d     : Running distance\n";
  cout << "-p     : Running distance for performance prediction\n";
  cout << "-w     : Body weight change in percentage (for performance prediction)\n\n";
  cout << "Examples:\n";
  cout << "Calculate the average pace and VO2max for a 5 km race with a duration of 21 minutes and 30 seconds.\n";
  cout << "$ runpred -d 5 -t 21:30\n\n";
  cout << "The same as above but also predict the duration of a 10 km race assuming constant VO2max.\n";
  cout << "$ runpred -d 5 -t 21:30 -p 10\n\n";
  cout << "The same as above but also account for a 2 percent body weight loss.\n";
  cout << "$ runpred -d 5 -t 21:30 -p 10 -w -0.02\n";
  cout << "\nWritten by P. Groningsson\n";
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
