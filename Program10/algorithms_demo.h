
#ifndef ALGORITHMS_DEMO_H
#define ALGORITHMS_DEMO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>    // For numerical algorithms
#include <functional> // For function objects
#include <sstream>    // Include for std::istringstream

// Function to display container contents
template <typename Container>
void displayContainer(const Container& container, const std::string& message = "Container");

// Function to populate a vector based on user input
std::vector<int> getUserInputVector();

// Modifying sequence algorithms
void demonstrateModifyingAlgorithms(std::vector<int>& vec);

// Non-modifying sequence algorithms
void demonstrateNonModifyingAlgorithms(std::vector<int>& vec);

// Sorting and related algorithms
void demonstrateSortingAlgorithms(std::vector<int>& vec);

// Numerical algorithms
void demonstrateNumericalAlgorithms(std::vector<int>& vec);

// Function objects demonstration
void demonstrateFunctionObjects(std::vector<int>& vec);

#endif // ALGORITHMS_DEMO_H
