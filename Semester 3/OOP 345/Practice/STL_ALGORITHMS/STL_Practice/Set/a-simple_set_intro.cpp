#include <iostream>
#include <set>

int main() {
    std::set<int> s;

    s.insert(5);
    s.insert(8);
    s.insert(5);
    s.insert(34);

    std::cout << "Set Contents: ";
    for (int x : s) {
        std::cout << x << " ";
    }
    return 0;
}