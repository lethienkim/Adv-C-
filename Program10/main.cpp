#include "algorithms_demo.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <limits> // Include this for std::numeric_limits



int main() {
    std::vector<int> vec = getUserInputVector();

    // Display the original container
    displayContainer(vec, "Original vector");

    // Run demonstrations
    char choice;
    do {
        std::cout << "\nChoose an algorithm demonstration to run:" << std::endl;
        std::cout << "1. Modifying Algorithms" << std::endl;
        std::cout << "2. Non-Modifying Algorithms" << std::endl;
        std::cout << "3. Sorting Algorithms" << std::endl;
        std::cout << "4. Numerical Algorithms" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter choice (1-5): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline

        switch (choice) {
        case '1':
            demonstrateModifyingAlgorithms(vec);
            break;
        case '2':
            demonstrateNonModifyingAlgorithms(vec);
            break;
        case '3':
            demonstrateSortingAlgorithms(vec);
            break;
        case '4':
            demonstrateNumericalAlgorithms(vec);
            break;
        case '5':
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
            break;
        }
    } while (choice != '5');

    return 0;
}
