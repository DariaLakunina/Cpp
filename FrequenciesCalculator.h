//
// Created by dshub on 10/17/2025.
//

#ifndef GROCERY_FREQUENCIESCALCULATOR_H
#define GROCERY_FREQUENCIESCALCULATOR_H
#include <map>
using namespace std;

class FrequenciesCalculator {
private:
    map<string, int> goodsFrequencies = map<string, int>(); //the map containing the data about frequencies of purchases

public:
    void calculateFrequenciesFromFile(const string &inputFileName);

    void writeMapToFile(const string &outputFileName) const;

    static void displayMenu();

    void lookupPurchaseFrequency() const;

    void outputAllFrequencies() const;

    void outputFrequenciesAsHistogram() const;
};


#endif //GROCERY_FREQUENCIESCALCULATOR_H
