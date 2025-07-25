#include<iostream>
#include<queue>

int main() {

	std::deque<int> nums = { 10, 20, 30 };
	nums.push_front(5);
	nums.push_back(40);
	std::cout << "Numbers stored are: ";
	for (int num : nums) {
		std::cout << num << " ";
	}
	std::cout << "\nElement at index 2: " << nums[2];


	return 0;
}