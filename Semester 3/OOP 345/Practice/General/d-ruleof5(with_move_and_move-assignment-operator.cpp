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
	Person(Person&& other) noexcept {
		name = other.name;
		other.name = nullptr;
		cout << "Moved Constructor." << endl;
	}
	Person& operator=(Person&& other) noexcept {
		if (this != &other) {
			delete[] name;
			name = other.name;
			other.name = nullptr;
			cout << "Move Assignment Operator." << endl;
		}
		return *this;
	}
	void show() const {
		cout << "Name: " << name << endl;
	}

};


int main() {
	Person a("Prabh");
	Person b = a;                 // Copy Constructor
	Person c("Other");
	c = a;                        // Copy Assignment

	Person d = std::move(a);      // Move Constructor
	Person e("Someone");
	e = std::move(b);             // Move Assignment
}
