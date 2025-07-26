#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
mutex mtx; // Mutex for protecting shared counter

void increment() {
    for (int i = 0; i < 100000; ++i) {
        mtx.lock();         // Lock before accessing shared data
        ++counter;          //without mutex this can be really unsafe
        mtx.unlock();       // Unlock after done
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);
    thread t3(increment);

    t1.join();
    t2.join();
    t3.join();

    cout << "Final Counter: " << counter << endl;

    return 0;
}
