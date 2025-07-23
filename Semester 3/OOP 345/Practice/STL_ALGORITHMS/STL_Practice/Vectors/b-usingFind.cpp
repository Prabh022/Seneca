#include<iostream>
#include<vector>
#include<algorithm> // for std::find

int main() {
	std::vector<int> nums = { 10, 30, 14, 23, 45 };
	int target = 30;
	
	auto it= std::find(nums.begin(), nums.end(), target);
	
	if (it != nums.end()) {
		std::cout << "Found " << target << " at index: " << (it - nums.begin()) << "\n";
	}
	else {
		std::cout << target << " not found!\n";
	}
	return 0;
}