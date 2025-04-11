#include <iostream>
#include<cstring>

using namespace std;

int main(void) {
	string name;
	int age;

	cout << "Please enter your name" << endl;
	cin >> name;
	cout << "Please enter your age" << endl;
	cin >> age;
	cout << "Your name is " << name << " and you are " << age << " years old" << endl;

	return 0;
}