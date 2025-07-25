#include <iostream>
#include <vector>
#include <numeric> // for accumulate

int main() {
    std::vector<int> nums = { 10, 20, 30 };

    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}
