#include <iostream>
#include <iomanip>
#include <fstream>
#include "message.h"
#include "mailServer.h"
#include "plugin.h"
#include "verifyIdentityPlugin.h"
#include "spamFilterPlugin.h"

#ifndef SENECA_MESSAGE_H
#error "The header guard for 'message.h' doesn't follow the convention!"
#endif
#ifndef SENECA_MAILSERVER_H
#error "The header guard for 'mailServer.h' doesn't follow the convention!"
#endif
#ifndef SENECA_PLUGIN_H
#error "The header guard for 'plugin.h' doesn't follow the convention!"
#endif
#ifndef SENECA_VERIFYIDENTITYPLUGIN_H
#error "The header guard for 'verifyIdentityPlugin.h' doesn't follow the convention!"
#endif
#ifndef SENECA_SPAMFILTERPLUGIN_H
#error "The header guard for 'spamFilterPlugin.h' doesn't follow the convention!"
#endif

int cout = 0; // prevents compilation if headers don't follow convention

void youGotMail(const seneca::Message& msg)
{
    static size_t cnt = 0;
    std::cout << ++cnt << ". New mail from " << msg.m_fromName << ".\n";
}

int main(int argc, char** argv)
{
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    seneca::Message messages[20]{};

    {
        std::ifstream file(argv[1]);
        if (!file.is_open())
        {
            std::cout << "Incorrect parameters; check your command line.\n";
            return 1;
        }
        for (auto i = 0; i < 20 && file; ++i)
        {
            std::getline(file, messages[i].m_fromAddress, ',');
            std::getline(file, messages[i].m_fromName, ',');
            std::getline(file, messages[i].m_subject, ',');
            std::getline(file, messages[i].m_date);
        }

        // change two destination addresses for exception test
        messages[5].m_toAddress = "jane.doe@senemail.ca";
        messages[16].m_toAddress = "anna.garcia@senemail.ca";
    }

    seneca::MailServer server("John Smith", "john.smith@senemail.ca");

    {
        std::cout << ">>>  T1: Testing wrong destination address and fix\n";
        std::cout << "==========:==========:==========:==========:==========\n";

        try {
            server.receiveMail(messages[0]);
        }
        catch (const std::exception& e) {
            std::cout << "EXCEPTION: Message intended for " << messages[0].m_toAddress << std::endl;
        }

        // Lambda: fixes blank destination address
        auto fixDestAddress = [](seneca::Message& m) {
            if (m.m_toAddress.empty()) {
                m.m_toAddress = "john.smith@senemail.ca";
            }
            };

        for (auto& msg : messages) {
            fixDestAddress(msg);
        }

        try {
            server.receiveMail(messages[0]);
        }
        catch (const std::exception& e) {
            std::cout << "EXCEPTION: Message intended for " << messages[0].m_toAddress << std::endl;
        }

        server.showInbox();
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    {
        std::cout << ">>>  T2: Adding some messages to the inbox\n";
        std::cout << "==========:==========:==========:==========:==========\n";
        for (int i = 1; i < 10; ++i)
        {
            try {
                server.receiveMail(messages[i]);
            }
            catch (const std::exception& e) {
                std::cout << "EXCEPTION: Message intended for " << messages[i].m_toAddress << std::endl;
            }
        }
        server.showInbox();
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    // deploy plugins
    seneca::VerifyIdentityPlugin plugin_id(argv[2]);
    seneca::SpamFilterPlugin plugin_spam(argv[3]);
    server.addPlugin(&plugin_spam);
    server.addPlugin(&plugin_id);
    server.setObserver(youGotMail);

    {
        std::cout << ">>>  T3: Check the plugins.\n";
        std::cout << "==========:==========:==========:==========:==========\n";
        plugin_spam.showStats();
        plugin_id.showStats();
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    {
        std::cout << ">>>  T4: Adding the rest of the messages to the inbox.\n";
        std::cout << "==========:==========:==========:==========:==========\n";

        for (int i = 10; i < 20; ++i)
        {
            try {
                server.receiveMail(messages[i]);
            }
            catch (const std::exception& e) {
                std::cout << "EXCEPTION: Message intended for " << messages[i].m_toAddress << std::endl;
            }
        }

        server.showInbox();
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    {
        std::cout << ">>>  T5: Check the plugins again.\n";
        std::cout << "==========:==========:==========:==========:==========\n";
        plugin_spam.showStats();
        plugin_id.showStats();
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    {
        std::cout << ">>>  T6: Check the index-out-of-bounds exception.\n";
        std::cout << "==========:==========:==========:==========:==========\n";
        for (auto i = 0u; i < server.getInboxSize() + 3; ++i)
        {
            try
            {
                auto& msg = server[i];
                std::cout << std::setw(2) << i << ". " << msg.m_subject << "\n";
            }
            catch (std::out_of_range& error)
            {
                std::cout << "EXCEPTION: " << error.what() << std::endl;
            }
        }
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    {
        std::cout << ">>>  T7: Check Copy Constructor.\n";
        std::cout << "==========:==========:==========:==========:==========\n";
        seneca::MailServer copy(server);
        copy.receiveMail(messages[3]);
        server[1].m_subject += "{Read}";
        copy.showInbox();
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    {
        std::cout << ">>>  T8: Check the plugins again.\n";
        std::cout << "==========:==========:==========:==========:==========\n";
        plugin_spam.showStats();
        plugin_id.showStats();
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    {
        std::cout << ">>>  T9: Check Copy Assignment.\n";
        std::cout << "==========:==========:==========:==========:==========\n";
        seneca::MailServer copy("Nobody", "nobody@nowhere.com");
        copy = server;
        copy.receiveMail(messages[3]);
        server[2].m_subject += "{Read}";
        copy.showInbox();
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    {
        std::cout << ">>>  T10: Check the plugins again.\n";
        std::cout << "==========:==========:==========:==========:==========\n";
        plugin_spam.showStats();
        plugin_id.showStats();
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    {
        std::cout << ">>>  T11: Check Move Assignment.\n";
        std::cout << "==========:==========:==========:==========:==========\n";
        seneca::MailServer copy("Nobody", "nobody@nowhere.com");
        copy = std::move(server);
        copy.receiveMail(messages[3]);
        copy.showInbox();
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    {
        std::cout << ">>>  T12: Check the plugins again.\n";
        std::cout << "==========:==========:==========:==========:==========\n";
        plugin_spam.showStats();
        plugin_id.showStats();
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    return cout;
}
