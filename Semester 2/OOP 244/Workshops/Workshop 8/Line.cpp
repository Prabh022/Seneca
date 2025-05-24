#define _CRT_SECURE_NO_WARNINGS
#include "Line.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace seneca {

    // Default constructor
    Line::Line() : LblShape(), m_length(0) {}

    // Two-argument constructor
    Line::Line(const char* label, int length) : LblShape(label) {
        int labelLen = label ? strlen(label) : 0;
        m_length = (length < labelLen) ? labelLen : length;
    }

    // Override getSpecs
    void Line::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);  // Read label part first
        is >> m_length;          // Then read the length
        is.ignore(1000, '\n');   // Skip to the end of the line
    }

    // Override draw
    void Line::draw(std::ostream& os) const {
        if (m_length > 0 && label() != nullptr) {
            os << label() << endl;
            for (int i = 0; i < m_length; ++i) {
                os << '=';
            }
            os << endl;
        }
    }

}
