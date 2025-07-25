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
	Person(const Person& other) {
		cout << "Copy Constructor" << endl;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
	Person& operator=(const Person& other) {
		cout << "Copy Assignment Operator" << endl;
		if (this != &other) {
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
		}
		return *this;
	}
	void show() const {
		cout << "Name: " << name << endl;
	}

};


int main() {

	Person p1("Alice");
	Person p2("John");
	 p2 = p1;
	p1.show();
	p2.show();
	return 0;
}