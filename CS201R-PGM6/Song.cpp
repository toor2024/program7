#include "Song.h"

Song::Song(char type, std::string title, std::string keyName, int rating, std::string genre, int length, int yearReleased, bool top40)
    : Media(type, title, keyName, rating, genre, length, yearReleased), top40(top40) {}

bool Song::getTop40() const {
    return top40;
}

void Song::setTop40(bool top) {
    top40 = top;
}

void Song::print(std::ostream& out) const {
    out << "Song: " << title << " by " << keyName << " - Top 40: " << (top40 ? "Yes" : "No") << "\n";
}
