//
// Author: Daria Lakunina
//
#include <algorithm>
#include <iostream>
#include <fstream>
#include "FrequenciesCalculator.h"
using namespace std;

//loading data from a file, calculating frequencies and populating the map
void FrequenciesCalculator::calculateFrequenciesFromFile(const string &inputFileName) {
    //read from file
    ifstream inFS;
    inFS.open(inputFileName);
    if (!inFS.is_open()) {
        cout << "Could not open file " << inputFileName << endl;
        return;
    }
    //form the map
    string currWord;
    while (!inFS.eof()) {
        inFS >> currWord;
        if (!goodsFrequencies.contains(currWord)) {
            goodsFrequencies.emplace(currWord, 1);
        } else {
            goodsFrequencies.at(currWord) = goodsFrequencies.at(currWord) + 1;
        }
    }
    inFS.close();
}

//writing the goods to frequencies map to a file
void FrequenciesCalculator::writeMapToFile(const string &outputFileName) const {
    //write the map to a file
    ofstream outFS;
    outFS.open(outputFileName);
    for (pair<string, int> freq: goodsFrequencies) {
        outFS << freq.first << " " << freq.second << endl;
    }
    outFS.close();
}

//displaying the menu
void FrequenciesCalculator::displayMenu() {
    cout << "1 - Find the frequency of produce purchases." << endl;
    cout << "2 - Output the frequency of purchases for all the items." << endl;
    cout << "3 - Output the frequency of purchases for all the items as a histogram." << endl;
    cout << "4 - Exit the program." << endl;
}

//looking up the produce's purchase frequency
void FrequenciesCalculator::lookupPurchaseFrequency() const {
    cout << "Please enter the produce name: " << endl;
    string userInput;
    cin >> userInput;
    //validate input in terms of containing digits
    while (any_of(userInput.begin(), userInput.end(), ::isdigit)) {
        cout << "Produce name cannot contain digits. Please enter a valid produce name: ";
        cin >> userInput;
    }
    //convert first letter of the input to capital for adequate search
    char &firstChar = userInput[0];
    if (islower(static_cast<unsigned char>(firstChar))) {
        firstChar = static_cast<char>(toupper(static_cast<unsigned char>(firstChar)));
    }
    //search for purchase frequency
    if (goodsFrequencies.count(userInput) == 0) {
        cout << "No " << userInput << " was purchased." << endl;
    } else {
        cout << userInput << " " << goodsFrequencies.at(userInput) << endl;
    }
}

//output all frequencies in the map
void FrequenciesCalculator::outputAllFrequencies() const {
    //output all the frequencies
    for (pair<string, int> freq: goodsFrequencies) {
        cout << freq.first << " " << freq.second << endl;
    }
}

//output all frequencies in the map as histogram
void FrequenciesCalculator::outputFrequenciesAsHistogram() const {
    //display frequencies as a histogram
    for (pair<string, int> freq: goodsFrequencies) {
        string frequency(freq.second, '*');
        cout << freq.first << " " << frequency << endl;
    }
}
