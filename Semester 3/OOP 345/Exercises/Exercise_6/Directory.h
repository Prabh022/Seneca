#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H

#include <vector>
#include <string>
#include <iostream>
#include "Resource.h"
#include "Flags.h"

namespace seneca {

    class Directory : public Resource {
        std::string m_name{};
        std::vector<Resource*> m_contents;

    public:
        Directory(const std::string& name);

        void update_parent_path(const std::string& path) override;
        NodeType type() const override;
        std::string path() const override;
        std::string name() const override;
        int count() const override;
        size_t size() const override;

        Directory& operator+=(Resource* res);
        Resource* find(const std::string& name, const std::vector<OpFlags>& flags = {});
        void remove(const std::string& name, const std::vector<OpFlags>& flags = {});
        void display(std::ostream& out, const std::vector<FormatFlags>& flags = {}) const;

        ~Directory() override;

        // Rule of Five - no copy/move
        Directory(const Directory&) = delete;
        Directory& operator=(const Directory&) = delete;
        Directory(Directory&&) = delete;
        Directory& operator=(Directory&&) = delete;
    };

}

#endif // SENECA_DIRECTORY_H
