#ifndef NAMETAG_H
#define NAMETAG_H

namespace seneca {

    class NameTag {
        char m_name[51];  // 50 characters + 1 for null terminator

    public:
        NameTag();
        void set(const char* name);  // set name
        const char* name() const;    // get name (for internal use)
        void print(int width = 0) const;  // print with frame, with optional width
    };

}

#endif
