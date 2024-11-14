#include "Movie.h"
#include <sstream>

Movie* Movie::createFromLine(const std::string& line) {
    std::stringstream ss(line);
    std::string title, keyName, genre;
    int rating, length, year;
    std::vector<std::string> stars;

    // Parse the fields from the line
    getline(ss, title, ',');
    getline(ss, keyName, ',');
    ss >> rating;
    ss.ignore();  // Skip comma
    getline(ss, genre, ',');
    ss >> length;
    ss.ignore(); // Skip comma
    ss >> year;

    // Create and return Movie object
    stars.push_back("Actor1");  // Example stars
    stars.push_back("Actor2");
    return new Movie('M', title, keyName, rating, genre, length, year, stars);
}

void Movie::print(std::ostream& out) const {
    out << "Movie: " << title << " by " << keyName << " (" << yearReleased << ") - Rating: " << rating << "/10\n";
    for (const auto& star : stars) {
        out << "Starring: " << star << "\n";
    }
}
