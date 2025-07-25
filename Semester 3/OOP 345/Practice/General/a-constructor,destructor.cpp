#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class Person {
	char* name;
	int age;

public:
	Person(const char* pers) {
		cout << "Constructor" << endl;
		name = new char[strlen(pers) + 1];
		strcpy(name, pers);
	}
	~Person() {
		cout << "Destructor" << endl;
		delete[] name;
	}
	
	void show() const {
		cout << "Name: " << name << endl;
	}

};


int main() {

	Person p1("Alice");
	p1.show();
	return 0;
}