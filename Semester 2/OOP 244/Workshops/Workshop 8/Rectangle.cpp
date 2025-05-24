#include "Rectangle.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace seneca {

    // Default constructor
    Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}

    // Three-argument constructor
    Rectangle::Rectangle(const char* label, int width, int height)
        : LblShape(label) {
        int minWidth = label ? (strlen(label) + 2) : 2;

        m_width = (width < minWidth) ? minWidth : width;
        m_height = (height < 3) ? 3 : height;
    }

    // getSpecs override
    void Rectangle::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);  // get label
        char comma;
        is >> m_width >> comma >> m_height;
        is.ignore(1000, '\n');

        // Validations
        int minWidth = label() ? (strlen(label()) + 2) : 2;
        if (m_height < 3) m_height = 3;
        if (m_width < minWidth) m_width = minWidth;
    }

    // draw override
    void Rectangle::draw(std::ostream& os) const {
        if (m_width > 0 && m_height > 0 && label() != nullptr) {
            // Top border
            os << '+' << std::setw(m_width - 2) << std::setfill('-') << '-' << '+' << endl;

            // Label line
            os << '|' << std::left << std::setw(m_width - 2)
                << std::setfill(' ') << label() << '|' << endl;

            // Empty lines
            for (int i = 0; i < m_height - 3; ++i) {
                os << '|' << std::setw(m_width - 2)
                    << ' ' << '|' << endl;
            }

            // Bottom border
            os << '+' << std::setw(m_width - 2) << std::setfill('-') << '-' << '+' << endl;

            // Reset format flags just in case
            os << std::right << std::setfill(' ');
        }
    }

}
