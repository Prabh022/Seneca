#include <iostream>
#include <thread>
#include<mutex>

using namespace std;

int counter = 0; // Shared resource
mutex mtx;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        lock_guard<mutex> lock(mtx);  //this is much cleaner and professional as it do locking and unlocking
                                      //all together.
        ++counter; // Not safe in multithreaded context!
        
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);
    thread t3(increment);

    t1.join();
    t2.join();
    t3.join();

    cout << "Final Counter: " << counter << endl; // Expected: 300000

    return 0;
}
