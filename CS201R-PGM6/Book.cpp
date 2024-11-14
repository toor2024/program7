#include "Book.h"
#include <sstream>

Book* Book::createFromLine(const std::string& line) {
    std::stringstream ss(line);
    std::string title, keyName, genre;
    int rating, length, year, weeksNYT;

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
    ss >> weeksNYT;

    return new Book(title, keyName, rating, genre, length, year, weeksNYT);
}

void Book::print(std::ostream& out) const {
    out << "Book: " << title << " by " << keyName << " (" << yearReleased << ") - Rating: " << rating << "/10\n";
    out << "Weeks on NYT: " << weeksNYT << "\n";
}
