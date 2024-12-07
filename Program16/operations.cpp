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

void demonstrateBitwiseOperations() {
    unsigned int num1, num2;

    std::cout << "\n--- Bitwise Operations ---\n";
    std::cout << "Enter two non-negative integers: ";
    std::cin >> num1 >> num2;

    std::cout << "Binary representation:\n";
    std::cout << "num1: " << std::bitset<16>(num1) << "\n";
    std::cout << "num2: " << std::bitset<16>(num2) << "\n";

    std::cout << "\nBitwise AND: " << (num1 & num2) << " (" << std::bitset<16>(num1 & num2) << ")\n";
    std::cout << "Bitwise OR: " << (num1 | num2) << " (" << std::bitset<16>(num1 | num2) << ")\n";
    std::cout << "Bitwise XOR: " << (num1 ^ num2) << " (" << std::bitset<16>(num1 ^ num2) << ")\n";
    std::cout << "Bitwise NOT of num1: " << (~num1) << " (" << std::bitset<16>(~num1) << ")\n";
    std::cout << "Bitwise NOT of num2: " << (~num2) << " (" << std::bitset<16>(~num2) << ")\n";

    int shift;
    std::cout << "Enter the number of positions to shift num1 left: ";
    std::cin >> shift;
    std::cout << "Left shift (num1 << " << shift << "): " << (num1 << shift) << " (" << std::bitset<16>(num1 << shift) << ")\n";

    std::cout << "Enter the number of positions to shift num2 right: ";
    std::cin >> shift;
    std::cout << "Right shift (num2 >> " << shift << "): " << (num2 >> shift) << " (" << std::bitset<16>(num2 >> shift) << ")\n";
}