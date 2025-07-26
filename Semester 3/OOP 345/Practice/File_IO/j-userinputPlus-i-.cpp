#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    char name[50];
    int marks;
};

void writeToFile(const vector<Student>& students, const string& filename) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cerr << "Failed to open file for writing\n";
        return;
    }

    size_t size = students.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const auto& s : students) {
        out.write(reinterpret_cast<const char*>(&s), sizeof(Student));
    }

    out.close();
}

vector<Student> readFromFile(const string& filename) {
    ifstream in(filename, ios::binary);
    vector<Student> students;

    if (!in) {
        cerr << "Failed to open file for reading\n";
        return students;
    }

    size_t size = 0;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));

    students.resize(size);
    for (size_t i = 0; i < size; ++i) {
        in.read(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }

    in.close();
    return students;
}

int main() {
    int n;
    cout << "How many students do you want to enter? ";
    cin >> n;

    vector<Student> students;
    students.reserve(n);

    for (int i = 0; i < n; ++i) {
        Student s;
        cout << "Enter name (max 49 chars): ";
        cin.ignore();  // Clear newline from previous input
        cin.getline(s.name, 50);

        cout << "Enter marks: ";
        cin >> s.marks;

        students.push_back(s);
    }

    writeToFile(students, "students.bin");

    cout << "\nStudents saved. Reading back from file...\n";
    vector<Student> loaded = readFromFile("students.bin");

    for (const auto& s : loaded) {
        cout << "Name: " << s.name << ", Marks: " << s.marks << endl;
    }

    return 0;
}
