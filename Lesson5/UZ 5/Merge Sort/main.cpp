#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "merge_sort.h"

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

    // Ask user for the number of arrays to generate and sort
    int numArrays;
    std::cout << "Number of arrays to be randomly generated and then sorted: ";
    std::cin >> numArrays;
    logFile << "Number of arrays to be randomly generated and then sorted: " << numArrays << std::endl;

    const int DEMO_SIZE = 50;

    double totalSortTime = 0;

    for (int k = 0; k < numArrays; ++k) {
        std::vector<int> demoArray(DEMO_SIZE);
        for (int i = 0; i < DEMO_SIZE; ++i) {
            demoArray[i] = rand() % 100;
        }

        std::cout << "\nOriginal Array " << k + 1 << " (50 elements):" << std::endl;
        logFile << "Original Array " << k + 1 << " (50 elements):" << std::endl;
        printArray(demoArray);
        printArray(demoArray, logFile);

        // Sorting the array
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(demoArray);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        totalSortTime += duration.count();

        std::cout << "\nSorted Array " << k + 1 << ":" << std::endl;
        logFile << "\nSorted Array " << k + 1 << ":" << std::endl;
        printArray(demoArray);
        printArray(demoArray, logFile);

        std::cout << "\nMerge Sort took: " << std::fixed << std::setprecision(6) << duration.count() << " seconds\n" << std::endl;
        logFile << "\nMerge Sort took: " << std::fixed << std::setprecision(6) << duration.count() << " seconds\n" << std::endl;

        std::cout << "\n----------------------------------------\n" << std::endl;
        logFile << "\n----------------------------------------\n" << std::endl;
    }

    // Calculate and display average sort time
    double averageSortTime = totalSortTime / numArrays;

    std::cout << "Average Merge Sort time: " << std::fixed << std::setprecision(6) << averageSortTime << " seconds" << std::endl;
    logFile << "Average Merge Sort time: " << std::fixed << std::setprecision(6) << averageSortTime << " seconds" << std::endl;

    // Close the log file
    logFile.close();
    std::cout << "\nLog file has been generated!\n" << std::endl;

    return 0;
}
