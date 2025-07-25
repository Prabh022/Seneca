#include <iostream>
#include <vector>
#include <functional>  // for std::reference_wrapper

int main() {
    // Step 1: Declare 3 integers
    int a, b, c;

    // Step 2: Take input from the user
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;
    std::cout << "Enter third number: ";
    std::cin >> c;

    // Step 3: Store references in vector
    std::vector<std::reference_wrapper<int>> refs;
    refs.push_back(a);
    refs.push_back(b);
    refs.push_back(c);

    // Step 4: Add 100 to each value via the vector
    for (int& ref : refs) {
        ref += 100;
    }

    // Step 5: Print modified original variables
    std::cout << "\nModified values:\n";
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    return 0;
}