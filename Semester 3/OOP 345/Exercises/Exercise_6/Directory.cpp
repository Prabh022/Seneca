#include "Directory.h"
#include <iomanip>
#include <stdexcept>
#include <algorithm>

namespace seneca {

    Directory::Directory(const std::string& name)
        : m_name{ name } {
    }

    void Directory::update_parent_path(const std::string& path) {
        m_parent_path = path;
        for (auto res : m_contents) {
            res->update_parent_path(this->path());
        }
    }

    NodeType Directory::type() const {
        return NodeType::DIR;
    }

    std::string Directory::path() const {
        return m_parent_path + m_name;
    }

    std::string Directory::name() const {
        return m_name;
    }

    int Directory::count() const {
        return static_cast<int>(m_contents.size());
    }

    size_t Directory::size() const {
        size_t total = 0u;
        for (const auto& res : m_contents)
            total += res->size();
        return total;
    }

    Directory& Directory::operator+=(Resource* res) {
        for (const auto& r : m_contents) {
            if (r->name() == res->name())
                throw std::invalid_argument("Resource already exists: " + res->name());
        }

        res->update_parent_path(this->path());
        m_contents.push_back(res);
        return *this;
    }

    Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flags) {
        for (auto res : m_contents) {
            if (res->name() == name) {
                return res;
            }
        }

        // If RECURSIVE flag is present
        if (std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) != flags.end()) {
            for (auto res : m_contents) {
                if (res->type() == NodeType::DIR) {
                    Resource* found = dynamic_cast<Directory*>(res)->find(name, flags);
                    if (found) return found;
                }
            }
        }

        return nullptr;
    }

    void Directory::remove(const std::string& name, const std::vector<OpFlags>& flags) {
        auto it = std::find_if(m_contents.begin(), m_contents.end(), [&](Resource* res) {
            return res->name() == name;
            });

        if (it == m_contents.end())
            throw std::string(name + " does not exist in " + m_name);

        Resource* target = *it;
        if (target->type() == NodeType::DIR) {
            if (std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) == flags.end())
                throw std::invalid_argument(name + " is a directory. Pass the recursive flag to delete directories.");
        }

        delete target;
        m_contents.erase(it);
    }

    void Directory::display(std::ostream& out, const std::vector<FormatFlags>& flags) const {
        out << "Total size: " << size() << " bytes\n";

        bool long_format = std::find(flags.begin(), flags.end(), FormatFlags::LONG) != flags.end();

        for (auto res : m_contents) {
            char type_char = (res->type() == NodeType::DIR) ? 'D' : 'F';
            out << type_char << " | "
                << std::left << std::setw(15) << res->name() << " |";

            if (long_format) {
                if (res->type() == NodeType::DIR) {
                    out << std::right << std::setw(3) << res->count();
                }
                else {
                    out << std::setw(3) << " ";
                }
                out << " | " << std::right << std::setw(10) << res->size() << " bytes";
            }
            out << "\n";
        }
    }

    Directory::~Directory() {
        for (auto res : m_contents) {
            delete res;
        }
        m_contents.clear();
    }

}
