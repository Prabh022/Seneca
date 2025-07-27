#include<iostream>
#include<future>

int factorial(int n) {
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}

int main() {
	std::future<int> fut = std::async(std::launch::async, factorial, 4);

	std::cout << "Waiting for the calculations..." << std::endl;

	int result = fut.get();

	std::cout << "And the factorial is: " << result << std::endl;


	return 0;
}