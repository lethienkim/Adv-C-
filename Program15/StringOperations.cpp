#include "string_operations.h"

// Demonstrates three ways to assign values to strings
void assignValuesToStrings() {
    std::string str1 = "Hello";
    std::string str2("World");
    std::string str3;
    str3 = "Welcome";

    std::cout << "Three ways to assign values to strings:" << std::endl;
    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;
    std::cout << "str3 = " << str3 << std::endl;
}

// Demonstrates two ways to concatenate strings
void concatenateStrings() {
    std::string str1 = "Hello";
    std::string str2 = " World";
    std::string str3 = str1 + str2; // Concatenation using +
    str1 += str2; // Concatenation using +=

    std::cout << "Two ways to concatenate strings:" << std::endl;
    std::cout << "Using +: " << str3 << std::endl;
    std::cout << "Using +=: " << str1 << std::endl;
}

// Enables user to select portions of two strings to compare with one another and compare those portions
void compareStringPortions() {
    std::string str1, str2;
    int start1, len1, start2, len2;

    std::cout << "Enter first string: ";
    std::cin >> str1;
    std::cout << "Enter second string: ";
    std::cin >> str2;
    std::cout << "Enter start index and length for first string: ";
    std::cin >> start1 >> len1;
    std::cout << "Enter start index and length for second string: ";
    std::cin >> start2 >> len2;

    std::string substr1 = str1.substr(start1, len1);
    std::string substr2 = str2.substr(start2, len2);

    std::cout << "Comparing \"" << substr1 << "\" and \"" << substr2 << "\": ";
    if (substr1 == substr2) {
        std::cout << "They are equal." << std::endl;
    }
    else {
        std::cout << "They are not equal." << std::endl;
    }
}

// Demonstrates a string iterator displaying a string in forward order
void displayStringForward(const std::string& str) {
    std::cout << "String in forward order: ";
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
}

// Demonstrates a string iterator displaying a string in reverse order
void displayStringReverse(const std::string& str) {
    std::cout << "String in reverse order: ";
    for (std::string::const_reverse_iterator rit = str.rbegin(); rit != str.rend(); ++rit) {
        std::cout << *rit;
    }
    std::cout << std::endl;
}

// Demonstrates the three common I/O streams using insertion (<<) and extraction (>>) operators
void demonstrateIOStreams() {
    std::string str;
    std::cout << "Enter a string for standard I/O: ";
    std::cin.ignore();
    std::getline(std::cin, str);
    std::cout << "You entered: " << str << std::endl;

    std::ofstream outfile("output.txt");
    outfile << "String written to file: " << str << std::endl;
    outfile.close();
    std::cout << "String written to file 'output.txt'." << std::endl;

    std::ifstream infile("output.txt");
    std::string fileStr;
    std::getline(infile, fileStr);
    std::cout << "String read from file: " << fileStr << std::endl;
    infile.close();

    std::stringstream ss;
    ss << "String stream content: " << str;
    std::cout << ss.str() << std::endl;
}
