#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Media.h"

// Utility functions
bool checkDigits(const std::string& str1);
std::string trim(const std::string& str);

// Function declarations for reading and processing media
void readMediaList(std::istream& inFile, std::ostream& errFile, std::vector<Media*>& mediaLib);
void processCommands(std::istream& inCommands, std::ostream& outFile, std::ostream& outErr, std::vector<Media*>& mediaLib);

// Functions for printing media
void printAllMedia(std::ostream& outFile, const std::vector<Media*>& mediaLib);
void printMediaByType(std::ostream& outFile, const std::vector<Media*>& mediaLib, char type);
void printTotals(std::ostream& outFile, const std::vector<Media*>& mediaLib);

// New functions for the commands L, F, and K
void listStars(std::ostream& outFile, std::ostream& errFile, const std::vector<Media*>& mediaLib, const std::string& starName);
void listMoviesByString(std::ostream& outFile, std::ostream& errFile, const std::vector<Media*>& mediaLib, const std::string& searchStr);
void listMediaByName(std::ostream& outFile, std::ostream& errFile, const std::vector<Media*>& mediaLib, const std::string& name);

// Function to add new media based on command
void addNewMedia(const std::string& commandRecord, std::ostream& outErr, std::vector<Media*>& mediaLib);
