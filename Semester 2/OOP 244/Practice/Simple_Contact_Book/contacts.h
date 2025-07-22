#ifndef CONTACT_H
#define CONTACT_H

#include <string>
namespace Working {
    class Contact {
    private:
        std::string name;
        std::string phone;

    public:
        void input();
        void display() const;
        std::string getName() const;

        static void addContact(const std::string& filename);
        static void viewContacts(const std::string& filename);
        static void searchContact(const std::string& filename, const std::string& targetName);
    };
}
#endif
