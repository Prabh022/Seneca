#include<iostream>  
#include<stack>  

int main() {  
std::stack<int> nums;  
int count, input;  

std::cout << "How many numbers would you like in Stack: ";  
std::cin >> count;  
std::cout << "Enter the numbers you would like to enter: ";  
for (int i = 0; i < count; i++) {  
	std::cin >> input;  
	nums.push(input);  
}  

std::cout << "\nPopping values: ";  
while (!nums.empty()) {  
	std::cout << nums.top() << " \n";  
	nums.pop();  
}  

return 0;  
}