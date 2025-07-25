#include<iostream>
#include<functional>

int square(int x) {
	return x * x;
}


using namespace std;
int main() {
	std::function<int(int)> f1 = square;
	std::cout << f1(5); 

	return 0;
}