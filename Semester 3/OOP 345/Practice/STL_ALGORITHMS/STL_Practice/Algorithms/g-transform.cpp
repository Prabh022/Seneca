#include <iostream>
#include <vector>
#include <algorithm> // for transform

int main() {
    std::vector<int> nums = { 10, 20, 30, 40, 50 };
    std::vector<int> doubled(nums.size()); // make space

    std::transform(nums.begin(), nums.end(), doubled.begin(), [](int x) {
        return x * 2;
        });

    std::cout << "Original: ";
    for (int x : nums) std::cout << x << " ";

    std::cout << "\nDoubled: ";
    for (int x : doubled) std::cout << x << " ";

    std::cout << std::endl;
    return 0;
}
