#ifndef SENECA_FILE_H
#define SENECA_FILE_H

#include <string>
#include "Resource.h"
#include "Flags.h"

namespace seneca {

    class File : public Resource {
        std::string m_contents{};

    public:
        File(const std::string& name, const std::string& contents = "");

        void update_parent_path(const std::string& path) override;
        NodeType type() const override;
        std::string path() const override;
        std::string name() const override;
        int count() const override;
        size_t size() const override;

        // Rule of Five
        ~File() override = default;
        File(const File&) = delete;
        File& operator=(const File&) = delete;
        File(File&&) = delete;
        File& operator=(File&&) = delete;
    };

}

#endif // SENECA_FILE_H
