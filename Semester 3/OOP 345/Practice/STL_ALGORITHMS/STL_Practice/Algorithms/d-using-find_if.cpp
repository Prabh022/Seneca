#include <iostream>
#include <vector>
#include <algorithm> // for find_if
using namespace std;

int main() {
    vector<int> nums = { 2, 4, 6, 9, 10 };

    auto it = find_if(nums.begin(), nums.end(), [](int val) {
        return val % 2 != 0;
        });

    if (it != nums.end()) {
        cout << "First odd number is: " << *it << endl;
    }
    else {
        cout << "No odd number found." << endl;
    }

    return 0;
}
