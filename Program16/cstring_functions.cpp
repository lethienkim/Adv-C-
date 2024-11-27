#include "operations.h"

void demonstrateCStringFunctions() {
    const int SIZE = 100;
    char str1[SIZE], str2[SIZE];

    std::cout << "\n--- C-String Functions ---\n";
    std::cout << "Enter the first string: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cin.getline(str1, SIZE);

    std::cout << "Enter the second string: ";
    std::cin.getline(str2, SIZE);

    // String length
    std::cout << "\nLength of first string: " << std::strlen(str1) << "\n";
    std::cout << "Length of second string: " << std::strlen(str2) << "\n";

    // String comparison
    int result = std::strcmp(str1, str2);
    if (result == 0) {
        std::cout << "The two strings are equal.\n";
    }
    else if (result < 0) {
        std::cout << "The first string is less than the second string.\n";
    }
    else {
        std::cout << "The first string is greater than the second string.\n";
    }

    // String concatenation using safer functions
    char concatenated[SIZE * 2];
    strcpy_s(concatenated, SIZE * 2, str1); // Safe copy
    strcat_s(concatenated, SIZE * 2, str2); // Safe concatenation
    std::cout << "Concatenated string: " << concatenated << "\n";
}
