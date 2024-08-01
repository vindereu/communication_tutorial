#ifndef __PID_H__
#define __PID_H__
#include <array>
#include <limits>

using std::array;
using std::numeric_limits;

template<size_t AMOUNT>
class PID
{
public:
    PID()
    : Kp{0}, Ki{0}, Kd{0},
      target{0},
      lowerIntegral{-numeric_limits<double>::max()},
      upperIntegral{numeric_limits<double>::max()},
      init{true},
      lastTime{numeric_limits<double>::quiet_NaN()},
      lastError{0},
      errorSum{0}
    {
    }
    
    PID(array<double, AMOUNT> Kp, array<double, AMOUNT> Ki, array<double, AMOUNT> Kd)
        : Kp{Kp}, Ki{Ki}, Kd{Kd},
      target{0},
      lowerIntegral{-numeric_limits<double>::max()},
      upperIntegral{numeric_limits<double>::max()},
      init{true},
      lastTime{numeric_limits<double>::quiet_NaN()},
      lastError{0},
      errorSum{0}
    {
    }
    
    void reset()
    {
        init = true;
        lastTime = std::numeric_limits<double>::quiet_NaN();
        for (size_t i=0; i<AMOUNT; i++) {
            errorSum[i] = 0;
            lastError[i] = 0;
        }
    }

    array<double, AMOUNT> update(array<double, AMOUNT> data, double userTime)
    {
        array<double, AMOUNT> output, error, P_out, I_out, D_out;

        // Error & Kp output
        for (size_t i=0; i<AMOUNT; i++) {
            error[i] = target[i] - data[i];
            P_out[i] = Kp[i] * error[i];
        }

        if (init) {
            lastError = error;
            lastTime = userTime;
            init = false;
            return P_out;
        }

        double dt = get_dt(userTime);

        for (size_t i=0; i<AMOUNT; i++) {
            // Ki output
            errorSum[i] += error[i] * dt;
            I_out[i] = Ki[i] * errorSum[i];
            I_out[i] = std::max(I_out[i], lowerIntegral);
            I_out[i] = std::min(I_out[i], upperIntegral);

            // Kd output
            double dError = (error[i] - lastError[i]) / dt;
            D_out[i] = Kd[i] * dError;

            // Output
            output[i] = P_out[i] + I_out[i] + D_out[i];
        }
        lastError = error;

        return output;
    }

public:
    array<double, AMOUNT> Kp, Ki, Kd;
    array<double, AMOUNT> target;
    double lowerIntegral, upperIntegral;

private:
    bool init;
    double lastTime;
    array<double, AMOUNT> lastError;
    array<double, AMOUNT> errorSum;
  
private:
    double get_dt(double currentTime)
    {
        double dt = currentTime - lastTime;
        lastTime = currentTime;
        if (dt <= 0.0)
            return 1E-10;

        return dt;
    }
};

#endif /* __PID_H__ */