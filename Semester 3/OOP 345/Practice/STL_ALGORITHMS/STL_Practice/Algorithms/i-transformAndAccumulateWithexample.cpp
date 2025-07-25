#include <iostream>
#include <vector>
#include <algorithm>   // for std::transform
#include <numeric>     // for std::accumulate

int main() {
    std::vector<int> nums;
    int input;

    // 🔹 Take 6 user inputs
    std::cout << "Enter 6 numbers: ";
    for (int i = 0; i < 6; ++i) {
        std::cin >> input;
        nums.push_back(input);
    }

    // 🔹 Create a new vector of doubled values
    std::vector<int> doubled;
    std::transform(nums.begin(), nums.end(), std::back_inserter(doubled), [](int x) {
        return x * 2;
        });

    // 🔹 Calculate total of original and doubled numbers
    int originalSum = std::accumulate(nums.begin(), nums.end(), 0);
    int doubledSum = std::accumulate(doubled.begin(), doubled.end(), 0);

    // 🔹 Print both vectors
    std::cout << "\nOriginal numbers: ";
    for (int x : nums) std::cout << x << " ";

    std::cout << "\nDoubled numbers: ";
    for (int x : doubled) std::cout << x << " ";

    // 🔹 Print both sums
    std::cout << "\nSum of original numbers: " << originalSum;
    std::cout << "\nSum of doubled numbers: " << doubledSum << std::endl;

    return 0;
}