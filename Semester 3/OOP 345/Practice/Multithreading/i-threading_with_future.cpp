#include<iostream>  
#include<thread>  
#include<future>  

int square(int x) {  
return x * x;  
}  

int main() {
	std::future<int> fut = std::async(std::launch::async, square, 23);


	// Do other stuff until calculation is going on
	std::cout << "Calculating..." << std::endl;

	int result = fut.get(); // wait here until get the result

	std::cout << "Final Result of Square is: " << result << std::endl;

	return 0;

}