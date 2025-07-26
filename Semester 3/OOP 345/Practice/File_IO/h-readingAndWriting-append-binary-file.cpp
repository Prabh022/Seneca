#include<fstream>
#include<iostream>
using namespace std;
struct Student {
	char name[50];
	int marks;
};
int main() {
	//Writing to a Binary File, Appending version
	
	ofstream out("data.dat", ios::binary | ios::app);

	Student s1 = { "Diego", 75 };
	Student s2 = { "Kyle", 53 };

	out.write(reinterpret_cast<char*>(&s1), sizeof(Student));
	out.write(reinterpret_cast<char*>(&s2), sizeof(Student));

	out.close();
	//Reading to a Binary File
	ifstream in("data.dat", ios::binary);
	Student s;

	while (in.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
		cout << "Name: " << s.name << ", Scores: " << s.marks << endl;
	}
	in.close();
	return 0;

}