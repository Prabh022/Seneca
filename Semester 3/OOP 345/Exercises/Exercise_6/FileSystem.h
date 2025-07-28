#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H

#include <string>
#include "Directory.h"

namespace seneca {

    class Filesystem {
        Directory* m_root{};
        Directory* m_current{};

        void parse_and_load(const std::string& file_path);

    public:
        Filesystem(const std::string& file_path, const std::string& root_name = "");
        ~Filesystem();

        Filesystem(const Filesystem&) = delete;
        Filesystem& operator=(const Filesystem&) = delete;

        Filesystem(Filesystem&&) noexcept;
        Filesystem& operator=(Filesystem&&) noexcept;

        Filesystem& operator+=(Resource* res);
        Directory* change_directory(const std::string& name = "");
        Directory* get_current_directory() const;
    };

}

#endif // SENECA_FILESYSTEM_H
