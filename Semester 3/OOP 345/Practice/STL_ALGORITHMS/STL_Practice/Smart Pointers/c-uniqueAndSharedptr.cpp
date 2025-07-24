#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<std::string> name = std::make_unique<std::string>("Prabh");
    std::cout << "Name: " << *name << std::endl;

    std::shared_ptr<int> age = std::make_shared<int>(23);
    std::shared_ptr<int> ageCopy = age;

    std::cout << "Age: " << *age << ", Copies: " << age.use_count() << std::endl;

    return 0;
}
