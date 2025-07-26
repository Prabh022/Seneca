#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    while (true) {
        double num1, num2;
        char op;

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> op;

        try {
            double result;
            switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0)
                    throw runtime_error("Cannot divide by zero.");
                result = num1 / num2;
                break;
            default:
                throw invalid_argument("Invalid operator.");
            }
            cout << "Result: " << result << endl;
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << "\nTry another calculation? (y/n): ";
        char again;
        cin >> again;
        if (again != 'y' && again != 'Y') break;
    }

    cout << "Goodbye!\n";
    return 0;
}