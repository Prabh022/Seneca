#include<iostream>
#include<thread>

using namespace std;

void task1() {
	cout << "Task 1 running...\n" << endl;
}
void task2() {
	cout << "Task 2 running...\n" << endl;
}
int main() {
	thread t1(task1);  // launch task 1 on new thread
	thread t2(task2);  // launch task 2 on new thread

	t1.join();  // will wait until task 2 finish
	t2.join();  // will wait until task 1 finish
	 
	cout << "Both task finished successfully!\n";

	return 0;
}