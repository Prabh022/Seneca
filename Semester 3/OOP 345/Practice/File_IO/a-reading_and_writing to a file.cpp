#include<iostream>
#include<string>
#include<fstream>

using namespace std;
int main() {
	string filename = "sample.txt";
	string line;
	ofstream outFile(filename);
	if (!outFile) {
		cerr << "Error opening the file!\n";
		return 1;
	}
	// Writing to a file
	cout << "Enter some text to save in the file: ";
	getline(cin, line);
	outFile << line << endl;
	outFile.close();
	
	// Reading from a File
	ifstream inFile(filename);
	if (!inFile) {
		cerr << " Error opening file for Reading.\n";
		return 1;
	}
	cout << "Reading from the File: " << filename << endl;

	while (getline(inFile, line)) {
		cout << line << endl;
	}
	inFile.close();
		return 0;
}