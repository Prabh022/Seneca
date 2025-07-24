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
    std::string er_name;
    std::cout << "\nWhat person you want to remove: ";
    std::cin >> er_name;
    auto it = people.find(er_name);
    if (it != people.end()) {
        people.erase(er_name);
        std::cout << er_name << " was removed from the list.\n";
    }
    else {
        std::cout << er_name << " was not found in the list.\n";
    }
    std::cout << "\nList of people (In Reverse Order and after Removal):\n";
    for (auto it = people.rbegin(); it != people.rend(); ++it) {
        std::cout << it->first << " lives in " << it->second << "\n";
    }




    return 0;
}
