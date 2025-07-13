#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "mailServer.h"

namespace seneca {

    MailServer::MailServer(const char* name, const char* address)
        : m_userName(name), m_userAddress(address), m_inbox(nullptr),
        m_cnt(0), m_capacity(0), onNewMailArrived(nullptr) {
    }

    MailServer::~MailServer() {
        delete[] m_inbox;
    }

    MailServer::MailServer(const MailServer& other)
        : m_userName(other.m_userName), m_userAddress(other.m_userAddress),
        m_cnt(other.m_cnt), m_capacity(other.m_capacity),
        onNewMailArrived(other.onNewMailArrived) {
        m_inbox = new Message[m_capacity];
        for (size_t i = 0; i < m_cnt; ++i)
            m_inbox[i] = other.m_inbox[i];
        for (size_t i = 0; i < 2; ++i)
            m_plugins[i] = other.m_plugins[i];
    }

    MailServer& MailServer::operator=(const MailServer& other) {
        if (this != &other) {
            delete[] m_inbox;

            m_userName = other.m_userName;
            m_userAddress = other.m_userAddress;
            m_cnt = other.m_cnt;
            m_capacity = other.m_capacity;
            onNewMailArrived = other.onNewMailArrived;

            m_inbox = new Message[m_capacity];
            for (size_t i = 0; i < m_cnt; ++i)
                m_inbox[i] = other.m_inbox[i];
            for (size_t i = 0; i < 2; ++i)
                m_plugins[i] = other.m_plugins[i];
        }
        return *this;
    }

    MailServer::MailServer(MailServer&& other) noexcept {
        *this = std::move(other);
    }

    MailServer& MailServer::operator=(MailServer&& other) noexcept {
        if (this != &other) {
            delete[] m_inbox;

            m_userName = std::move(other.m_userName);
            m_userAddress = std::move(other.m_userAddress);
            m_inbox = other.m_inbox;
            m_cnt = other.m_cnt;
            m_capacity = other.m_capacity;
            onNewMailArrived = other.onNewMailArrived;

            for (size_t i = 0; i < 2; ++i)
                m_plugins[i] = other.m_plugins[i];

            other.m_inbox = nullptr;
            other.m_cnt = 0;
            other.m_capacity = 0;
            other.onNewMailArrived = nullptr;
        }
        return *this;
    }

    void MailServer::resizeInbox() {
        size_t newCap = (m_capacity == 0) ? 2 : m_capacity * 2;
        Message* temp = new Message[newCap];
        for (size_t i = 0; i < m_cnt; ++i)
            temp[i] = m_inbox[i];
        delete[] m_inbox;
        m_inbox = temp;
        m_capacity = newCap;
    }

    void MailServer::receiveMail(Message msg) {
        if (msg.m_toAddress != m_userAddress)
            throw std::runtime_error("Email not addressed to this user");

        if (m_cnt >= m_capacity)
            resizeInbox();

        m_inbox[m_cnt++] = msg;

        for (size_t i = 0; i < 2; ++i)
            if (m_plugins[i])
                (*m_plugins[i])(m_inbox[m_cnt - 1]);

        if (onNewMailArrived)
            onNewMailArrived(m_inbox[m_cnt - 1]);
    }

    void MailServer::addPlugin(Plugin* thePlugin) {
        for (size_t i = 0; i < 2; ++i) {
            if (!m_plugins[i]) {
                m_plugins[i] = thePlugin;
                break;
            }
        }
    }

    void MailServer::setObserver(Observer_pfn observer) {
        onNewMailArrived = observer;
    }

    Message& MailServer::operator[](size_t idx) {
        if (idx >= m_cnt)
            throw std::out_of_range("Index " + std::to_string(idx) + " is out of bounds");
        return m_inbox[idx];
    }

    size_t MailServer::getInboxSize() const {
        return m_cnt;
    }

    void MailServer::showInbox() const {
        for (size_t i = 0; i < m_cnt; ++i) {
            std::cout << std::right << std::setw(20) << m_inbox[i].m_fromName << "  "
                << std::left << std::setw(40) << m_inbox[i].m_fromAddress << "  "
                << std::setw(15) << m_inbox[i].m_date.substr(0, 10) << "  "
                << m_inbox[i].m_subject << std::endl;
        }
    }

}
