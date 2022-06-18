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
  float actj = (float)LinuxParser::ActiveJiffies(pid_);
  float luptime = (float)(LinuxParser::UpTime())*sysconf(_SC_CLK_TCK);
  return (actj / (luptime - LinuxParser::UpTime(pid_)*sysconf(_SC_CLK_TCK))) ; 
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
return LinuxParser::UpTime(pid_); 
}

// Completed: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const 
{ 
	return this->cpuutil_ < a.cpuutil_;
}
