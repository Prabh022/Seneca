#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <future>
#include <mutex>
#include <condition_variable>

using namespace std;

// ThreadPool class to manage multiple worker threads
class ThreadPool {
public:
    // Constructor - initializes and starts worker threads
    ThreadPool(size_t threadCount);

    // Submit a task to the thread pool and get a future result
    template<class F, class... Args>
    auto submit(F&& f, Args&&... args)
        -> future<invoke_result_t<F, Args...>>;

    // Destructor - cleans up and stops threads
    ~ThreadPool();

private:
    // Worker threads
    vector<thread> workers;

    // Task queue - stores functions to be executed
    queue<function<void()>> tasks;

    // Synchronization tools
    mutex queueMutex;                 // Protects task queue
    condition_variable condition;     // Notifies threads of new work
    bool stop = false;                // Flag to stop the pool
};

// Constructor - Start the given number of worker threads
ThreadPool::ThreadPool(size_t threadCount) {
    for (size_t i = 0; i < threadCount; ++i) {
        workers.emplace_back([this] {
            // Each thread runs this loop
            while (true) {
                function<void()> task;

                // Scope for locking
                {
                    unique_lock<mutex> lock(queueMutex);

                    // Wait until there's a task or the pool is stopping
                    condition.wait(lock, [this] {
                        return stop || !tasks.empty();
                        });

                    // If we're stopping and no tasks left, exit the thread
                    if (stop && tasks.empty())
                        return;

                    // Get next task from queue
                    task = move(tasks.front());
                    tasks.pop();
                }

                // Run the task
                task();
            }
            });
    }
}

// Submit a task to the thread pool
template<class F, class... Args>
auto ThreadPool::submit(F&& f, Args&&... args)
-> future<invoke_result_t<F, Args...>>
{
    using return_type = invoke_result_t<F, Args...>;

    // Wrap the function and arguments into a packaged task
    auto task = make_shared<packaged_task<return_type()>>(
        bind(forward<F>(f), forward<Args>(args)...)
    );

    // Get the future to retrieve result later
    future<return_type> result = task->get_future();

    {
        // Lock the queue to prevent race condition
        unique_lock<mutex> lock(queueMutex);

        // Prevent submitting if the pool is stopped
        if (stop)
            throw runtime_error("Cannot submit to stopped ThreadPool");

        // Add the task as a void function to the queue
        tasks.emplace([task]() { (*task)(); });
    }

    // Notify one waiting thread
    condition.notify_one();

    return result;
}

// Destructor - join all threads and stop everything
ThreadPool::~ThreadPool() {
    {
        unique_lock<mutex> lock(queueMutex);
        stop = true; // Tell threads to stop
    }

    // Wake up all threads so they can exit
    condition.notify_all();

    // Join all threads to wait for their completion
    for (thread& worker : workers)
        worker.join();
}

// Example function to run in the thread pool
int add(int a, int b) {
    this_thread::sleep_for(chrono::seconds(1)); // simulate delay
    return a + b;
}

// Main function to test the ThreadPool
int main() {
    // Create a thread pool with 3 worker threads
    ThreadPool pool(3);

    // Submit tasks and get futures
    auto future1 = pool.submit(add, 5, 10);
    auto future2 = pool.submit(add, 20, 30);
    auto future3 = pool.submit([] { cout << "Hello from thread!\n"; return 0; });

    // Wait for results
    cout << "Result 1: " << future1.get() << endl;
    cout << "Result 2: " << future2.get() << endl;
    future3.get(); // No result printed since it's void

    cout << "All tasks completed." << endl;

    return 0;
}
