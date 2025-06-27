#include "ProteinDatabase.h"
#include <sstream>

namespace seneca {
    ProteinDatabase::ProteinDatabase() {}

    ProteinDatabase::ProteinDatabase(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) return;

        std::string line;
        // First pass: count how many protein entries
        while (std::getline(file, line)) {
            if (!line.empty() && line[0] == '>') ++numProteins;
        }

        ids = new std::string[numProteins];
        sequences = new std::string[numProteins];

        file.clear();
        file.seekg(0);

        size_t current = 0;
        std::string sequence;
        while (std::getline(file, line)) {
            if (!line.empty() && line[0] == '>') {
                if (current > 0) sequences[current - 1] = sequence;
                std::istringstream iss(line);
                std::getline(iss, line, '|'); // skip ">db"
                std::getline(iss, ids[current], '|');
                sequence.clear();
                ++current;
            }
            else {
                sequence += line;
            }
        }
        if (current > 0) sequences[current - 1] = sequence;
    }

    ProteinDatabase::~ProteinDatabase() {
        delete[] ids;
        delete[] sequences;
    }

    ProteinDatabase::ProteinDatabase(const ProteinDatabase& other) {
        numProteins = other.numProteins;
        ids = new std::string[numProteins];
        sequences = new std::string[numProteins];
        for (size_t i = 0; i < numProteins; ++i) {
            ids[i] = other.ids[i];
            sequences[i] = other.sequences[i];
        }
    }

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& other) {
        if (this != &other) {
            delete[] ids;
            delete[] sequences;
            numProteins = other.numProteins;
            ids = new std::string[numProteins];
            sequences = new std::string[numProteins];
            for (size_t i = 0; i < numProteins; ++i) {
                ids[i] = other.ids[i];
                sequences[i] = other.sequences[i];
            }
        }
        return *this;
    }

    ProteinDatabase::ProteinDatabase(ProteinDatabase&& other) noexcept {
        ids = other.ids;
        sequences = other.sequences;
        numProteins = other.numProteins;
        other.ids = nullptr;
        other.sequences = nullptr;
        other.numProteins = 0;
    }

    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& other) noexcept {
        if (this != &other) {
            delete[] ids;
            delete[] sequences;
            ids = other.ids;
            sequences = other.sequences;
            numProteins = other.numProteins;
            other.ids = nullptr;
            other.sequences = nullptr;
            other.numProteins = 0;
        }
        return *this;
    }

    size_t ProteinDatabase::size() const {
        return numProteins;
    }

    std::string ProteinDatabase::operator[](size_t index) const {
        return (index < numProteins) ? sequences[index] : "";
    }

    std::string ProteinDatabase::getUID(size_t index) const {
        return (index < numProteins) ? ids[index] : "None";
    }
}