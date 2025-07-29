#include <iostream>
#include "SongCollection.h"

int main() {
    try {
        sdds::SongCollection theCollection("songs.txt");

        std::cout << "=== Original List ===" << std::endl;
        theCollection.display(std::cout);

        std::cout << "\n=== Sorted by Title ===" << std::endl;
        theCollection.sort("title");
        theCollection.display(std::cout);

        std::cout << "\n=== Sorted by Album ===" << std::endl;
        theCollection.sort("album");
        theCollection.display(std::cout);

        std::cout << "\n=== Clean Album Field ===" << std::endl;
        theCollection.cleanAlbum();
        theCollection.display(std::cout);

        std::string artist = "The Beatles";
        std::cout << "\n=== In Collection: " << artist << " ===" << std::endl;
        std::cout << (theCollection.inCollection(artist) ? "Yes" : "No") << std::endl;

        std::cout << "\n=== Songs by " << artist << " ===" << std::endl;
        auto songs = theCollection.getSongsForArtist(artist);
        for (const auto& song : songs) {
            std::cout << song << '\n';
        }

    }
    catch (const std::exception& e) {
        std::cerr << "** Error: " << e.what() << std::endl;
    }

    return 0;
}