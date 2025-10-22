/*
 * Author: Daria Lakunina
 * Date: 10/18/2025
 * Description: the application loads the grocery list from a file,
 * calculates and writes purchases frequencies to the file and outputs
 * the frequencies for requested individual item or for all the items as
 * numbers or as a histogram.
 */

#include <iostream>
#include <fstream>

#include "FrequenciesCalculator.h"
using namespace std;


int main() {
    FrequenciesCalculator frequenciesCalculator;
    //creating an instance of the class performing all the required functions
    frequenciesCalculator.calculateFrequenciesFromFile("CS210_Project_Three_Input_File.txt");
    //calculating purchases frequencies
    frequenciesCalculator.writeMapToFile("frequency.dat"); //writing the resulting map to a file for backup purpose

    //greeting the user and asking them for input
    cout << "Welcome to Grocery!" << endl;
    cout << "Please choose one of 4 options and enter the corresponding number." << endl;
    FrequenciesCalculator::displayMenu();
    cout << "Enter your choice: " << endl;
    string userChoice;
    cin >> userChoice;

    //validating user's input, directing the program's flow depending on it
    if (userChoice != "1" && userChoice != "2" && userChoice != "3") {
        cout << "Please enter a valid choice." << endl;
        cin >> userChoice;
    }
    while (userChoice != "4") {
        if (userChoice == "1") {
            frequenciesCalculator.lookupPurchaseFrequency();
            cout << endl;
            FrequenciesCalculator::displayMenu();
            cout << "Enter your choice: " << endl;
            cin >> userChoice;
        } else if (userChoice == "2") {
            frequenciesCalculator.outputAllFrequencies();
            cout << endl;
            FrequenciesCalculator::displayMenu();
            cout << "Enter your choice: " << endl;
            cin >> userChoice;
        } else if (userChoice == "3") {
            frequenciesCalculator.outputFrequenciesAsHistogram();
            cout << endl;
            FrequenciesCalculator::displayMenu();
            cout << "Enter your choice: " << endl;
            cin >> userChoice;
        }
    }

    return 0;
}
