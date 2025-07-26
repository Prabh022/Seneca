#include<fstream>
#include<iostream>
using namespace std;
struct Student {
	char name[50];
	int marks;
};
int main() {
	ofstream out("data.dat", ios::binary);
	
	Student s1 = { "Alice", 60 };
	Student s2 = { "David", 73 };

	out.write(reinterpret_cast<char*>(&s1), sizeof(Student));
	out.write(reinterpret_cast<char*>(&s2), sizeof(Student));

	out.close();
	return 0;
}