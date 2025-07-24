#include<iostream>
#include<memory>

int main() {

	std::unique_ptr<int> p1 = std::make_unique<int>(41);
	std::cout << "Value: " << *p1 << std::endl;
	

	// p2 = p1; // ❌ Error: can't copy unique_ptr
	std::unique_ptr<int> p2 = std::move(p1);
	if (!p1) std::cout << "p1 is now null.\n";
	std::cout << "p2 now holds: " << *p2 << std::endl;

	return 0;
}