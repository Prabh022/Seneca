#include <iostream>
#include <fstream>
#include <sstream>
#include "Contacts.h"

using namespace std;
namespace Working {
    void Contact::input() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter phone: ";
        getline(cin, phone);
    }

    void Contact::display() const {
        cout << "Name: " << name << ", Phone: " << phone << endl;
    }

    string Contact::getName() const {
        return name;
    }

    void Contact::addContact(const string& filename) {
        Contact c;
        cin.ignore(); // clear leftover newline from previous input
        c.input();

        ofstream file(filename, ios::app);
        if (!file) {
            cout << "Failed to open file." << endl;
            return;
        }

        file << c.name << "," << c.phone << "\n";
        file.close();
        cout << "Contact saved." << endl;
    }

    void Contact::viewContacts(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "No contacts found." << endl;
            return;
        }

        string line;
        cout << "\n--- Contact List ---\n";
        while (getline(file, line)) {
            stringstream ss(line);
            string name, phone;

            if (getline(ss, name, ',') && getline(ss, phone)) {
                cout << "Name: " << name << ", Phone: " << phone << endl;
            }
        }

        file.close();
    }

    void Contact::searchContact(const string& filename, const string& targetName) {
        ifstream file(filename);
        if (!file) {
            cout << "No contacts found." << endl;
            return;
        }

        string line;
        bool found = false;

        while (getline(file, line)) {
            stringstream ss(line);
            string name, phone;

            if (getline(ss, name, ',') && getline(ss, phone)) {
                if (name == targetName) {
                    cout << "Contact found: " << name << " - " << phone << endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found)
            cout << "Contact not found." << endl;

        file.close();
    }
}