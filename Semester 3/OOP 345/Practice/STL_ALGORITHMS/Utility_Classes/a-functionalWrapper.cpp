#include <iostream>
#include <vector>
#include<string>
#include <functional>  // for std::function

int main() {
    ;
    std::vector<std::string> inputs(3);
    std::vector<std::function<void()>> actions;

    // Step 1: Take 3 strings from the user
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter string " << (i + 1) << ": ";
        
        std::getline(std::cin, inputs[i]);
    }

    // Step 2: Create lambdas and store in vector
    for (const auto& str : inputs) {
        actions.push_back([str]() {
            std::cout << str << std::endl;
            });
    }

    // Step 3: Loop and execute each lambda
    std::cout << "\n--- Running Stored Lambdas ---\n";
    for (const auto& action : actions) {
        action();  // call the lambda
    }

    return 0;
}