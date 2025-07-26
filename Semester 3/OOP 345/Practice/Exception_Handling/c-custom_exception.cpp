#include <iostream>
#include <exception>
#include <string>
using namespace std;

// Custom Exception Class
class DivideByZeroException : public exception {
    string message;
public:
    DivideByZeroException(const string& msg) : message(msg) {}

    // Override what() to return our message
    const char* what() const noexcept override {
        return message.c_str();
    }
};

double divide(double a, double b) {
    if (b == 0) {
        throw DivideByZeroException("Custom Error: Cannot divide by zero.");
    }
    return a / b;
}

int main() {
    double x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    try {
        double result = divide(x, y);
        cout << "Result = " << result << endl;
    }
    catch (const DivideByZeroException& e) {
        cout << "Caught custom exception: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Caught standard exception: " << e.what() << endl;
    }

    return 0;
}
