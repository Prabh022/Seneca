#include <iostream>
#include <deque>
#include <limits> // for INT_MAX

using namespace std;

int main() {
    deque<int> nums;
    int input;

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; ++i) {
        cin >> input;
        nums.push_back(input);
    }

    cout << "\nThe numbers entered are: ";
    for (int num : nums) {
        cout << num << " ";
    }

    int closestAbove100 = INT_MAX;
    bool found = false;

    for (int num : nums) {
        if (num > 100 && num < closestAbove100) {
            closestAbove100 = num;
            found = true;
        }
    }

    if (found) {
        cout << "\nClosest number greater than 100 is: " << closestAbove100;
    }
    else {
        cout << "\nNo number greater than 100 was found.";
    }

    cout << endl;
    return 0;
}