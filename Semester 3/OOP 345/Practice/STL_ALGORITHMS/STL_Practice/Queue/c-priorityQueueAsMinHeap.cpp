#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int count, input;

    std::cout << "How many numbers to insert in Min-Heap? ";
    std::cin >> count;

    std::cout << "Enter " << count << " numbers:\n";
    for (int i = 0; i < count; ++i) {
        std::cin >> input;
        minHeap.push(input);
    }

    std::cout << "\nPopping values (smallest to largest):\n";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << "\n";
        minHeap.pop();
    }

    return 0;
}
