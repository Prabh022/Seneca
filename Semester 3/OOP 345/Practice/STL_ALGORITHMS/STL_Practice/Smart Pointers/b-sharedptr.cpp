#include<iostream>
#include<memory>

int main() {

	std::shared_ptr<int> p1 = std::make_shared<int>(41);
	std::shared_ptr<int> p2 = p1;

	std::cout << "p1: " << *p1 << " use_count: " << p1.use_count() << std::endl;
	std::cout << "p2 " << *p2 << " use_count: " << p2.use_count() << std::endl;

	p1.reset();
	std::cout << "p1 is reset.\n";
	std::cout << "p2 " << *p2 << " use_count: " << p2.use_count() << std::endl;

	return 0;
}