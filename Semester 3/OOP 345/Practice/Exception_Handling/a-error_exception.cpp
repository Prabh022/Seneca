#include <iostream>
using namespace std;

int divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero!");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    cout << "Program continues..." << endl;
    return 0;
}
