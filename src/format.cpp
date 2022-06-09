#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
// Done:Sdadam: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) 
{ 
  int min = seconds/60;
  int hr = min/60;
  string tm_out = std::to_string(int(hr))+ ":" + std::to_string(int(min)) + ":" + std::to_string(int(seconds%60));
  return tm_out; 
}
