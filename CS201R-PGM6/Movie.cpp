#include "Movie.h"
#include <sstream>

Movie::Movie(char type, std::string title, std::string keyName, int rating, std::string genre, int length, int yearReleased, std::vector<std::string> stars)
    : Media(type, title, keyName, rating, genre, length, yearReleased), stars(stars) {}

std::vector<std::string> Movie::getStars() const {
    return stars;
}

void Movie::setStars(const std::vector<std::string>& newStars) {
    stars = newStars;
}

void Movie::print(std::ostream& out) const {
    out << "Movie: " << title << " by " << keyName << " (" << yearReleased << ") - Rating: " << rating << "/10\n";
}
