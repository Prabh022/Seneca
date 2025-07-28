#include <iostream>
#include <vector>
using namespace std;

// Function to apply AND, OR, and XOR
int bitwisePuzzle(const vector<int>& arr) {
    int andResult = arr[0];
    int orResult = arr[0];

    // Start from second element since we've used arr[0] already
    for (size_t i = 1; i < arr.size(); ++i) {
        andResult &= arr[i];  // Bitwise AND across all elements
        orResult |= arr[i];  // Bitwise OR across all elements
    }

    return andResult ^ orResult;  // Final XOR of AND and OR
}

int main() {
    // Sample input array
    vector<int> arr = { 6, 3, 9 };

    // Display original array
    cout << "Array elements: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    // Get result
    int result = bitwisePuzzle(arr);

    // Show final answer
    cout << "Final result of (AND ^ OR): " << result << "\n";

    return 0;
}