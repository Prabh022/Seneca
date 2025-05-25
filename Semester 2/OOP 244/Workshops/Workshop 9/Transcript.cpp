#define _CRT_SECURE_NO_WARNINGS
#include "Transcript.h"
#include "utils.h"

namespace seneca {
    seneca::Transcript::Transcript(const char* name, size_t number)
    {
        if (name) {
            m_name = new char[strlen(name) + 1]; // +1 for null terminator
            strcpy(m_name, name);                // copy the name into our member
        }
        else {
            m_name = nullptr;
        }
        m_number = number;                // assign student number
    }

    Transcript::~Transcript()
    {
        delete[] m_name;
    }

    Transcript::Transcript(const Transcript& other) {
        if (other.m_name) {
            m_name = new char[strlen(other.m_name) + 1];
            strcpy(m_name, other.m_name);
        }
        else {
            m_name = nullptr;
        }
        m_number = other.m_number;
    }
    Transcript& Transcript::operator=(const Transcript& other) {
        if (this != &other) { // Avoid self-assignment
            delete[] m_name; // Clean up old memory

            if (other.m_name) {
                m_name = new char[strlen(other.m_name) + 1];
                strcpy(m_name, other.m_name);
            }
            else {
                m_name = nullptr;
            }

            m_number = other.m_number;
        }
        return *this;
    }


}


