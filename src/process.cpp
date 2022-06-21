#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { 
return pid_; 
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() 
{ 
/*solution from https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux/23376195#23376195*/
// calc preious values of cpu jiffies
  preIdle_ = preIdle_ + preIOWait_;
  preNonIdle_ = preUser_ + preNice_ + preSystem_ + preIRQ_ + preSoftIRQ_ +  preSteal_;
  preTotal_ = preIdle_ + preNonIdle_;

  // get the current values of cpu jiffies
  vector<string> jiffs = LinuxParser::CpuUtilization();
  float idle =       stof(jiffs[LinuxParser::kIdle_]) + stof(jiffs[LinuxParser::kIOwait_]);
  float nonidle =
      stof(jiffs[LinuxParser::kUser_]) + stof(jiffs[LinuxParser::kNice_]) +
      stof(jiffs[LinuxParser::kSystem_]) + stof(jiffs[LinuxParser::kIRQ_]) +
      stof(jiffs[LinuxParser::kSoftIRQ_]) + stof(jiffs[LinuxParser::kSteal_]);
  float total = idle + nonidle;

  // calc delta of current and preious values
  float totalDelta = total - preTotal_;
  float idleDelta = idle - preIdle_;

  // set CpuUtilization_ as percentage
  CpuUtilization_ = (totalDelta - idleDelta) / totalDelta;

  // update preious values with new current values and return CpuUtilization_
  preIOWait_ = stof(jiffs[LinuxParser::kIOwait_]);
  preUser_ = stof(jiffs[LinuxParser::kUser_]);
  preNice_ = stof(jiffs[LinuxParser::kNice_]);
  preSystem_ = stof(jiffs[LinuxParser::kSystem_]);
  preIRQ_ = stof(jiffs[LinuxParser::kIRQ_]);
  preSoftIRQ_ = stof(jiffs[LinuxParser::kSoftIRQ_]);
  preSteal_ = stof(jiffs[LinuxParser::kSteal_]);
  return CpuUtilization_;

}

// Completed: Return the command that generated this process
string Process::Command() 
{ 
return LinuxParser::Command(pid_); 
}

// Completed: Return this process's memory utilization
string Process::Ram() 
{ 
return LinuxParser::Ram(pid_); 
}

// Completed: Return the user (name) that generated this process
string Process::User() 
{
 return LinuxParser::User(pid_); 
}

// Completed: Return the age of this process (in seconds)
long int Process::UpTime() 
{ 
return LinuxParser::UpTime() - LinuxParser::UpTime(pid_);
}

// Completed: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const 
{ 
	return this->cpuutil_ < a.cpuutil_;
  //return (  a.cpuUtilization_<cpuUtilization_);
}
