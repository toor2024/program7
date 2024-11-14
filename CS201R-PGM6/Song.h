#pragma once
#include "Media.h"

class Song : public Media {
private:
    bool top40;

public:
    Song(char type, std::string title, std::string keyName, int rating, std::string genre, int length, int yearReleased, bool top40);
    bool getTop40() const;
    void setTop40(bool top40);
    void print(std::ostream& out) const override;
};
