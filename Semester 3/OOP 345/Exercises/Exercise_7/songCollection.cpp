#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include "SongCollection.h"

namespace sdds {

    SongCollection::SongCollection(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) throw std::runtime_error("Cannot open file " + filename);

        std::string line;
        while (std::getline(file, line)) {
            try {
                std::string title = trim(line.substr(0, 25));
                std::string artist = trim(line.substr(25, 25));
                std::string album = trim(line.substr(50, 25));
                std::string priceStr = trim(line.substr(75, 5));
                std::string yearStr = trim(line.substr(80, 5));
                std::string lengthStr = trim(line.substr(85, 5));

                double price = priceStr.empty() ? 0.0 : std::stod(priceStr);
                size_t year = yearStr.empty() ? 0 : std::stoul(yearStr);
                size_t length = lengthStr.empty() ? 0 : std::stoul(lengthStr);

                m_songs.push_back({ title, artist, album, price, year, length });
            }
            catch (...) {
                std::cerr << "** Skipping bad line: [" << line << "]" << std::endl;
            }
        }
    }

    void SongCollection::display(std::ostream& out) const {
        std::for_each(m_songs.begin(), m_songs.end(), [&out](const Song& song) {
            out << song << '\n';
            });

        size_t totalSeconds = std::accumulate(m_songs.begin(), m_songs.end(), 0u,
            [](size_t sum, const Song& s) {
                return sum + s.m_time;
            });

        out << std::setw(89) << "Total Listening Time: "
            << totalSeconds / 60 << ":" << std::setfill('0') << std::setw(2) << totalSeconds % 60 << std::setfill(' ')
            << '\n';
    }

    void SongCollection::sort(const std::string& field) {
        if (field == "title") {
            std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
                return a.m_title < b.m_title;
                });
        }
        else if (field == "album") {
            std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
                return a.m_album < b.m_album;
                });
        }
        else if (field == "length") {
            std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
                return a.m_time < b.m_time;
                });
        }
    }

    void SongCollection::cleanAlbum() {
        std::for_each(m_songs.begin(), m_songs.end(), [](Song& s) {
            if (s.m_album == "[None]") s.m_album = "";
            });
    }

    bool SongCollection::inCollection(const std::string& artist) const {
        return std::any_of(m_songs.begin(), m_songs.end(), [&](const Song& s) {
            return s.m_artist == artist;
            });
    }

    std::vector<Song> SongCollection::getSongsForArtist(const std::string& artist) const {
        std::vector<Song> songs;
        std::copy_if(m_songs.begin(), m_songs.end(), std::back_inserter(songs), [&](const Song& s) {
            return s.m_artist == artist;
            });
        return songs;
    }

    std::ostream& operator<<(std::ostream& out, const Song& song) {
        out << std::left << std::setw(25) << song.m_title << " | "
            << std::setw(25) << song.m_artist << " | "
            << std::setw(25) << song.m_album << " | "
            << std::setw(5) << song.m_year << " | "
            << std::right << std::setw(3) << song.m_time / 60 << ":"
            << std::setfill('0') << std::setw(2) << song.m_time % 60 << std::setfill(' ') << " | "
            << std::fixed << std::setprecision(2) << song.m_price;
        return out;
    }

    std::string SongCollection::trim(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
    }

}