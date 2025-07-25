#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Book {
    char* title;
    static int idCounter;
    int id;

public:
    Book(const char* name) : id(++idCounter) {
        cout << "[#" << id << "] Constructor\n";
        title = new char[strlen(name) + 1];
        strcpy(title, name);
    }

    Book(const Book& other) : id(++idCounter) {
        cout << "[#" << id << "] Copy Constructor from #" << other.id << "\n";
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
    }

    Book& operator=(const Book& other) {
        cout << "[#" << id << "] Copy Assignment from #" << other.id << "\n";
        if (this != &other) {
            delete[] title;
            title = new char[strlen(other.title) + 1];
            strcpy(title, other.title);
        }
        return *this;
    }

    Book(Book&& other) noexcept : id(++idCounter) {
        cout << "[#" << id << "] Move Constructor from #" << other.id << "\n";
        title = other.title;
        other.title = nullptr;
    }

    Book& operator=(Book&& other) noexcept {
        cout << "[#" << id << "] Move Assignment from #" << other.id << "\n";
        if (this != &other) {
            delete[] title;
            title = other.title;
            other.title = nullptr;
        }
        return *this;
    }

    ~Book() {
        cout << "[#" << id << "] Destructor\n";
        delete[] title;
    }
};

int Book::idCounter = 0;

int main() {
    vector<Book> books;

    cout << "\n--- Pushing temporary object ---\n";
    books.push_back(Book("Effective C++")); // should call move constructor

    cout << "\n--- Creating then pushing named object ---\n";
    Book b2("Clean Code");
    books.push_back(b2); // should call copy constructor

    cout << "\n--- Emplacing directly ---\n";
    books.emplace_back("Design Patterns"); // should use constructor directly, no move/copy

    cout << "\n--- End of main ---\n";
}
