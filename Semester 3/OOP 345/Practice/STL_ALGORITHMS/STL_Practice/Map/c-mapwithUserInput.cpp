#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> people;
    int count;
    std::string name, city;

    std::cout << "How many people? ";
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        std::cout << "Enter name: ";
        std::cin >> name;

        std::cout << "Enter city: ";
        std::cin >> city;

        people[name] = city;
    }

    std::cout << "\nList of people (sorted by name):\n";
    for (const auto& pair : people) {
        std::cout << pair.first << " lives in " << pair.second << ".\n";
    }

    return 0;
}
