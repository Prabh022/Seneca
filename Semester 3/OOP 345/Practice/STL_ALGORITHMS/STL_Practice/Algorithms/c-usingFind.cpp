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
	 auto it = find(nums.begin(), nums.end(), 20);
	 if (it != nums.end()) {
		 cout << "\n20 was found at index: " << distance(nums.begin(), it);
	 }
	 else {
		 cout << "\n20 was not found in the list.";
	 }

	cout << endl;
	return 0;
}