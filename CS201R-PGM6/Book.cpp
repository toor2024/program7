#include "Book.h"

Book::Book(char type, std::string title, std::string keyName, int rating, std::string genre, int length, int yearReleased, int weeksNYT)
    : Media(type, title, keyName, rating, genre, length, yearReleased), weeksNYT(weeksNYT) {}

int Book::getWeeks() const {
    return weeksNYT;
}

void Book::setWeeks(int weeks) {
    weeksNYT = weeks;
}

void Book::print(std::ostream& out) const {
    out << "Book: " << title << " by " << keyName << " - Weeks on NYT: " << weeksNYT << "\n";
}
