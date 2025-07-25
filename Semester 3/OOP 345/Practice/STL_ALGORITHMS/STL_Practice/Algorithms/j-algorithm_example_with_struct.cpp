#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int marks;
};

// Display function for one student
void display(const Student& s) {
    cout << "Name: " << s.name << ", Marks: " << s.marks << endl;
}

int main() {
    vector<Student> students;
    int num;

    cout << "H2ow many students? ";
    cin >> num;

    for (int i = 0; i < num; ++i) {
        Student s;
        cout << "Enter name: ";
        cin.ignore();  // flush leftover newline
        getline(cin, s.name);
        cout << "Enter marks: ";
        cin >> s.marks;
        students.push_back(s);
    }
   //  Sort in descending order by marks
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.marks > b.marks;  // 👈 Descending comparator
        });

    cout << "\n--- Sorted Student List (Descending by Marks) ---\n";
    for (const auto& s : students) {
        display(s);
    }

    return 0;
}