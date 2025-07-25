#include<iostream>
#include<functional>

struct Tripler {
	int operator()(int x) const { return x * 3; }
};

using namespace std;
int main() {
	function<int(int)> doubler = [](int x) {
		return x * 2;
		};
	function<int(int)> f = Tripler();
	cout << doubler(10) << endl;
	cout << f(10) << endl;
	

	return 0;
}