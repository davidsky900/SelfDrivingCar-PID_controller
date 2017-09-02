#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    // Initialize PID gains and errors
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    d_error = 0;
    p_error = 0;
    i_error = 0;
}

void PID::UpdateError(double cte) {
    // Update errors within PID controller
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
}

