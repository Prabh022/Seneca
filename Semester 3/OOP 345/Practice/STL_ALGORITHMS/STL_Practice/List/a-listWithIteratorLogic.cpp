#include<iostream>
#include<list>

int main() {
	std::list<int> nums;
	int count, input, remove;

	std::cout << "How many numbers would you like in List: ";
	std::cin >> count;
	std::cout << " Enter " << count << " numbers: ";
	for (int i = 0;i < count; i++) {
		std::cin >> input;
		nums.push_back(input);
	}
	std::cout << "Numbers entered are: ";
	for (int num : nums) {
		std::cout << num << " ";
	}
	std::cout << "\nEnter the number you would like to remove: ";
	std::cin >> remove;
	std::list<int>::iterator it = std::find(nums.begin(), nums.end(), remove);
	if (it != nums.end()) {
		nums.remove(remove);
		std::cout << remove << " has been removed from the list.\n";
	}
	else {
		std::cout << remove << " was not found in the list.\n";
	}
	std::cout << "Numbers in the list after Removal: ";
	for (int num : nums) {
		std::cout << num << " ";
	}
	return 0;
}