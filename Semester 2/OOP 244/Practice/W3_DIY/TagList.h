#ifndef TAGLIST_H
#define TAGLIST_H

#include "NameTag.h"

namespace seneca {

    class TagList {
        NameTag* m_tags;  // dynamic array
        int m_size;       // number of allocated tags
        int m_added;      // how many have been added so far

    public:
        TagList();
        void set();                 // reset
        void set(int size);          // allocate size
        void add(const NameTag& nt); // add a tag
        void print() const;          // print all
        void cleanup();              // cleanup memory
    };

}

#endif
