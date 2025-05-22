#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H

#include "Employee.h"

namespace seneca {

    class Professor : public Employee {
        char* m_subject{};
        int m_sections{};

        void deallocate(); // handles dynamic memory cleanup

    public:
        Professor(); // no-arg
        Professor(const char* name, const char* subject, int sections, size_t empNo, double salary); // 5-arg
        ~Professor();

        double devPay() const;

        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::ostream& title(std::ostream& ostr = std::cout) const;
    };

    std::istream& operator>>(std::istream& istr, Professor& P);
    std::ostream& operator<<(std::ostream& ostr, const Professor& P);

}

#endif // SDDS_PROFESSOR_H
