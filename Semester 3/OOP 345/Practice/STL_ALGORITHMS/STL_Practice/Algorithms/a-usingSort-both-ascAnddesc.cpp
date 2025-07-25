#include<iostream>
#include<vector>
#include<algorithm>  // for sort

using namespace std;
int main() {
	vector<int> nums;
	int input;
	cout << "Enter 5 numbers: ";
	for (int i = 0; i < 5; i++) {
		cin >> input;
		nums.push_back(input);
	}
	cout << "\nThe numbers entered are: ";
	for (int num : nums) {
		cout << num << " ";
	}
	sort(nums.begin(), nums.end());
	cout << "\nSorted numbers entered(Asc) are: ";
	for (int num : nums) {
		cout << num << " ";
	}
	sort(nums.begin(), nums.end(), [](int a, int b) {
		return a > b;
		});
	cout << "\nSorted numbers entered(Desc) are: ";
	for (int num : nums) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}