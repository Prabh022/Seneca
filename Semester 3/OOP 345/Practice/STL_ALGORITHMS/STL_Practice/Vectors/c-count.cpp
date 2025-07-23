#include<iostream>
#include<vector>
#include<algorithm> // for std::count

int main() {
	std::vector<int> nums = { 10, 30, 20, 14, 23, 45, 20,};
	int target = 20;
	
	int frequency = std::count(nums.begin(), nums.end(), target);
	std::cout << "Target " << target << " appears to be " << frequency << " times.\n";
	
	return 0;
}