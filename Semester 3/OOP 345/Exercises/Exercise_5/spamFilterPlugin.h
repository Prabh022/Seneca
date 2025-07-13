#ifndef SENECA_SPAMFILTERPLUGIN_H
#define SENECA_SPAMFILTERPLUGIN_H

#include <string>
#include "plugin.h"   // base class
#include "message.h"  // Message class

namespace seneca {

    class SpamFilterPlugin : public Plugin {
        std::string m_keywords[100];  // static array of spam-identifying keywords
        size_t m_count = 0;           // number of keywords loaded
        size_t m_spamDetected = 0;    // number of spam messages identified

    public:
        SpamFilterPlugin(const char* filename);       // constructor
        void operator()(Message& msg) override;       // spam filter logic
        void showStats() const override;              // print stats
    };

}

#endif
