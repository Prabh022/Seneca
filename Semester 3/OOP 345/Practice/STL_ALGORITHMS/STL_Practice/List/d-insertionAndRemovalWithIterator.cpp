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
	auto insert_it = nums.insert(it,250);  // we could have used just this as well - nums.insert(it,250);, 
	                                       //but that would have given error for inser_it at bottom
	std::cout << "\nNumbers of the list are: ";
	for (int num : nums) {
		std::cout << num << " ";
	}
	//std::advance(it, 2);

	nums.erase(insert_it);
	/* Remove 200 by iterator
	auto erase_it = nums.begin();
	std::advance(erase_it, 1); // 100 → 200
	nums.erase(erase_it);
	-- We can use this as well for better control on what number to deleted
	*/
	std::cout << "\nNumbers of the list are: ";
	for (int num : nums) {
		std::cout << num << " ";
	}
		return 0;
}