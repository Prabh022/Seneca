#include <iostream>
#include <future>
#include <thread>

using namespace std;

int multiply(int n, int o) {
    return n * o;
}

int main() {
    // First packaged_task for main thread
    packaged_task<int(int, int)> task1(multiply);
    future<int> result1 = task1.get_future();
    task1(6, 7); // executed directly in main

    // Second packaged_task for thread
    packaged_task<int(int, int)> task2(multiply);
    future<int> result2 = task2.get_future();
    thread t(move(task2), 10, 20); // executed in separate thread

    t.join();

    cout << "Result from main: " << result1.get() << endl;
    cout << "Result from thread: " << result2.get() << endl;

    return 0;
}