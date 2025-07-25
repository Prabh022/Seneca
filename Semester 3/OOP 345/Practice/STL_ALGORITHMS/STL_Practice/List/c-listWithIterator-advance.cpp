#include<iostream>
#include<list>

int main() {
	std::list<int> nums = { 100,200,300,400 };
	std::cout << "Numbers of the list are: ";
	for (int num : nums) {
		std::cout << num << " ";
	}
	auto it = nums.begin();
	std::advance(it, 2);
	nums.insert(it,250);
	std::cout << "\nNumbers of the list are: ";
	for (int num : nums) {
		std::cout << num << " ";
	}
		return 0;
}