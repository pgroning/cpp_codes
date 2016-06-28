#ifndef RUNPERF_H
#define RUNPERF_H
#include <string>

class runperf
{
 public:
  runperf();
  runperf(float t, float d);
  void pace_calc(float runtime, float distance);
  void pace_calc();
  std::string get_pace();
  void VO2max_calc();
  void VO2max_calc(float, float);
  float get_VO2max();
  void predict(float, float);
  std::string get_predtime();
  std::string get_predpace();
 private:
  float runtime;
  float distance;
  float distance_new;
  float pace;
  float VO2max;
  float predtime;
  float weightchange;
};

#endif // RUNPERF_H
