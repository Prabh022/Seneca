#include "Filesystem.h"
#include "File.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace seneca {

    // Utility function to trim string (left & right)
    std::string trim(const std::string& str) {
        size_t start = str.find_first_not_of(" \t\r\n");
        size_t end = str.find_last_not_of(" \t\r\n");
        return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
    }

    Filesystem::Filesystem(const std::string& file_path, const std::string& root_name) {
        std::string root_dir = root_name.empty() ? "/" : root_name;
        if (root_dir.back() != '/')
            root_dir += '/';

        m_root = new Directory(root_dir);
        m_root->update_parent_path("");
        m_current = m_root;

        parse_and_load(file_path);
    }

    Filesystem::~Filesystem() {
        delete m_root;
    }

    Filesystem& Filesystem::operator+=(Resource* res) {
        *m_current += res;
        return *this;
    }

    Directory* Filesystem::change_directory(const std::string& name) {
        if (name.empty()) {
            m_current = m_root;
            return m_current;
        }

        Resource* found = m_current->find(name);
        if (!found || found->type() != NodeType::DIR) {
            throw std::invalid_argument("Cannot change directory! " + name + " not found!");
        }

        m_current = dynamic_cast<Directory*>(found);
        return m_current;
    }

    Directory* Filesystem::get_current_directory() const {
        return m_current;
    }

    void Filesystem::parse_and_load(const std::string& file_path) {
        std::ifstream file(file_path);
        if (!file) throw std::runtime_error("Could not open file: " + file_path);

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;

            std::string path, contents;
            std::stringstream ss(line);
            std::getline(ss, path, '|');
            std::getline(ss, contents);

            path = trim(path);
            contents = trim(contents);

            bool is_file = path.back() != '/';
            std::stringstream path_parts(path);
            std::string segment;
            Directory* current = m_root;

            std::vector<std::string> parts;
            while (std::getline(path_parts, segment, '/')) {
                if (!segment.empty())
                    parts.push_back(segment + "/");
            }

            // If it's a file, remove last part and handle separately
            std::string file_name;
            if (is_file && !parts.empty()) {
                file_name = parts.back();
                parts.pop_back();
            }

            // Navigate and build directories
            for (const auto& part : parts) {
                Resource* found = current->find(part);
                if (!found) {
                    Directory* new_dir = new Directory(part);
                    *current += new_dir;
                    current = new_dir;
                }
                else {
                    current = dynamic_cast<Directory*>(found);
                }
            }

            // Add file or directory
            if (is_file) {
                File* f = new File(file_name.substr(0, file_name.size() - 1), contents);
                *current += f;
            }
            else {
                std::string last_dir = parts.empty() ? path : path.substr(path.find_last_of('/', path.size() - 2) + 1);
                if (!current->find(last_dir)) {
                    Directory* d = new Directory(last_dir);
                    *current += d;
                }
            }
        }
    }

    // Move constructor
    Filesystem::Filesystem(Filesystem&& other) noexcept {
        m_root = other.m_root;
        m_current = other.m_current;
        other.m_root = nullptr;
        other.m_current = nullptr;
    }

    // Move assignment
    Filesystem& Filesystem::operator=(Filesystem&& other) noexcept {
        if (this != &other) {
            delete m_root;
            m_root = other.m_root;
            m_current = other.m_current;
            other.m_root = nullptr;
            other.m_current = nullptr;
        }
        return *this;
    }

}
