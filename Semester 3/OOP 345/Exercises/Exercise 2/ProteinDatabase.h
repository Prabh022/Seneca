#ifndef PROTEIN_DATABASE_H
#define PROTEIN_DATABASE_H

#include <string>
#include <fstream>
namespace seneca {
    class ProteinDatabase {
        std::string* ids = nullptr;        // dynamic array of IDs
        std::string* sequences = nullptr;  // dynamic array of sequences
        size_t numProteins = 0;            // number of proteins

    public:
        ProteinDatabase();
        ProteinDatabase(const std::string& filename);

        // Rule of 5
        ~ProteinDatabase();
        ProteinDatabase(const ProteinDatabase& other);
        ProteinDatabase& operator=(const ProteinDatabase& other);
        ProteinDatabase(ProteinDatabase&& other) noexcept;
        ProteinDatabase& operator=(ProteinDatabase&& other) noexcept;

        size_t size() const;
        std::string operator[](size_t index) const;
        std::string getUID(size_t index) const;
    };

}
#endif