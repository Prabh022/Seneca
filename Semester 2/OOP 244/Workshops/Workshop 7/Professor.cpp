#define _CRT_SECURE_NO_WARNINGS
#include "Professor.h"
#include "Utils.h"
#include <cstring>
#include <iomanip>

namespace seneca {

    void Professor::deallocate() {
        delete[] m_subject;
        m_subject = nullptr;
    }

    Professor::Professor() : m_subject(nullptr), m_sections(0) {}

    Professor::Professor(const char* name, const char* subject, int sections, size_t empNo, double salary)
        : Employee(name, empNo, salary), m_subject(nullptr), m_sections(sections) {
        Utils u;
        u.alocpy(m_subject, subject);
    }

    Professor::~Professor() {
        deallocate();
    }

    double Professor::devPay() const {
        return (salary() * 0.01) * m_sections;
    }

    std::istream& Professor::read(std::istream& istr) {
        char tempSubject[1024];
        int tempSections;

        Employee::read(istr);

        istr.ignore(); // skip comma after salary if needed
        istr.getline(tempSubject, 1024, ',');
        istr >> tempSections;
        istr.ignore(1000, '\n');

        deallocate();
        Utils u;
        u.alocpy(m_subject, tempSubject);
        m_sections = tempSections;

        return istr;
    }

    std::ostream& Professor::write(std::ostream& ostr) const {
        ostr << " ";
        Employee::write(ostr);
        ostr << " " << std::left << std::setw(20)
            << (m_subject ? m_subject : "") << " | "
            << std::right << std::setw(5) << m_sections << " | "
            << std::setw(8) << std::fixed << std::setprecision(2)
            << devPay() << " |";
        return ostr;
    }

    std::ostream& Professor::title(std::ostream& ostr) const {
        Employee::title(ostr);
        ostr << " Teaching Subject | Sec # | $Dev Pay |";
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Professor& P) {
        return P.read(istr);
    }

    std::ostream& operator<<(std::ostream& ostr, const Professor& P) {
        return P.write(ostr);
    }

}
