#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Media {
protected:
    char type;          // Movie, Book, or Song
    string title;
    string keyName;
    int rating;
    string genre;
    int length;
    int yearReleased;

public:
    // Constructor
    Media(char t, string tit, string kn, int r, string g, int l, int y) 
        : type(t), title(tit), keyName(kn), rating(r), genre(g), length(l), yearReleased(y) {}

    // Pure virtual function to make Media an abstract class
    virtual void print(ostream& os) const = 0;

    // Getters and setters
    char getType() const { return type; }
    string getTitle() const { return title; }
    string getKeyName() const { return keyName; }
    int getRating() const { return rating; }
    string getGenre() const { return genre; }
    int getLength() const { return length; }
    int getYearReleased() const { return yearReleased; }

    // Setters
    void setRating(int r) { rating = r; }
    void setYearReleased(int year) { yearReleased = year; }
};

#endif // MEDIA_H
