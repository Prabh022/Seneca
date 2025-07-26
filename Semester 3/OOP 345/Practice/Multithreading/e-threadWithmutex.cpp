#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m;  // shared lock for printing

void square(int n) {
    int result = n * n;

    lock_guard<mutex> guard(m);  // lock the mutex
    cout << "Square of " << n << " is: " << result << endl;
}

int main() {
    thread t1(square, 5);
    thread t2(square, 8);
    thread t3(square, 65);

    t1.join();
    t2.join();
    t3.join();

    cout << "The Program has ended successfully.\n";

    return 0;
}