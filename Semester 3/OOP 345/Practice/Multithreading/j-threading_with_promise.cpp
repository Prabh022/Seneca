#include<iostream>
#include<thread>
#include<future>

using namespace std;

void compute(promise<int> prom) {
	this_thread::sleep_for(chrono::seconds(2));
	prom.set_value(34);
}

int main() {
	promise<int> prom;
	future<int> fut = prom.get_future();

	thread t(compute, move(prom));

	cout << "Waiting for the result..." << endl;
	int result = fut.get();
	cout << "The Result is: " << result << endl;

	t.join();

	return 0;
}