#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Numbers.h"

using namespace std;

namespace seneca {

    Numbers::~Numbers() {
        if (m_isOriginal && !isEmpty()) {
            save();
        }
        delete[] m_numbers;
        delete[] m_filename;
    }

    Numbers::Numbers(const Numbers& other) {
        setEmpty();
        m_isOriginal = false;
        *this = other;
    }

    Numbers& Numbers::operator=(const Numbers& other) {
        if (this != &other) {
            delete[] m_numbers;
            m_numbers = nullptr;
            m_numCount = other.m_numCount;
            if (m_numCount > 0) {
                m_numbers = new double[m_numCount];
                for (int i = 0; i < m_numCount; ++i) {
                    m_numbers[i] = other.m_numbers[i];
                }
            }
        }
        return *this;
    }

    int Numbers::numberCount() const {
        ifstream file(m_filename);
        int count = 0;
        char ch;
        while (file.get(ch)) {
            if (ch == '\n') {
                count++;
            }
        }
        return count;
    }

    bool Numbers::load() {
        bool success = false;
        if (m_numCount > 0) {
            m_numbers = new double[m_numCount];
            ifstream file(m_filename);
            int i = 0;
            while (file && i < m_numCount) {
                file >> m_numbers[i];
                if (file) i++;
            }
            if (i == m_numCount) {
                success = true;
            }
            else {
                delete[] m_numbers;
                m_numbers = nullptr;
                setEmpty();
            }
        }
        return success;
    }

    void Numbers::save() const {
        if (m_isOriginal && !isEmpty()) {
            ofstream file(m_filename);
            for (int i = 0; i < m_numCount; ++i) {
                file << m_numbers[i] << endl;
            }
        }
    }

    Numbers& Numbers::operator+=(double value) {
        if (!isEmpty()) {
            double* temp = new double[m_numCount + 1];
            for (int i = 0; i < m_numCount; ++i) {
                temp[i] = m_numbers[i];
            }
            temp[m_numCount++] = value;
            delete[] m_numbers;
            m_numbers = temp;
            sort();
        }
        return *this;
    }

    std::ostream& Numbers::display(std::ostream& ostr) const {
        if (isEmpty()) {
            ostr << "Empty list";
        }
        else {
            ostr << fixed << setprecision(2);
            ostr << "=========================" << endl;
            if (m_isOriginal) {
                ostr << m_filename << endl;
            }
            else {
                ostr << "*** COPY ***" << endl;
            }
            for (int i = 0; i < m_numCount; ++i) {
                ostr << m_numbers[i];
                if (i < m_numCount - 1) ostr << ", ";
            }
            ostr << endl;
            ostr << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average:         " << average() << endl;
            ostr << "=========================";
        }
        return ostr;
    }

    std::ostream& operator<<(std::ostream& os, const Numbers& N) {
        return N.display(os);
    }

    std::istream& operator>>(std::istream& is, Numbers& N) {
        double value;
        is >> value;
        if (is) {
            N += value;
        }
        return is;
    }

}
