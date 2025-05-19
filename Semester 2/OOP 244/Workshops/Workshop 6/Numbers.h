/***********************************************************************
// OOP244 Workshop 6 lab
// File	Numbers.h
// Version 0.1
// Author	Fardad Soleimanloo
***********************************************************************/
#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_

#include <iostream>

namespace seneca {
    class Numbers {
        double* m_numbers{};
        char* m_filename{};
        bool m_isOriginal{};
        int m_numCount{};
        bool isEmpty() const;
        void setEmpty();
        void setFilename(const char* filename);
        void sort();
        int numberCount() const;
        bool load();
        void save() const;

    public:
        Numbers();
        Numbers(const char* filename);
        Numbers(const Numbers& other);
        Numbers& operator=(const Numbers& other);
        ~Numbers();
        double average() const;
        double max() const;
        double min() const;
        Numbers& operator+=(double value);
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };

    std::ostream& operator<<(std::ostream& os, const Numbers& N);
    std::istream& operator>>(std::istream& is, Numbers& N);
}

#endif // !SENECA_NUMBERS_H_
