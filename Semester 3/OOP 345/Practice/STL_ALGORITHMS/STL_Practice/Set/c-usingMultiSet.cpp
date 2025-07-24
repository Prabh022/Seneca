#include <iostream>
#include <set>

int main() {
    std::multiset<int> s;
    int input, count;

    std::cout << "Enter the numbers you want to include: ";
    std::cin >> count;
    std::cout << "Enter " << count << " numbers:";
    for (int i = 0; i < count;i++) {
        std::cin >> input;
        s.insert(input);
    }
    std::cout << "Sorted Numbers entered are: ";
    for (int num : s) {
        std::cout << num << " ";
    }
    std::cout << "\nTotal numbers are: " << s.size() << std::endl;
    return 0;
}