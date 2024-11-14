#pragma once
#include <string>
#include <vector>
#include <iostream>

class Media {
protected:
    char type;
    std::string title;
    std::string keyName;
    int rating;
    std::string genre;
    int length;
    int yearReleased;

public:
    Media();
    Media(char type, std::string title, std::string keyName, int rating, std::string genre, int length, int yearReleased);

    // Setters
    void setType(char c);
    void setRating(int r);
    void setYearReleased(int yr);

    // Getters
    char getType() const;
    std::string getTitle() const;
    std::string getKeyName() const;
    int getRating() const;
    std::string getGenre() const;
    int getLength() const;
    int getYearReleased() const;

    // Pure virtual function for printing (abstract class)
    virtual void print(std::ostream& out) const = 0;

    // Static function to create a Media object from a line
    static Media* createFromLine(const std::string& line, std::ostream& outErr);

    // Virtual destructor for proper cleanup
    virtual ~Media() = default;
};
