#include "operations.h"

void demonstrateCharacterHandling() {
    char ch;

    std::cout << "\n--- Character-Handling Functions ---\n";
    std::cout << "Enter a single character: ";
    std::cin >> ch;

    std::cout << "Character information:\n";
    if (std::isalpha(ch)) {
        std::cout << ch << " is a letter.\n";
        std::cout << "Uppercase version: " << static_cast<char>(std::toupper(ch)) << "\n";
        std::cout << "Lowercase version: " << static_cast<char>(std::tolower(ch)) << "\n";
    }
    else if (std::isdigit(ch)) {
        std::cout << ch << " is a digit.\n";
    }
    else if (std::isspace(ch)) {
        std::cout << ch << " is a whitespace character.\n";
    }
    else {
        std::cout << ch << " is a special character.\n";
    }
}
