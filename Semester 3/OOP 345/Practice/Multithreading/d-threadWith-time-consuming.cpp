#include<iostream>
#include<chrono>
#include<thread>

using namespace std;

void square(int n) {
	this_thread::sleep_for(chrono::seconds(1));
	int result = n * n;
	cout << "Square of " << n << " is: " << result << endl;
}

int main() {
	thread t1(square, 5);
	thread t2(square, 8);
	thread t3(square, 65);
	
	
	t1.join();
	t2.join();
	t3.join();

	cout << "The Program has ended successfully.";

	return 0;
}