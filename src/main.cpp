#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <ctime>

#include "stopwatch.cpp"

int main() {
    std::cout << "Starting ..." << std::endl;

    // Uniform random number generation b/n 50 and 100.
    std::random_device randomDevice;
    std::mt19937 randomNumberGenerator(randomDevice());
    std::uniform_int_distribution<> uniformIntDistribution(50, 100);

    // Loop over sleep and logging times.
    Stopwatch sw = Stopwatch();
    for (int i = 0; i < 10; i++) {
        sw.elapsedLap("This is a test.");
        int randomSleepInt = uniformIntDistribution(randomNumberGenerator);
        std::this_thread::sleep_for(std::chrono::milliseconds(randomSleepInt));
    }
}