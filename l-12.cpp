// COMSC-210 | Lab 12 | Annie Morales
// IDE used: Visual Studio Code

// Real-world simulation: This program will simulate daily temperatures for a month (30 days).
// It read 30 temperatures from a file, store them in an STD::array, 
// and calculate the average, highest, and lowest temperatures for the month.

// Header files
#include <iostream>
#include <array> // For std::array
#include <numeric> // For accumulate()
#include <fstream>
#include <algorithm> 
using namespace std;

const int DAYS_IN_MONTH = 30;

int main() 
{
    array<double, DAYS_IN_MONTH> temperatures;
    ifstream inputFile("temp.txt");

    if (!inputFile) 
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    for (int i = 0; i < DAYS_IN_MONTH; ++i) 
    {
        inputFile >> temperatures[i];
    }

    inputFile.close();

    double average = accumulate(temperatures.begin(), temperatures.end(), 0.0) / DAYS_IN_MONTH;
    double highest = *max_element(temperatures.begin(), temperatures.end());
    double lowest = *min_element(temperatures.begin(), temperatures.end());

    cout << "Average temperature: " << average << endl;
    cout << "Highest temperature: " << highest << endl;
    cout << "Lowest temperature: " << lowest << endl;

    return 0;
}