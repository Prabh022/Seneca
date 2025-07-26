#include <iostream>
#include <exception>
#include <string>
using namespace std;

// Custom Exception Class
class NegativeRootException : public exception {
    string message;
public:
    NegativeRootException(const string& msg) : message(msg) {}

    // Override what() to return our message
    const char* what() const noexcept override {
        return message.c_str();
    }
};

double safeSqrt(double x) {
    if (x < 0) {
        throw NegativeRootException("Custom Error: Cannot get a root of Negative number.");
    }
    return sqrt(x);
}

int main() {
    double x;
    cout << "Enter a numbers: ";
    cin >> x;

    try {
        double result = safeSqrt(x);
        cout << "Result = " << result << endl;
    }
    catch (const NegativeRootException& e) {
        cout << "Caught custom exception: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Caught standard exception: " << e.what() << endl;
    }

    return 0;
}
