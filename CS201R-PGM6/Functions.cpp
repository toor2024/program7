#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Functions.h"
#include "Media.h"
#include "Movie.h"
#include "Book.h"
#include "Song.h"

using namespace std;

// Utility function to check if a string consists only of digits
bool checkDigits(const string& str1) {
    return !str1.empty() && str1.find_first_not_of("0123456789") == string::npos;
}

// Utility function to trim whitespace from a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

// Function to read the media list from file and populate the vector
void readMediaList(istream& inFile, ostream& errFile, vector<Media*>& mediaLib) {
    string line;
    while (getline(inFile, line)) {
        // Determine the media type from the first character (e.g., 'M' for Movie)
        stringstream ss(line);
        char type;
        ss >> type;

        Media* media = nullptr;

        // Based on the type, create the appropriate media object
        if (type == 'M') {
            media = Movie::createFromLine(line);
        } else if (type == 'B') {
            media = Book::createFromLine(line);
        } else if (type == 'S') {
            media = Song::createFromLine(line);
        }

        if (media != nullptr) {
            mediaLib.push_back(media);
        } else {
            errFile << "ERROR: Failed to parse media line: " << line << endl;
        }
    }
}

// Function to print all media items
void printAllMedia(ostream& outFile, const vector<Media*>& mediaLib) {
    for (const auto& media : mediaLib) {
        media->print(outFile);
    }
}

// Function to print media items by type
void printMediaByType(ostream& outFile, const vector<Media*>& mediaLib, char type) {
    for (const auto& media : mediaLib) {
        if (media->getType() == type) {
            media->print(outFile);
        }
    }
}

// Function to print totals of each media type
void printTotals(ostream& outFile, const vector<Media*>& mediaLib) {
    int totalMovies = 0, totalBooks = 0, totalSongs = 0;

    for (const auto& media : mediaLib) {
        switch (media->getType()) {
            case 'M': totalMovies++; break;
            case 'B': totalBooks++; break;
            case 'S': totalSongs++; break;
        }
    }

    int totalItems = totalMovies + totalBooks + totalSongs;

    // Print totals
    outFile << "YOUR MEDIA LIBRARY" << endl;
    outFile << "#\tTYPE" << endl;
    outFile << totalMovies << "\tMovies" << endl;
    outFile << totalBooks << "\tBooks" << endl;
    outFile << totalSongs << "\tSongs" << endl;
    outFile << totalItems << "\tItems" << endl;
}

// Updated function to process commands from the command file
void processCommands(istream& inCommands, ostream& outFile, ostream& outErr, vector<Media*>& myLib) {
    string commandRecord;
    bool initialPrinted = false;

    // Print initial totals once
    if (!initialPrinted) {
        outFile << "Initial Totals:\n";
        printTotals(outFile, myLib);
        initialPrinted = true;
    }

    while (getline(inCommands, commandRecord)) {
        if (commandRecord.empty()) continue;

        char choice = commandRecord[0];
        string argument = (commandRecord.length() > 2) ? commandRecord.substr(2) : "";

        switch (choice) {
            case 'A':
                printAllMedia(outFile, myLib);
                break;
            case 'M':
                if (!argument.empty()) printMediaByType(outFile, myLib, 'M');
                break;
            case 'B':
                if (!argument.empty()) printMediaByType(outFile, myLib, 'B');
                break;
            case 'S':
                if (!argument.empty()) printMediaByType(outFile, myLib, 'S');
                break;
            case 'N': {
                // Handle adding new media item based on the type specified in the argument
                stringstream ss(argument);
                char type;
                ss >> type;
                ss.ignore();  // Skip the comma

                Media* newMedia = nullptr;

                // Based on the type, create the appropriate media object
                if (type == 'M') {
                    newMedia = Movie::createFromLine(argument);
                } else if (type == 'B') {
                    newMedia = Book::createFromLine(argument);
                } else if (type == 'S') {
                    newMedia = Song::createFromLine(argument);
                }

                if (newMedia != nullptr) {
                    myLib.push_back(newMedia);
                } else {
                    outErr << "ERROR: Failed to create new media from argument: " << argument << endl;
                }
                break;
            }
            case 'Q':
                return;
        }
    }

    // Print final totals once
    outFile << "\nFinal Totals:\n";
    printTotals(outFile, myLib);
}
