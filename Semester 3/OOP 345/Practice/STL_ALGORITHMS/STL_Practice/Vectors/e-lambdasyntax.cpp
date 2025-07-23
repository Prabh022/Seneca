#include<iostream>
#include<vector>
#include<algorithm> // for std::count

int main() {
	std::vector<int> nums;
	int count, input;
	std::cout << "How many numbers would you like to continue with it: ";
	std::cin >> count;
	std::cout << "Enter " << count << " numbers: ";
	for (int i = 0;i < count; i++) {
		std::cin >> input;
		nums.push_back(input);
	}
	
	std::sort(nums.begin(), nums.end(), [](int a, int b) {
		return a > b;
		});

	for (int x : nums) {
		std::cout << x << " ";
	}


	return 0;
}