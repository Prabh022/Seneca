#include<iostream>
#include<deque>

int main() {

	std::deque<int> nums = { 10, 20, 30 };
	nums.push_front(5);
	nums.push_back(40);
	std::cout << "Numbers stored are: ";
	for (int num : nums) {
		std::cout << num << " ";
	}
	std::cout << "\nElement at index 2: " << nums[2];
	auto it = std::find(nums.begin(), nums.end(), 40);
	if (it != nums.end()) {
		nums.erase(it);
		std::cout << "\n40  was removed.";
	}
	else {
		std::cout << " 40 was not found in the list";
	}
	std::cout << "Numbers stored after Removal: ";
	for (int num : nums) {
		std::cout << num << " ";
	}

	return 0;
}
