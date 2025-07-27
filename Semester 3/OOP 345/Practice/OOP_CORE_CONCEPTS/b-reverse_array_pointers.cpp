#include<iostream>

using namespace std;

void reverseArray(int* start, int size) {
    int* end = start + size - 1;

    while (start < end) {
        // Swap values pointed to by start and end
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers closer to the center
        ++start;
        --end;
    }
}
int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    reverseArray(arr, 5);

    for (int i = 0; i < 5; ++i)
        std::cout << arr[i] << " ";


	return 0;
}