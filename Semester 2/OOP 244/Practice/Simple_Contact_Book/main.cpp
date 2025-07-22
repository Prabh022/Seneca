#include <iostream>
#include "Contacts.h"

using namespace std;
    int main() {
        int choice;
        string filename = "contacts.txt";
        string searchName;

        while (true) {
            cout << "\n--- Contact Book ---\n";
            cout << "1. Add Contact\n";
            cout << "2. View All Contacts\n";
            cout << "3. Search Contact by Name\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                Working::Contact::addContact(filename); // we can also use - using namespace Working if we don't want this way of putting working;
                break;
            case 2:
                Working::Contact::viewContacts(filename);
                break;
            case 3:
                cin.ignore(); // flush newline
                cout << "Enter name to search: ";
                getline(cin, searchName);
                Working::Contact::searchContact(filename, searchName);
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
            }
        }
    }
