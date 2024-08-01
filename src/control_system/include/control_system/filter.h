#ifndef __FILTER_H__
#define __FILTER_H__
#include <array>
#include <limits>
#include <cassert>

using std::array;
using std::numeric_limits;

template<size_t AMOUNT>
class RC_LowPass
{
public:
    array<double, AMOUNT> tau;

public:
    RC_LowPass() = delete;

    RC_LowPass(array<double, AMOUNT> tau, array<double, AMOUNT> initialValue)
        : tau{tau},
          init{true},
          lastTime{numeric_limits<double>::quiet_NaN()},
          vCapacitor{initialValue}
    {
    }

    array<double, AMOUNT> update(array<double, AMOUNT> data, double userTime)
    {
        for (size_t i=0; i<AMOUNT; i++)
            assert(tau[i] > 0.0);

        if (init) {
            init = false;
            lastTime = userTime;
            return vCapacitor;
        }

        double dt = get_dt(userTime);
        for (size_t i=0; i<AMOUNT; i++)
            vCapacitor[i] += (data[i]-vCapacitor[i]) * dt / tau[i];

        return vCapacitor;
    }

    void reset(array<double, AMOUNT> initialValue={0})
    {
        init = true;
        lastTime = numeric_limits<double>::quiet_NaN();
        vCapacitor = initialValue;
    }

private:
    bool init;
    double lastTime;
    array<double, AMOUNT> vCapacitor;

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


#endif /* __FILTER_H__ */