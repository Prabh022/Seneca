#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Student {
    char name[50];  // Use fixed-size char array instead of std::string
    int marks;
};
void writeToFile(const vector<Student>& students, const string& filename) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cerr << "Failed to open file for writing\n";
        return;
    }

    size_t size = students.size();
    out.write(reinterpret_cast<char*>(&size), sizeof(size)); // Write vector size

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
    in.read(reinterpret_cast<char*>(&size), sizeof(size)); // Read vector size

    students.resize(size); // Prepare space

    for (size_t i = 0; i < size; ++i) {
        in.read(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }

    in.close();
    return students;
}
int main() {
    vector<Student> original = {
        {"Alice", 85},
        {"Bob", 90},
        {"Charlie", 78}
    };

    writeToFile(original, "students.bin");

    vector<Student> loaded = readFromFile("students.bin");

    cout << "\n--- Loaded Students ---\n";
    for (const auto& s : loaded) {
        cout << "Name: " << s.name << ", Marks: " << s.marks << endl;
    }

    return 0;
}
