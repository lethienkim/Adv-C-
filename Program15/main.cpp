#include "string_operations.h"
int main() {
    int choice;

    while (true) {
        std::cout << "\nChoose an operation:\n";
        std::cout << "1. Assign values to strings\n";
        std::cout << "2. Concatenate strings\n";
        std::cout << "3. Compare portions of strings\n";
        std::cout << "4. Display string forward\n";
        std::cout << "5. Display string reverse\n";
        std::cout << "6. Demonstrate I/O streams\n";
        std::cout << "7. Exit\n";
        std::cin >> choice;

        if (choice == 7) break;

        try {
            switch (choice) {
            case 1:
                assignValuesToStrings();
                break;
            case 2:
                concatenateStrings();
                break;
            case 3:
                compareStringPortions();
                break;
            case 4:
            {
                std::string str;
                std::cout << "Enter a string: ";
                std::cin >> str;
                displayStringForward(str);
            }
            break;
            case 5:
            {
                std::string str;
                std::cout << "Enter a string: ";
                std::cin >> str;
                displayStringReverse(str);
            }
            break;
            case 6:
                demonstrateIOStreams();
                break;
            default:
                std::cout << "Invalid choice!\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
