
#include "string_operations.h"
#include <vector>
#include <limits>

// Helper function to display menu
int displayMenu(const std::vector<std::string>& options) {
    std::cout << "\nChoose an operation:\n";
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << i + 1 << ". " << options[i] << "\n";
    }
    int choice;
    std::cin >> choice;
    return choice;
}

// Helper function to clear input buffer
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<std::string> options = {
        "Assign values to strings",
        "Concatenate strings",
        "Compare portions of strings",
        "Display string forward",
        "Display string reverse",
        "Demonstrate I/O streams",
        "Exit"
    };

    while (true) {
        int choice = displayMenu(options);
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
            case 4: {
                std::string str;
                std::cout << "Enter a string: ";
                clearInputBuffer();
                std::getline(std::cin, str);
                displayStringForward(str);
                break;
            }
            case 5: {
                std::string str;
                std::cout << "Enter a string: ";
                clearInputBuffer();
                std::getline(std::cin, str);
                displayStringReverse(str);
                break;
            }
            case 6:
                demonstrateIOStreams();
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
