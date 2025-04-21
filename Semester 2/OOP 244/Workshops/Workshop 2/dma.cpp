#include <iostream>
#include "dma.h"
using namespace std;
namespace seneca {
    void reverse() {
        int numValues;

        std::cout << "Enter the number of double values:\n> ";
        std::cin >> numValues;

        // Validate input (optional)
        if (numValues <= 0) {
            std::cout << "Invalid number of values.\n";
            return;
        }

        // Dynamic allocation
        double* values = new double[numValues];

        // Input loop
        for (int i = 0; i < numValues; ++i) {
            std::cout << (i + 1) << "> ";
            std::cin >> values[i];
        }

        // Reverse output loop
        for (int i = numValues - 1; i >= 0; --i) {
            std::cout << values[i] << std::endl;
        }

        // Deallocate memory
        delete[] values;
    }

    Contact* getContact() {
        Contact* newContact = new Contact;

        std::cout << "Name: ";
        std::cin.getline(newContact->m_name, 21);

        std::cout << "Last name: ";
        std::cin.getline(newContact->m_lastname, 31);

        std::cout << "Phone number: ";
        std::cin >> newContact->m_phoneNumber;

        return newContact;
    }
    void display(const Contact& c) {
        std::cout << c.m_name << " " << c.m_lastname << ", +" << c.m_phoneNumber << std::endl;
    }
    void deallocate(Contact* c) {
        delete c;
    }
    
    void setEmpty(Contact& c) {
        c.m_name[0] = '\0';        // set name to empty C-string
        c.m_lastname[0] = '\0';    // set lastname to empty C-string
        c.m_phoneNumber = 0;       // set phone number to 0
    }

}
