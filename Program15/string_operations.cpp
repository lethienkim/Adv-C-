#include "string_operations.h"

// Helper function to iterate over a string
void iterateString(const std::string& str, bool reverse = false) {
    if (reverse) {
        std::cout << "String in reverse order: ";
        for (auto rit = str.rbegin(); rit != str.rend(); ++rit) {
            std::cout << *rit;
        }
    }
    else {
        std::cout << "String in forward order: ";
        for (auto it = str.begin(); it != str.end(); ++it) {
            std::cout << *it;
        }
    }
    std::cout << "\n";
}

// Demonstrates three ways to assign values to strings
void assignValuesToStrings() {
    std::string str1 = "Hello";
    std::string str2("World");
    std::string str3;
    str3 = "Welcome";

    std::cout << "Three ways to assign values to strings:\n";
    std::cout << "str1 = " << str1 << "\n";
    std::cout << "str2 = " << str2 << "\n";
    std::cout << "str3 = " << str3 << "\n";
}

// Demonstrates two ways to concatenate strings
void concatenateStrings() {
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::cin.ignore();
    std::getline(std::cin, str1);
    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);

    std::string concatenated1 = str1 + str2;
    str1 += str2;

    std::cout << "Concatenation using +: " << concatenated1 << "\n";
    std::cout << "Concatenation using +=: " << str1 << "\n";
}

// Enables user to select portions of two strings to compare with one another and compare those portions
void compareStringPortions() {
    std::string str1, str2;
    int start1, len1, start2, len2;

    std::cout << "Enter the first string: ";
    std::cin.ignore();
    std::getline(std::cin, str1);
    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);

    std::cout << "Enter start index and length for the first string: ";
    std::cin >> start1 >> len1;
    std::cout << "Enter start index and length for the second string: ";
    std::cin >> start2 >> len2;

    if (start1 < 0 || start1 + len1 > static_cast<int>(str1.size()) || len1 < 0) {
        std::cout << "Invalid indices for the first string.\n";
        return;
    }
    if (start2 < 0 || start2 + len2 > static_cast<int>(str2.size()) || len2 < 0) {
        std::cout << "Invalid indices for the second string.\n";
        return;
    }

    std::string substr1 = str1.substr(start1, len1);
    std::string substr2 = str2.substr(start2, len2);

    std::cout << "Comparing \"" << substr1 << "\" and \"" << substr2 << "\": ";
    if (substr1 == substr2) {
        std::cout << "They are equal.\n";
    }
    else {
        std::cout << "They are not equal.\n";
    }
}

// Demonstrates a string iterator displaying a string in forward order
void displayStringForward(const std::string& str) {
    iterateString(str);
}

// Demonstrates a string iterator displaying a string in reverse order
void displayStringReverse(const std::string& str) {
    iterateString(str, true);
}

// Demonstrates the three common I/O streams using insertion (<<) and extraction (>>) operators
void demonstrateIOStreams() {
    std::string str;
    std::cout << "Enter a string for standard I/O: ";
    std::cin.ignore();
    std::getline(std::cin, str);
    std::cout << "You entered: " << str << "\n";

    std::string filename;
    std::cout << "Enter the filename to write to: ";
    std::cin >> filename;

    std::ofstream outfile(filename);
    outfile << "String written to file: " << str << "\n";
    outfile.close();
    std::cout << "String written to file '" << filename << "'.\n";

    std::ifstream infile(filename);
    std::string fileStr;
    std::getline(infile, fileStr);
    std::cout << "String read from file: " << fileStr << "\n";
    infile.close();

    std::stringstream ss;
    ss << "String stream content: " << str;
    std::cout << ss.str() << "\n";
}
