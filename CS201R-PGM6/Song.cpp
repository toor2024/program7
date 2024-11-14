#include "Song.h"
#include <sstream>

Song* Song::createFromLine(const std::string& line) {
    std::stringstream ss(line);
    std::string title, keyName, genre;
    int rating, length, year;
    bool top40;

    // Parse the fields from the line
    getline(ss, title, ',');
    getline(ss, keyName, ',');
    ss >> rating;
    ss.ignore();  // Skip comma
    getline(ss, genre, ',');
    ss >> length;
    ss.ignore(); // Skip comma
    ss >> year;
    ss.ignore(); // Skip comma
    ss >> top40;

    return new Song('S', title, keyName, rating, genre, length, year, top40);
}

void Song::print(std::ostream& out) const {
    out << "Song: " << title << " by " << keyName << " - Top 40: " << (top40 ? "Yes" : "No") << "\n";
}
