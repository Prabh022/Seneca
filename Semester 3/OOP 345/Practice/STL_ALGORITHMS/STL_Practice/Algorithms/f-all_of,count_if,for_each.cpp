#include <iostream>
#include <vector>
#include <algorithm> // for all_of, count_if, for_each

int main() {
    std::vector<int> nums;
    int input;

    // Step 1: Take 6 inputs
    std::cout << "Enter 6 numbers: ";
    for (int i = 0; i < 6; ++i) {
        std::cin >> input;
        nums.push_back(input);
    }

    // Step 2: Print all values
    std::cout << "\nNumbers entered: ";
    for (int n : nums) {
        std::cout << n << " ";
    }

    // Step 3: Check if all are even
    bool allEven = std::all_of(nums.begin(), nums.end(), [](int x) {
        return x % 2 == 0;
        });

    std::cout << "\nAll numbers are even? " << (allEven ? "Yes" : "No");

    // Step 4: Count how many are > 50
    int countAbove50 = std::count_if(nums.begin(), nums.end(), [](int x) {
        return x > 50;
        });

    std::cout << "\nNumbers greater than 50: " << countAbove50;

    // Step 5: Print each number squared using for_each
    std::cout << "\nSquares of the numbers: ";
    std::for_each(nums.begin(), nums.end(), [](int x) {
        std::cout << x * x << " ";
        });

    std::cout << std::endl;
    return 0;
}