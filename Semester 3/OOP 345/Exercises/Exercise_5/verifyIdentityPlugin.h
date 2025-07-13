#ifndef SENECA_VERIFYIDENTITYPLUGIN_H
#define SENECA_VERIFYIDENTITYPLUGIN_H

#include <string>
#include "plugin.h"
#include "message.h"

namespace seneca {

    class VerifyIdentityPlugin : public Plugin {
        std::string m_known[100];    // known email addresses
        size_t m_knownCount = 0;     // number of known addresses
        size_t m_unknownCount = 0;   // number of unknown senders

    public:
        VerifyIdentityPlugin(const char* filename);   // load known senders from file
        void operator()(Message& msg) override;       // tag unknown sender
        void showStats() const override;              // show unknown sender count
    };

}

#endif
