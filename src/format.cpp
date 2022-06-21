#include <string>

#include "format.h"
#include <iomanip>

using std::string;

//using std::setfill;
//using std::setw;
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
long hr, min, sec;
  hr = seconds / 3600;
  min = (seconds - 3600 * hr) / 60;
  sec = (seconds - 3600 * hr) % 60;
  std::ostringstream stream;
  stream << std::setw(2) << std::setfill('0') << hr << ":" << std::setw(2)<< std::setfill('0') << min << ":" << std::setw(2) << std::setfill('0') <<sec;
  return stream.str();
}
