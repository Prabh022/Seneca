#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ageMap;  // name → age

    int count;
    std::string name;
    int age;

    std::cou2t << "How many people? ";
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        std::cout << "\nEnter name: ";
        std::cin >> name;

        std::cout << "Enter age: ";
        std::cin >> age;

        ageMap[name] = age;  // store the pair in the map
    }

    std::cout << "\nAll people (sorted by name):\n";
    for (const auto& pair : ageMap) {
        std::cout << pair.first << " is " << pair.second << " years old.\n";
    }

    return 0;
}
