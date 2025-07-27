#include<iostream>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<thread>

using namespace std;

mutex mtx;
condition_variable cv;
queue<int> q;
bool finished = false;

void producer() {
	for (int i = 0;i < 5; i++) {
		this_thread::sleep_for(chrono::milliseconds(500));
		unique_lock<mutex> lock(mtx);
		q.push(i);
		cout << "Produced: " << i << endl;
		cv.notify_one();
	}
	//Done producing
	unique_lock<mutex> lock(mtx);
	finished = true;
	cv.notify_one();
		
}

void consumer() {
	while (true) {
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [] { return !q.empty() || finished;});
		
		while (!q.empty()) {
			cout << "Consumed: " << q.front() << endl;
			q.pop();
		}
		if (finished) break;

	}

}

int main() {
	thread t1(producer);
	thread t2(consumer);

	t1.join();
	t2.join();

	cout << "All tasks are completed" << endl;
	return 0;
}









