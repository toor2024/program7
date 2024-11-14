#ifndef BOOK_H
#define BOOK_H

#include "Media.h"
#include <string>
#include <iostream>

class Book : public Media {
private:
    int weeksNYT;  // Store the number of weeks the book has been on the NYT list

public:
    // Constructor
    Book(std::string tit, std::string kn, int r, std::string g, int l, int y, int w)
        : Media('B', tit, kn, r, g, l, y), weeksNYT(w) {}

    // Getter and setter for weeksNYT
    int getWeeksNYT() const { return weeksNYT; }
    void setWeeksNYT(int weeks) { weeksNYT = weeks; }

    // Print function
    void print(std::ostream& os) const override {
        os << "Book: " << title << " by " << keyName << " (" << yearReleased << ")\n";
        os << "Genre: " << genre << "\n";  // Print the genre of the book
        os << "Rating: " << rating << "/10\n";  // Print the rating
        os << "Weeks on NYT: " << weeksNYT << "\n"; // Print how many weeks the book has been on NYT
    }

    // Static function to create Book from line
    static Book* createFromLine(const std::string& line);
};

#endif // BOOK_H
