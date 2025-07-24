#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Employee {
    std::string name;
    int id;
public:
    Employee(std::string name, int id) : name(name), id(id) {}
    void display() const {
        std::cout << "Name: " << name << " | ID: " << id << std::endl;
    }
};

int main() {
    std::vector<std::shared_ptr<Employee>> employees;
    int count = 3;
    std::string name;
    int id;

    std::cout << "Enter details for " << count << " employees:\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "\nEmployee " << i + 1 << " Name: ";
        std::cin >> name;
        std::cout << "Employee " << i + 1 << " ID: ";
        std::cin >> id;

        employees.push_back(std::make_shared<Employee>(name, id));
    }

    std::cout << "\nAll Employees:\n";
    for (const auto& emp : employees) {
        emp->display();
    }

    return 0;
}
