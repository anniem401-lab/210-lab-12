// COMSC-210 | Lab 12 | Annie Morales
// IDE used: Visual Studio Code

// Real-world simulation: This program will simulate daily temperatures for a month (30 days).
// It will read 30 temperatures from a file, store them in an STD::array, 
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

    cout.setf(ios::fixed|ios::showpoint); // Sets the output format to fixed-point notation
    cout.precision(1); // Sets the precision to 1 decimal place

    double average = accumulate(temperatures.begin(), temperatures.end(), 0.0) / DAYS_IN_MONTH; // Calculates average temperature
    double highest = *max_element(temperatures.begin(), temperatures.end()); // Finds highest temperature
    double lowest = *min_element(temperatures.begin(), temperatures.end()); // Finds lowest temperature

    // Displays the results
    cout << endl;
    cout << "Display of temperatures:" << endl;
    cout << "------------------------" << endl;
    cout << "1. Is the array empty? " << (temperatures.empty() ? "Yes" : "No") << endl; // Checks if the array is empty
    cout << "2. Average temperature: " << average << "°F" << endl; // Average calculated by accumulate() function
    cout << "3. Highest temperature: " << highest << "°F" << endl; // Highest calculated by max_element() function
    cout << "4. Lowest temperature: " << lowest << "°F" << endl; // Lowest calculated by min_element() function
    cout << "5. Day 15 temperature: " << temperatures[14] << "°F" << endl; // Accessing the 15th day temperature (index 14)
    cout << "6. Address of the array: " << temperatures.data() << endl; // Address of the array
    cout << "7. Size of the array: " << temperatures.size() << endl; // Size of the array
    cout << "8. First element: " << temperatures.front() << "°F" << endl; // First element of the array
    cout << "9. Last element: " << temperatures.back() << "°F" << endl; // Last element of the array
    
    sort(temperatures.begin(), temperatures.end()); // Sorts the array in ascending order
    cout << "10. Sorted temperatures: ";
    for (double temp : temperatures) cout << temp << "°F  "; cout << endl; // Displays all temperatures sorted in the array
    cout << endl;

    return 0;
}