// COMSC-210 | Lab 12 | Annie Morales
// IDE used: Visual Studio Code

// Real-world simulation: This program will simulate daily temperatures for a month (30 days).
// It read 30 temperatures from a file, store them in an STD::array, 
// and calculate the average, highest, and lowest temperatures for the month.

// Header files
#include <iostream> // For input and output
#include <array> // For std::array
#include <numeric> // For accumulate()
#include <fstream> // For file operations
#include <algorithm> // For max_element() and min_element()
using namespace std;

const int DAYS_IN_MONTH = 30; // Number of days in a month

int main() 
{
    array<double, DAYS_IN_MONTH> temperatures; // Array to store daily temperatures
    
    // Reads temperatures from a file
    ifstream inputFile("temps.txt");

    // Checks if file opened successfully
    if (!inputFile) 
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    for (int i = 0; i < DAYS_IN_MONTH; ++i) // Traverses the array to read temperatures from the file
    {
        inputFile >> temperatures[i];
    }

    inputFile.close(); // Closes the file

    double average = accumulate(temperatures.begin(), temperatures.end(), 0.0) / DAYS_IN_MONTH; // Calculates average temperature
    double highest = *max_element(temperatures.begin(), temperatures.end()); // Finds highest temperature
    double lowest = *min_element(temperatures.begin(), temperatures.end()); // Finds lowest temperature

    // Displays the results
    cout << endl;
    cout << "Temperatures for the month:" << endl;
    cout << "---------------------------" << endl;
    cout << "Average temperature: " << average << endl;
    cout << "Highest temperature: " << highest << endl;
    cout << "Lowest temperature: " << lowest << endl;
    cout << endl;

    return 0;
}