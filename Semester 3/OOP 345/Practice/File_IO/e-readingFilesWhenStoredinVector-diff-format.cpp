#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;
struct Student {
	string name;
	int marks;
};

int main() {
	ifstream inFile("scores.csv");
	vector<Student> students;
	string line;
	
	while(getline(inFile,line)){
		stringstream ss(line);
		string name;
		int marks;

		getline(ss, name, ',');
		ss >> marks;

		students.push_back({ name, marks });


	}

	inFile.close();
	//Display all Students
	for (const auto& s : students) {
		cout << "Name: " << s.name << ", Scores: " << s.marks << endl;
	}
	return 0;
}