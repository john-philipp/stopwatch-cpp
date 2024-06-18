#include <chrono>
#include <iostream>

using LogFunctionType = std::function<void(const std::string& msg)>;
using ClockType = std::chrono::high_resolution_clock;
using TimePointType = std::chrono::time_point<ClockType>;
using TimeMs = std::chrono::milliseconds;
class Stopwatch
{
private:
    TimePointType timeStart;
    TimePointType timeLap;
    LogFunctionType logFunction;

    void handleLogging(const std::stringstream msgStream) {
        auto msgStr = msgStream.str();
        if (logFunction == nullptr) {
            std::cout << msgStr << std::endl;
        } else {
            logFunction(msgStr);
        }
    }

    double durationToSeconds(TimeMs duration) {
        return duration.count() / 1000.0;
    }

    double getTimeDiffFrom(TimePointType t0, TimePointType t1) {
        return durationToSeconds(std::chrono::duration_cast<TimeMs>(t1 - t0));
    }

public:
    Stopwatch() : timeStart(ClockType::now()) {
        timeLap = timeStart;
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
    }

    double elapsedTotal(const std::string& desc) {
        auto timeNow = ClockType::now();
        auto timeTaken = getTimeDiffFrom(timeStart, timeNow);
        handleLogging(std::stringstream() << "Time taken: t_total=" << timeTaken << "s \tdesc=" << desc);
        return timeTaken;
    }

    double elapsedLap(const std::string& desc) {
        auto timeNow = ClockType::now();
        auto timeTaken = getTimeDiffFrom(timeLap, timeNow);
        handleLogging(std::stringstream() << "Time taken: t_diff=" << timeTaken << "s \tdesc=" << desc);
        timeLap = timeNow;
        return timeTaken;
    }
};
