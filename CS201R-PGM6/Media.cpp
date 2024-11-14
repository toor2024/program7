#include <string>
#include <iostream>
#include <sstream>
#include "Media.h"
#include "Movie.h"
#include "Book.h"
#include "Song.h"
#include "Functions.h" // For trim and checkDigits

using namespace std;

// Parameterized constructor
Media::Media(char type, string title, string keyName, int rating, string genre, int length, int yearReleased)
    : type(type), title(title), keyName(keyName), rating(rating), genre(genre), length(length), yearReleased(yearReleased) {
    setRating(rating);
    setYearReleased(yearReleased);
}

// Setters
void Media::setRating(int r) {
    if (r >= 1 && r <= 10) {
        rating = r;
    }
}

void Media::setYearReleased(int yr) {
    if (yr >= 1920 && yr <= 2025) {
        yearReleased = yr;
    }
}

// Getters
char Media::getType() const {
    return type;
}

std::string Media::getTitle() const {
    return title;
}

std::string Media::getKeyName() const {
    return keyName;
}

int Media::getRating() const {
    return rating;
}

std::string Media::getGenre() const {
    return genre;
}

int Media::getLength() const {
    return length;
}

int Media::getYearReleased() const {
    return yearReleased;
}

// Function to print Media details (should be overridden in derived classes)
void Media::print(std::ostream& out) const {
    out << type << ", " << title << ", " << keyName << ", " << rating << ", " << genre << ", " << length << ", " << yearReleased << endl;
}
