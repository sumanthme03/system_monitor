#include "processor.h"
#include <vector>
#include "linux_parser.h"
#include "unistd.h"
using namespace std;

// DOne: Return the aggregate CPU utilization
float Processor::Utilization() 
{
return LinuxParser::ActiveJiffies() / (LinuxParser::ActiveJiffies() + LinuxParser::IdleJiffies());

  
}