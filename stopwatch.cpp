#include <chrono>
#include <iostream>

class Stopwatch
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> lap_time;

public:
    Stopwatch() : start_time(std::chrono::high_resolution_clock::now()) {
        lap_time = start_time;
    }

    void reset() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    double s_elapsed_total() {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        return duration.count() / 1000.0;
    }

    double s_elapsed_lap(std::string name) {
        auto last_lap = lap_time;
        auto curr_lap = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(curr_lap - last_lap);
        auto dt = duration.count() / 1000.0;

        lap_time = curr_lap;
        std::cout << "Time taken: " << dt << "s \tname=" << name << std::endl;
        return dt;
    }
};
