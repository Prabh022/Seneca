#include<iostream>  
#include<queue>  

int main() {  
std::queue<int> nums;  
int count, input;  

std::cout << "How many numbers would you like in Queue: ";  
std::cin >> count;  
std::cout << "Enter the numbers you would like to enter: ";  
for (int i = 0; i < count; i++) {  
	std::cin >> input;  
	nums.push(input);  
}  

std::cout << "\nPopping values: \n";  
while (!nums.empty()) {  
	std::cout << nums.front() << " \n";  
	nums.pop();  
}  

return 0;  
}