#include "processor.h"

#include "linux_parser.h"
#include "unistd.h"


// DOne: Return the aggregate CPU utilization
float Processor::Utilization() {
     
  float tot_cpu = LinuxParser::Jiffies();
  float act_cpu = LinuxParser::ActiveJiffies();
  
  float cpu_percent = (act_cpu - Processor::previous_act_cpu_) / (tot_cpu - Processor::prevous_tot_cpu_);
  return cpu_percent;
     }