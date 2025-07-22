#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "NameTag.h"
using namespace std;
namespace seneca {

    NameTag::NameTag() {
        m_name[0] = '\0';
    }

    void NameTag::set(const char* name) {
        strncpy(m_name, name, 50);
        m_name[50] = '\0';  // ensure null-termination
    }

    const char* NameTag::name() const {
        return m_name;
    }

    void NameTag::print(int width) const {
        size_t nameLength = strlen(m_name);
        int frameWidth = (width > nameLength) ? width : nameLength;

        cout << '+';
        for (int i = 0; i < frameWidth + 2; i++) cout << '-';
        cout << '+' << endl;

        cout << "| " << m_name;
        for (int i = 0; i < frameWidth - nameLength; i++) cout << ' ';
        cout << " |" << endl;

        cout << '+';
        for (int i = 0; i < frameWidth + 2; i++) cout << '-';
        cout << '+' << endl;
    }

}
