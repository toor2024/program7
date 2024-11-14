#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Media.h"

bool checkDigits(const std::string& str1);
std::string trim(const std::string& str);

void readMediaList(std::istream& inFile, std::ostream& errFile, std::vector<Media*>& mediaLib);
void processCommands(std::istream& inCommands, std::ostream& outFile, std::ostream& outErr, std::vector<Media*>& mediaLib);
void printAllMedia(std::ostream& outFile, const std::vector<Media*>& mediaLib);
void printMediaByType(std::ostream& outFile, const std::vector<Media*>& mediaLib, char type);
void printTotals(std::ostream& outFile, const std::vector<Media*>& mediaLib);
void addNewMedia(const std::string& commandRecord, std::ostream& outErr, std::vector<Media*>& mediaLib);
