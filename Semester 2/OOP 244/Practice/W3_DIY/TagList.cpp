#include <iostream>
#include <cstring>
#include "TagList.h"
using namespace std;

namespace seneca {

    TagList::TagList() {
        m_tags = nullptr;
        m_size = 0;
        m_added = 0;
    }

    void TagList::set() {
        delete[] m_tags;
        m_tags = nullptr;
        m_size = 0;
        m_added = 0;
    }

    void TagList::set(int size) {
        delete[] m_tags;  // clean previous
        m_size = size;
        m_tags = new NameTag[m_size];
        m_added = 0;
    }

    void TagList::add(const NameTag& nt) {
        if (m_added < m_size) {
            m_tags[m_added] = nt;
            m_added++;
        }
    }

    void TagList::print() const {
        // Find the maximum name length
        int maxLen = 0;
        for (int i = 0; i < m_added; i++) {
            size_t len = strlen(m_tags[i].name());
            if (len > maxLen) {
                maxLen = len;
            }
        }
        // Print all tags with the same frame width
        for (int i = 0; i < m_added; i++) {
            m_tags[i].print(maxLen);
        }
    }

    void TagList::cleanup() {
        delete[] m_tags;
        m_tags = nullptr;
        m_size = 0;
        m_added = 0;
    }

}
