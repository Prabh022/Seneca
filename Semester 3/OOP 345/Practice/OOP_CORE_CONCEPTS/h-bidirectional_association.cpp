#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Doctor; // Forward declaration

class Patient {
    string name;
    vector<Doctor*> doctors; // knows doctors
public:
    Patient(string n) : name(n) {}

    void addDoctor(Doctor* d); // declare

    string getName() const { return name; }

    void showDoctors();
};

class Doctor {
    string name;
    vector<Patient*> patients; // knows patients
public:
    Doctor(string n) : name(n) {}

    void addPatient(Patient* p) {
        patients.push_back(p);
        p->addDoctor(this); // ensure bidirectional link
    }

    string getName() const { return name; }

    void showPatients() {
        cout << "Dr. " << name << "'s patients: ";
        for (auto p : patients)
            cout << p->getName() << " ";
        cout << "\n";
    }
};

void Patient::addDoctor(Doctor* d) {
    doctors.push_back(d); // don't call back again (to avoid infinite recursion)
}

void Patient::showDoctors() {
    cout << name << "'s doctors: ";
    for (auto d : doctors)
        cout << d->getName() << " ";
    cout << "\n";
}

int main() {
    Doctor d1("Smith");
    Doctor d2("Brown");

    Patient p1("Alice");
    Patient p2("Bob");

    d1.addPatient(&p1);
    d1.addPatient(&p2);

    d2.addPatient(&p1); // Alice has 2 doctors

    d1.showPatients();
    d2.showPatients();

    p1.showDoctors();
    p2.showDoctors();

    return 0;
}
