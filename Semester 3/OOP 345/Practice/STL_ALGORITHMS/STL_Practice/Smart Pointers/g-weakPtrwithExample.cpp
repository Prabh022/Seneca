#include <iostream>
#include <memory>
#include <string>

class Person;

class Pet {
    std::string name;
    std::weak_ptr<Person> owner;  // weak_ptr to avoid ownership cycle
public:
    Pet(std::string name) : name(name) {}
    void setOwner(std::shared_ptr<Person> p) { owner = p; }

    void whoOwnsMe() const {
        if (auto sp = owner.lock()) {
            std::cout << name << " is owned by " << sp->getName() << "\n";
        }
        else {
            std::cout << name << " has no owner.\n";
        }
    }
};

class Person : public std::enable_shared_from_this<Person> {
    std::string name;
    std::shared_ptr<Pet> pet;
public:
    Person(std::string name) : name(name) {}
    void adopt(std::shared_ptr<Pet> p) {
        pet = p;
        p->setOwner(shared_from_this());
    }
    std::string getName() const { return name; }
};

int main() {
    std::shared_ptr<Pet> fluffy = std::make_shared<Pet>("Fluffy");

    {
        std::shared_ptr<Person> alice = std::make_shared<Person>("Alice");
        alice->adopt(fluffy);

        std::cout << "[Inside scope]: ";
        fluffy->whoOwnsMe();  // Will show Alice as owner
    } // alice goes out of scope and is destroyed here

    std::cout << "[Outside scope]: ";
    fluffy->whoOwnsMe();  // Should now say Fluffy has no owner

    return 0;
}
