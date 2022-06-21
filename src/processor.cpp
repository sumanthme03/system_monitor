#include "processor.h"
#include <vector>
#include "linux_parser.h"
#include "unistd.h"
using namespace std;

// DOne: Return the aggregate CPU utilization
float Processor::Utilization() 
{
  vector<string> util = LinuxParser::CpuUtilization();
  float tot = 0;
  float act = std::stof(util[0]) + std::stof(util[1]) + std::stof(util[2]);
  for (auto i : util) tot = tot + std::stof(i);

  return (act / tot);
  
} 
