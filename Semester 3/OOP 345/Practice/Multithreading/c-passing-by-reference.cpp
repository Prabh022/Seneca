#include<iostream>
#include<thread>

using namespace std;

void addOne(int& x) {
	x += 1;
}

int main() {
	int num = 5;
	thread t(addOne, ref(num));
	t.join();

	cout << "num after thread: " << num << endl;

	return 0;
}