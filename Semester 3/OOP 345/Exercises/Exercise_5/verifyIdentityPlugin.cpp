#include <fstream>
#include <iostream>
#include <stdexcept>
#include "verifyIdentityPlugin.h"

namespace seneca {

    VerifyIdentityPlugin::VerifyIdentityPlugin(const char* filename) {
        std::ifstream file(filename);
        if (!file)
            throw std::runtime_error("Cannot open file");

        std::string line;
        while (std::getline(file, line) && m_knownCount < 100) {
            m_known[m_knownCount++] = line;
        }
    }

    void VerifyIdentityPlugin::operator()(Message& msg) {
        bool known = false;

        for (size_t i = 0; i < m_knownCount; ++i) {
            if (msg.m_fromAddress == m_known[i]) {
                known = true;
                break;
            }
        }

        if (!known) {
            if (msg.m_subject.find("[UNKNOWN SENDER] ") != 0)
                msg.m_subject = "[UNKNOWN SENDER] " + msg.m_subject;
            ++m_unknownCount;
        }
    }

    void VerifyIdentityPlugin::showStats() const {
        std::cout << "[Verify Identity Plugin] Found " << m_unknownCount
            << " messages from unknown senders." << std::endl;
    }

}
