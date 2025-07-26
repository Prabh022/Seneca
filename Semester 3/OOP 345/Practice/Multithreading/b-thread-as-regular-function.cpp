#include<iostream>
#include<thread>

using namespace std;

void greet(string name) {
	cout << "Hello! " << name <<  endl;
}

int main() {
	thread t1(greet, "Samdish");

	t1.join();
	
	 
	cout << "Have a Good Day!\n";

	return 0;
}