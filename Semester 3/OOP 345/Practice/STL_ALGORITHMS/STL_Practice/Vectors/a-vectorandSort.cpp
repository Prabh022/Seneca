#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	std::vector<int> nums;
	int input;
	std::cout << "Enter 5 integers: ";
	for (int i = 0; i < 5;i++) {
		std::cin >> input;
		nums.push_back(input);
	}
	std::cout << "Five intergers are: ";
	for (int num : nums) {
		std::cout << num << " ";
	}

	std::sort(nums.begin(), nums.end());
	std::cout << "\nSorted Numbers are: ";
	for (int num : nums) {
		std::cout << num << " ";
	}


	return 0;
}