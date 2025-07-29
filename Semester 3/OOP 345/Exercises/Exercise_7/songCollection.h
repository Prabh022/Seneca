#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <string>
#include <vector>
#include <iostream>

namespace sdds {

    struct Song {
        std::string m_title{};
        std::string m_artist{};
        std::string m_album{};
        double m_price{};
        size_t m_year{};
        size_t m_time{};
    };

    class SongCollection {
        std::vector<Song> m_songs;

        std::string trim(const std::string& str);

    public:
        SongCollection(const std::string& filename);

        void display(std::ostream& out) const;
        void sort(const std::string& field);
        void cleanAlbum();
        bool inCollection(const std::string& artist) const;
        std::vector<Song> getSongsForArtist(const std::string& artist) const;
    };

    std::ostream& operator<<(std::ostream& out, const Song& theSong);

}

#endif // SDDS_SONGCOLLECTION_H