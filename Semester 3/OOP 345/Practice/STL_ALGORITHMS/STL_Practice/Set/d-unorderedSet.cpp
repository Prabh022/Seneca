#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> s;
    int input, count;

    std::cout << "Enter the numbers you want to include: ";
    std::cin >> count;
    std::cout << "Enter " << count << " numbers:";
    for (int i = 0; i < count;i++) {
        std::cin >> input;
        s.insert(input);
    }
    std::cout << "Unique numbers entered are: ";
    for (int num : s) {
        std::cout << num << " ";
    }
    std::cout << "\nTotal unique numbers are: " << s.size() << std::endl;
    int searchNum;
    std::cout << "\nEnter a number to search: ";
    std::cin >> searchNum;

    if (s.find(searchNum) != s.end()) {
        std::cout << searchNum << " exists in the set.\n";
    }
    else {
        std::cout << searchNum << " does not exist in the set.\n";
    }

    return 0;
}