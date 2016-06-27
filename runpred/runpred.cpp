/* Running prediction program */

#include "runperf.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>

//#include <limits.h>
//#include <string>
//#include <sys/stat.h>
//#include <stdio.h>
//#include <string.h>
//#include <dirent.h>

using namespace std;

void help();


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
      stringstream(timestr) >> runtime; //in minutes
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
  cout << "Pace =  " << run.get_pace() << " min/km" << endl;
  run.VO2max_calc();
  cout << "VO2max = " << run.get_VO2max() << endl;
  if (distance_new >= 0) {
    cout << "----Performance prediction----\n";
    run.predict(distance_new, weightchange);
    cout << weightchange << endl;
    cout << "Predicted time = " << run.get_predtime() << endl; 
    cout << "Predicted pace = " << run.get_predpace() << " min/km" << endl;
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
  cout << "-p     : Running distance for time prediction\n";
  cout << "-w     : Weight change in percentage\n";
}
