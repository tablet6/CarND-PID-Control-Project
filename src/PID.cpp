#include "PID.h"

#include <iostream>
#include <math.h>

/*
* TODO: Complete the PID class.
*/

#define ITERATIONS 100

PID::PID() {
  p_error = 0.07;
  i_error = 0.0;
  d_error = 0.0;
  
  Kp = 0.2;
  Ki = 0.004;
  Kd = 3.0;
  
  counter = 0;
  throttle = 0.0;
  first = true;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  i_error = i_error + cte;
  d_error = cte - p_error;
  p_error = cte;
//  std::cout<<"cte: "<<cte<<"\n";
}

double PID::TotalError() {
  
  return (-Kp * p_error - Ki * i_error - Kd * d_error);
}

void PID::UpdateThrottle(double value) {
  
  
  // Init counter when first time we reduce the throttle
  if (value == 0.1)
  {
    counter = 1;
  }
  
  //Increment counter
  if (counter!=0 )
  {
    counter++;
  }
  
  //Keep throttle constant for 100 iterations once it was reduced.
  //A very crude logic, since I didn't figured out how to pass init value to Lambda func
  if (counter < ITERATIONS && counter !=0)
  {
    throttle = 0.1;
  }
  else
  {
    counter = 0;
    throttle = value;
  }
  
//  std::cout<<"counter: "<<counter<<" throttle: "<<throttle<<"\n";
}

//A very crude logic, since I didn't figured out how to pass init value to Lambda func
void PID::setFirst(bool value) {
  first = false;
}
