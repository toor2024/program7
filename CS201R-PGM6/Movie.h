#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"
#include <string>
#include <vector>
#include <iostream>

class Movie : public Media {
private:
    std::vector<std::string> stars;

public:
    // Constructor
    Movie(char type, std::string title, std::string keyName, int rating, std::string genre, int length, int yearReleased, std::vector<std::string> stars)
        : Media(type, title, keyName, rating, genre, length, yearReleased), stars(stars) {}

    // Getter and setter for stars
    std::vector<std::string> getStars() const;
    void setStars(const std::vector<std::string>& newStars);

    // Print function
    void print(std::ostream& out) const override;

    // Static function to create Movie from line
    static Movie* createFromLine(const std::string& line);
};

#endif // MOVIE_H
