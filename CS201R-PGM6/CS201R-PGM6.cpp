#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Functions.h"
#include "Media.h"
#include "Movie.h"
#include "Book.h"
#include "Song.h"

using namespace std;

int main() {
    // Open the input and output files
    ifstream inList("mediaList.txt");
    ifstream inCommands("mediaCommands.txt");
    ofstream outErr("mediaError.txt");
    ofstream outFile("mediaReport.txt");

    // Check if files opened successfully
    if (!inList.is_open()) {
        cerr << "Error: Unable to open mediaList.txt" << endl;
        return 1;
    }
    if (!inCommands.is_open()) {
        cerr << "Error: Unable to open mediaCommands.txt" << endl;
        return 1;
    }
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open mediaReport.txt" << endl;
        return 1;
    }
    if (!outErr.is_open()) {
        cerr << "Error: Unable to open mediaError.txt" << endl;
        return 1;
    }

    // Vector to store media items
    vector<Media*> myLib;

    // Load media list from the file
    readMediaList(inList, outErr, myLib);

    // Print initial totals to the terminal
    cout << "Initial Totals:" << endl;
    printTotals(cout, myLib); // Print to terminal

    // Process commands from 'mediaCommands.txt'
    processCommands(inCommands, outFile, outErr, myLib);

    // Print final totals to both terminal and the output file
    cout << "\nFinal Totals:" << endl;
    printTotals(cout, myLib); // Print to terminal
    printTotals(outFile, myLib); // Print to file

    // Clean up dynamically allocated memory
    for (auto& media : myLib) {
        delete media;
    }

    // Close all files
    inList.close();
    inCommands.close();
    outFile.close();
    outErr.close();

    return 0;
}
