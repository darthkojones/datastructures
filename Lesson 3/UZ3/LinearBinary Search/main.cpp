#include <iostream>
#include <chrono>
#include <cstdlib>
#include <iomanip> // Include this library for setting precision
#include "linear_search.h"
#include "binary_search.h"

#define ARRAY_SIZE 10000

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1; // Simple filling for easy binary search
    }
}

int main() {
    int arr[ARRAY_SIZE];
    fillArray(arr, ARRAY_SIZE);

    int target = ARRAY_SIZE; // Target to search for
    int index;

    // Linear search
    auto start = std::chrono::high_resolution_clock::now();
    index = linearSearch(arr, ARRAY_SIZE, target);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> linear_duration = end - start;
    std::cout << std::fixed << std::setprecision(7); 
    std::cout << "Linear Search is O(n): Index = " << index << ", Time = " << linear_duration.count() << "s\n";

    // Binary search
    start = std::chrono::high_resolution_clock::now();
    index = binarySearch(arr, ARRAY_SIZE, target);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> binary_duration = end - start;
    std::cout << std::fixed << std::setprecision(7); // Set precision for output
    std::cout << "Binary Search is O(log n): Index = " << index << ", Time = " << binary_duration.count() << "s\n";

    return 0;
}
