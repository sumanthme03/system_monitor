#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // Done : Declare any necessary private members
 private:
 float previous_act_cpu_{0};
 float prevous_tot_cpu_{0};
};

#endif