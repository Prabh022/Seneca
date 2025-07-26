#include<iostream>
#include<fstream>

int main() {
	std::ifstream inFile("data.txt");
	int num;
	while (inFile >> num) {
		std::cout << "Reading numbers: " << num << "\n";
	}
	std::cout << std::endl;

	return 0;
}