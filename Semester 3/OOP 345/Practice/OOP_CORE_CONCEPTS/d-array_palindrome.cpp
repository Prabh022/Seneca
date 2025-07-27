#include <iostream>
using namespace std;

bool isPalindrome(int* start, int size) {
    int* left = start;
    int* right = start + size - 1;

    while (left < right) {
        if (*left != *right)
            return false;

        ++left;
        --right;
    }

    return true;
}
int main() {
    int arr[] = { 1, 2, 3, 2, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isPalindrome(arr, size))
        cout << "Array is a palindrome!" << endl;
    else
        cout << "Array is NOT a palindrome." << endl;

    return 0;
}