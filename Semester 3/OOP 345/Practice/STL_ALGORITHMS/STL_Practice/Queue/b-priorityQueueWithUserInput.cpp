#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;
    int count, input;

    std::cout << "How many numbers do you want to add to the Priority Queue? ";
    std::cin >> count;

    std::cout << "Enter " << count << " numbers:\n";
    for (int i = 0; i < count; ++i) {
        std::cin >> input;
        pq.push(input);
    }

    std::cout << "\nPopping values in priority order:\n";
    while (!pq.empty()) {
        std::cout << pq.top() << "\n";  // always prints the largest remaining
        pq.pop();
    }

    return 0;
}
