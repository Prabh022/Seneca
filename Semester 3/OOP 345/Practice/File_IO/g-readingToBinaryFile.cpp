#include<fstream>
#include<iostream>
using namespace std;
struct Student {
	char name[50];
	int marks;
};
int main() {
	ifstream in("data.dat", ios::binary);
	Student s;

	while (in.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
		cout << "Name: " << s.name << ", Scores: " << s.marks << endl;
	}
	in.close();
	return 0;

}