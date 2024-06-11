#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "insertion_sort.h"

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

    const int DEMO_SIZE = 50;
    const int LARGE_SIZE = 1000;

    double totalNonRecursiveTime = 0;
    double totalRecursiveTime = 0;

    for (int k = 0; k < numArrays; ++k) {
        std::vector<int> demoArray(DEMO_SIZE);
        for (int i = 0; i < DEMO_SIZE; ++i) {
            demoArray[i] = rand() % 100;
        }

        std::cout << "\nOriginal Array " << k + 1 << " (50 elements):" << std::endl;
        logFile << "Original Array " << k + 1 << " (50 elements):" << std::endl;
        printArray(demoArray);
        printArray(demoArray, logFile);

        // Copy arrays for sorting
        std::vector<int> array1 = demoArray;
        std::vector<int> array2 = demoArray;

        insertionSortNonRecursive(array1);
        insertionSortRecursive(array2, array2.size());

        std::cout << "\nSorted Array " << k + 1 << " (Non-Recursive):" << std::endl;
        logFile << "\nSorted Array " << k + 1 << " (Non-Recursive):" << std::endl;
        printArray(array1);
        printArray(array1, logFile);

        std::cout << "\nSorted Array " << k + 1 << " (Recursive):" << std::endl;
        logFile << "\nSorted Array " << k + 1 << " (Recursive):" << std::endl;
        printArray(array2);
        printArray(array2, logFile);

        std::cout << "\n----------------------------------------\n" << std::endl;
        logFile << "\n----------------------------------------\n" << std::endl;

        // Large array for performance testing
        std::vector<int> largeArray1(LARGE_SIZE);
        std::vector<int> largeArray2(LARGE_SIZE);

        for (int i = 0; i < LARGE_SIZE; ++i) {
            int value = rand() % 10000;
            largeArray1[i] = value;
            largeArray2[i] = value;
        }

        // Time non-recursive insertion sort
        auto start = std::chrono::high_resolution_clock::now();
        insertionSortNonRecursive(largeArray1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        totalNonRecursiveTime += duration.count();
        std::cout << "Non-Recursive Insertion Sort took: " << duration.count() << " seconds" << std::endl;
        logFile << "Non-Recursive Insertion Sort took: " << duration.count() << " seconds" << std::endl;

        // Time recursive insertion sort
        start = std::chrono::high_resolution_clock::now();
        insertionSortRecursive(largeArray2, LARGE_SIZE);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        totalRecursiveTime += duration.count();
        std::cout << "Recursive Insertion Sort took: " << duration.count() << " seconds" << std::endl;
        logFile << "Recursive Insertion Sort took: " << duration.count() << " seconds" << std::endl;

        std::cout << "\n========================================\n" << std::endl;
        logFile << "\n========================================\n" << std::endl;
    }

    // Calculate and display averages
    double averageNonRecursiveTime = totalNonRecursiveTime / numArrays;
    double averageRecursiveTime = totalRecursiveTime / numArrays;

    std::cout << "Average Non-Recursive Insertion Sort time: " << averageNonRecursiveTime << " seconds" << std::endl;
    std::cout << "Average Recursive Insertion Sort time: " << averageRecursiveTime << " seconds" << std::endl;
    logFile << "Average Non-Recursive Insertion Sort time: " << averageNonRecursiveTime << " seconds" << std::endl;
    logFile << "Average Recursive Insertion Sort time: " << averageRecursiveTime << " seconds" << std::endl;

    // Close the log file
    logFile.close();
    std::cout << "\nLog file has been generated!\n" << std::endl;

    return 0;
}
