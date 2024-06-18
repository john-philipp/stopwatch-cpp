#include <chrono>
#include <iostream>
#include <functional>
#include <sstream>

using LogFunctionType = std::function<void(const std::string& msg)>;
using ClockType = std::chrono::high_resolution_clock;
using TimePointType = std::chrono::time_point<ClockType>;
using TimeMs = std::chrono::milliseconds;
class Stopwatch
{
    class TimeTaken {
        public:
            double total;
            double diff;
            TimeTaken(double total, double diff) {
                this->total = total;
                this->diff = diff;
            }
    };

private:
    TimePointType timeStart;
    TimePointType timeLap;
    LogFunctionType logFunction;

    void handleLogging(const char* msg) {
        if (logFunction == nullptr) {
            std::cout << msg << std::endl;
        } else {
            logFunction(msg);
        }
    }

    double durationToSeconds(TimeMs duration) {
        return duration.count() / 1000.0;
    }

    double getTimeDiffFrom(TimePointType t0, TimePointType t1) {
        return durationToSeconds(std::chrono::duration_cast<TimeMs>(t1 - t0));
    }

public:
    Stopwatch() {
        reset();
    }

    Stopwatch(LogFunctionType logFunction) : timeStart(ClockType::now()) {
        setLogFunction(logFunction);
        timeLap = timeStart;
    }

    void setLogFunction(LogFunctionType logFunction) {
        this->logFunction = logFunction;
    }

    void reset() {
        timeStart = ClockType::now();
        timeLap = timeStart;
    }

    TimeTaken elapsedLap(const std::string& desc) {
        auto timeNow = ClockType::now();
        auto timeDiff = getTimeDiffFrom(timeLap, timeNow);
        auto timeTotal = getTimeDiffFrom(timeStart, timeNow);
        char msgBuffer[100];
        sprintf(
            msgBuffer, 
            "t_total=%6.3fs t_diff=%6.3fs desc=%s", 
            timeTotal, timeDiff, desc.c_str());
        handleLogging(msgBuffer);
        timeLap = timeNow;
        return TimeTaken(timeTotal, timeDiff);
    }
};
