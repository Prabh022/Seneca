#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Task {
    std::string name;
    int priority;

    Task(std::string n, int p) : name(n), priority(p) {}
};

// Custom comparator: lower priority number = higher importance
struct CompareTask {
    bool operator()(const Task& t1, const Task& t2) {
        return t1.priority > t2.priority; // min-heap by priority
    }
};

int main() {
    std::priority_queue<Task, std::vector<Task>, CompareTask> taskQueue;

    int count;
    std::cout << "How many tasks? ";
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        std::string name;
        int priority;
        std::cout << "Enter task name: ";
        std::cin >> name;
        std::cout << "Enter priority (lower = urgent): ";
        std::cin >> priority;

        taskQueue.emplace(name, priority);
    }

    std::cout << "\nTasks in order of urgency:\n";
    while (!taskQueue.empty()) {
        Task t = taskQueue.top();
        std::cout << "Task: " << t.name << ", Priority: " << t.priority << "\n";
        taskQueue.pop();
    }

    return 0;
}
