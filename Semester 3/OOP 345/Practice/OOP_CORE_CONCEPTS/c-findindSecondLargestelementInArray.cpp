#include <iostream>
#include <climits>
using namespace std;

int findSecondLargest(int* arr, int size) {
    if (size < 2) return -1;  // Handle edge case

    int* ptr = arr;
    int largest = *ptr;
    int second = INT_MIN;

    for (int i = 1; i < size; ++i) {
        ptr++;
        if (*ptr > largest) {
            second = largest;
            largest = *ptr;
        }
        else if (*ptr > second && *ptr != largest) {
            second = *ptr;
        }
    }

    return second;
}

int main() {
    int nums[] = { 45, 22, 11, 87, 66, 87 };
    int size = sizeof(nums) / sizeof(nums[0]);

    int secondMax = findSecondLargest(nums, size);

    if (secondMax != -1)
        cout << "Second largest number: " << secondMax << endl;
    else
        cout << "Array too small to determine second largest." << endl;

    return 0;
}