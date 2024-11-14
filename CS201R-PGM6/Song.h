#ifndef SONG_H
#define SONG_H

#include "Media.h"
#include <string>
#include <iostream>

class Song : public Media {
private:
    bool top40;

public:
    // Constructor
    Song(char type, std::string title, std::string keyName, int rating, std::string genre, int length, int yearReleased, bool top40)
        : Media(type, title, keyName, rating, genre, length, yearReleased), top40(top40) {}

    // Getter and setter for top40
    bool getTop40() const { return top40; }
    void setTop40(bool top) { top40 = top; }

    // Print function
    void print(std::ostream& out) const override {
        out << "Song: " << title << " by " << keyName << " - Top 40: " << (top40 ? "Yes" : "No") << "\n";
    }

    // Static function to create Song from line
    static Song* createFromLine(const std::string& line);
};

#endif // SONG_H
