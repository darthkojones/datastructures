#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "selection_sort.h"

void printArray(const std::vector<int>& arr, std::ostream& os = std::cout) {
    for (int val : arr) {
        os << val << " ";
    }
    os << std::endl;
}

std::string getCurrentTimeString() {
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_time);
    std::ostringstream oss;
    oss << std::put_time(local_time, "%Y-%m-%d_%H-%M-%S");
    return oss.str();
}

int main() {
    // Seed for random number generation
    srand(time(0));

    // Generate unique log file name
    std::string logFileName = "log_" + getCurrentTimeString() + ".txt";

    // Create and open the log file
    std::ofstream logFile(logFileName);

    // Generate and sort a large array
    const int LARGE_SIZE = 1000;
    std::vector<int> largeArray(LARGE_SIZE);
    for (int i = 0; i < LARGE_SIZE; ++i) {
        largeArray[i] = rand() % 10000;
    }

    std::cout << "\nOriginal Array (1000 elements):" << std::endl;
    logFile << "Original Array (1000 elements):" << std::endl;
    printArray(largeArray);
    printArray(largeArray, logFile);

    // Sorting the array
    auto start = std::chrono::high_resolution_clock::now();
    selectionSort(largeArray);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "\nSorted Array:" << std::endl;
    logFile << "\nSorted Array:" << std::endl;
    printArray(largeArray);
    printArray(largeArray, logFile);

    std::cout << "\nSelection Sort took: " << std::fixed << std::setprecision(6) << duration.count() << " seconds\n" << std::endl;
    logFile << "\nSelection Sort took: " << std::fixed << std::setprecision(6) << duration.count() << " seconds\n" << std::endl;

    // Ask user for the number of elements to search for
    int numSearches;
    std::cout << "Number of elements to search for: ";
    std::cin >> numSearches;
    logFile << "Number of elements to search for: " << numSearches << std::endl;

    // Randomly select elements from the sorted array
    std::vector<int> searchElements(numSearches);
    for (int i = 0; i < numSearches; ++i) {
        searchElements[i] = largeArray[rand() % LARGE_SIZE];
    }

    std::cout << "\nThe following random elements have been chosen to be looked for:" << std::endl;
    logFile << "\nThe following random elements have been chosen to be looked for:" << std::endl;
    printArray(searchElements);
    printArray(searchElements, logFile);

    // Perform search and measure time
    double totalSearchTime = 0;
    for (const int& element : searchElements) {
        auto start = std::chrono::high_resolution_clock::now();
        auto it = std::find(largeArray.begin(), largeArray.end(), element);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        totalSearchTime += duration.count();

        std::cout << "Element " << element << (it != largeArray.end() ? " found" : " not found") << " in " << std::fixed << std::setprecision(6) << duration.count() << " seconds." << std::endl;
        logFile << "Element " << element << (it != largeArray.end() ? " found" : " not found") << " in " << std::fixed << std::setprecision(6) << duration.count() << " seconds." << std::endl;
    }

    // Calculate and display average search time
    double averageSearchTime = totalSearchTime / numSearches;

    std::cout << "\nAverage Search time: " << std::fixed << std::setprecision(6) << averageSearchTime << " seconds" << std::endl;
    logFile << "\nAverage Search time: " << std::fixed << std::setprecision(6) << averageSearchTime << " seconds" << std::endl;

    // Close the log file
    logFile.close();
    std::cout << "\nLog file has been generated!\n" << std::endl;

    return 0;
}
