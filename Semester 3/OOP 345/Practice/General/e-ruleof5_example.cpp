#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Book {
    char* title;

public:
    Book(const char* name) {
        // allocate memory for title
        cout << "Constructor" << endl;
        title = new char[strlen(name) + 1];
        strcpy(title, name);
   }
    Book(const Book& other) {
        // allocate new memory and copy title
        cout << "Copy Constructor" << endl;
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
    }

    // copy assignment constructor
    Book& operator=(const Book& other) {
        cout << "Copy Assignment Constructor" << endl;
        if (this != &other) {
            delete[] title;

            title = new char[strlen(other.title) + 1];
            strcpy(title, other.title);
        }
        return *this;
    }
    // Move Constructor
    Book(Book&& other) noexcept {
        cout << "Move Constructor" << endl;
        title = other.title;
        title = nullptr;
    }
    // Move Assignment Constructor
    Book& operator=(Book&& other) noexcept {
        if (this != &other) {
            delete[] title;

            cout << "Move Assignment Constructor" << endl;
            title = other.title;
            title = nullptr;
        }
        return *this;
    }
    // Destructor
    ~Book() {
        cout << "Destructor" << endl;
        delete[] title;
    }
    void show() const {
        cout << "Name of the book is: " << title << endl;
    }
};

int main() {
    Book b1("C++ Mastery");
    Book b2 = b1;
    Book b3("Temporary");
    b3 = b2;
    b1.show();
    b2.show();
    b3.show();
    Book b4 = std::move(b1);   // Move Constructor
    Book b5("Learning C++");
    b5 = std::move(b2);        // Move Assignment
}
