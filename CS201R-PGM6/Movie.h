#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"
#include <vector>
#include <string>

using namespace std;

class Movie : public Media {
private:
    vector<string> stars;

public:
    // Constructor
    Movie(string tit, string kn, int r, string g, int l, int y, vector<string> s)
        : Media('M', tit, kn, r, g, l, y), stars(s) {}

    // Getter and Setter for stars
    vector<string> getStars() const { return stars; }
    void setStars(const vector<string>& newStars) { stars = newStars; }

    // Implement the print function for Movie
    void print(ostream& os, vector<Media*>& mediaList) override {
        os << "Movie: " << title << "\n";
        os << "Genre: " << genre << "\n";
        os << "Rating: " << rating << "\n";
        os << "Stars: ";
        for (const auto& star : stars) {
            os << star << " ";
        }
        os << "\n";
    }
};

#endif // MOVIE_H
