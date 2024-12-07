
#include "operations.h"

int main() {
    int choice;

    std::cout << "Welcome to Program 16: Demonstrating Bitwise Operations, Character Handling, and C-String Functions\n";

    while (true) {
        std::cout << "\nChoose an operation to perform:\n";
        std::cout << "1. Demonstrate Bitwise Operations\n";
        std::cout << "2. Demonstrate Character Handling Functions\n";
        std::cout << "3. Demonstrate C-String Functions\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 4) {
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        }

        switch (choice) {
        case 1:
            demonstrateBitwiseOperations();
            break;
        case 2:
            demonstrateCharacterHandling();
            break;
        case 3:
            demonstrateCStringFunctions();
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
