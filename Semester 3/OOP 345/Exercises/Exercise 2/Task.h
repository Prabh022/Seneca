#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono>
namespace seneca {
    // A single timed task record
    struct Task {
        std::string taskName{};  // Name of the task
        std::string timeUnit{};  // Time unit, e.g., "nanoseconds"
        std::chrono::steady_clock::duration duration{};  // Measured time duration
    };
}
#endif

