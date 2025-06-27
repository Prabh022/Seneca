#ifndef TIMEDTASK_H
#define TIMEDTASK_H

#include "Task.h"
#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>
namespace seneca {
// Class to record and report execution times of tasks
class TimedTask {
    static const int MAX_TASKS = 10;  // max number of tasks
    Task tasks[MAX_TASKS];           // static array of task records
    int taskCount{ 0 };              // how many tasks recorded

    std::chrono::steady_clock::time_point startTime; // timer start
    std::chrono::steady_clock::time_point endTime;   // timer end

public:
    TimedTask() = default;

    void startClock() {
        startTime = std::chrono::steady_clock::now();
    }

    void stopClock() {
        endTime = std::chrono::steady_clock::now();
    }

    void addTask(const char* name) {
        if (taskCount < MAX_TASKS) {
            tasks[taskCount].taskName = name;
            tasks[taskCount].timeUnit = "nanoseconds";
            tasks[taskCount].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
            ++taskCount;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const TimedTask& tt) {
        os << "Execution Times:\n";
        os << "--------------------------\n";
        for (int i = 0; i < tt.taskCount; ++i) {
            os << std::setw(21) << std::left << tt.tasks[i].taskName
                << std::setw(13) << std::right << tt.tasks[i].duration.count()
                << " " << tt.tasks[i].timeUnit << "\n";
        }
        os << "--------------------------\n";
        return os;
    }
};
}
#endif


