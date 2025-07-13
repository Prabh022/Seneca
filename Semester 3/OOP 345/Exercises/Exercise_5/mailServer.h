#ifndef SENECA_MAILSERVER_H
#define SENECA_MAILSERVER_H

#include <string>
#include "message.h"
#include "plugin.h"

namespace seneca {

    class MailServer {
        std::string m_userName;
        std::string m_userAddress;
        Message* m_inbox{ nullptr };                // dynamic array of messages
        size_t m_cnt{ 0 };                          // number of received messages
        size_t m_capacity{ 0 };                     // current capacity of inbox array
        Plugin* m_plugins[2]{ nullptr, nullptr };   // max 2 plugins
        using Observer_pfn = void(*)(const Message&);
        Observer_pfn onNewMailArrived{ nullptr };   // observer function

        void resizeInbox();

    public:
        MailServer(const char* name, const char* address);
        ~MailServer();
        MailServer(const MailServer& other);
        MailServer& operator=(const MailServer& other);
        MailServer(MailServer&& other) noexcept;
        MailServer& operator=(MailServer&& other) noexcept;

        void receiveMail(Message msg);
        void addPlugin(Plugin* thePlugin);
        void setObserver(Observer_pfn observer);

        Message& operator[](size_t idx);
        size_t getInboxSize() const;
        void showInbox() const;
    };

}

#endif
