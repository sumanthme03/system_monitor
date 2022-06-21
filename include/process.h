#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include "linux_parser.h"
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
 
  Process(int pid) : pid_(pid){}
  int Pid();                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

  //completed: Declare any necessary private members
 private:
  
 int pid_;
 float cpuutil_ ;
 float CpuUtilization_;
  float preIdle_ = 0;
  float preTotal_ = 0;
  float preNonIdle_ = 0;
  float preIOWait_ = 0;
  float preUser_ = 0;
  float preNice_ = 0;
  float preSystem_ = 0;
  float preIRQ_ = 0;
  float preSoftIRQ_ = 0;
  float preSteal_ = 0;
};

#endif