#include <fstream>
#include<iostream>
#include <stdexcept>
#include "spamFilterPlugin.h"

namespace seneca {

    // Constructor: Load keywords from file
    SpamFilterPlugin::SpamFilterPlugin(const char* filename) {
        std::ifstream file(filename);
        if (!file)
            throw std::runtime_error("Cannot open file");

        std::string line;
        while (std::getline(file, line) && m_count < 100) {
            m_keywords[m_count++] = line;
        }
    }

    // Overloaded function call: Check message for spam
    void SpamFilterPlugin::operator()(Message& msg) {
        std::string& subject = msg.m_subject;

        for (size_t i = 0; i < m_count; ++i) {
            if (subject.find(m_keywords[i]) != std::string::npos) {
                if (subject.find("[SPAM] ") != 0)
                    subject = "[SPAM] " + subject;
                ++m_spamDetected;
                break;
            }
        }
    }

    // Show stats
    void SpamFilterPlugin::showStats() const {
        std::cout << "[Spam Filter Plugin] Identified " << m_spamDetected << " spam messages." << std::endl;
    }

}
