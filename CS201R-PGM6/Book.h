#pragma once
#include "Media.h"

class Book : public Media {
private:
    int weeksNYT;

public:
    Book(char type, std::string title, std::string keyName, int rating, std::string genre, int length, int yearReleased, int weeksNYT);
    int getWeeks() const;
    void setWeeks(int weeks);
    void print(std::ostream& out) const override;
};
