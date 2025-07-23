#include<iostream>
#include<vector>
#include<algorithm> // for std::count

int main() {
	std::vector<int> nums;
	int count, input, target;
	std::cout << "How many numbers would you like to continue with it: ";
	std::cin >> count;
	std::cout << "Enter " << count << " numbers: ";
	for (int i = 0;i < count; i++) {
		std::cin >> input;
		nums.push_back(input);
	}
	
	std::cout << count << " numbers are: ";
	for (int num : nums) {
		std::cout << num << " ";
	}
	std::cout << "\nEnter the target number: ";
	std::cin >> target;

	auto it = std::find(nums.begin(), nums.end(), target);
	
	if (it != nums.end()) {
		std::cout << "Found " << target << " at index: " << (it - nums.begin());
 	}
	else {
		std::cout << target << " not found!\n";
	}
	
	int frequency = std::count(nums.begin(), nums.end(), target);
	std::cout << "\nTarget " << target << " appears to be " << frequency << " times.\n";

	return 0;
}