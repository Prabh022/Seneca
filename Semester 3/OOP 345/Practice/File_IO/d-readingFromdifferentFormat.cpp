#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

int main() {
	std::ifstream inFile("scores.csv");
	std::string line;

	if (!inFile.is_open()) {
		std::cout << "Error opening the file!.\n";
		return 1;
	}
	while (std::getline(inFile, line)) {
		std::stringstream ss(line); // convert line to a stringstream
		std::string name;
		int scores;

		std::getline(ss, name, ',');
		ss >> scores;

		std::cout << "Name: " << name << ", Scores: " << scores << std::endl;
	}

	return 0;
}