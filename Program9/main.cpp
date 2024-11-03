#include "containers.h"
#include <limits>  // For std::numeric_limits

int main() {
    int firstChoice, secondChoice;

    while (true) {
        // First-level menu
        std::cout << "Select a container type:\n";
        std::cout << "1. Sequence Containers\n";
        std::cout << "2. Ordered Associative Containers\n";
        std::cout << "3. Unordered Associative Containers\n";
        std::cout << "4. Container Adapters\n";
        std::cout << "0. Exit\n";  // Add an exit option

        std::cin >> firstChoice;

        // Validate input and handle failure state
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 0 and 4.\n";
            continue;  // Restart the loop
        }

        if (firstChoice == 0) break;  // Exit condition

        switch (firstChoice) {
        case 1:
            // Sequence Containers
            std::cout << "Select a Sequence Container:\n";
            std::cout << "1. array\n2. deque\n3. forward_list\n4. list\n5. vector\n";
            std::cin >> secondChoice;

            // Validate second choice
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
                continue;
            }

            switch (secondChoice) {
            case 1: handleArray(); break;
            case 2: handleDeque(); break;
            case 3: handleForwardList(); break;
            case 4: handleList(); break;
            case 5: handleVector(); break;
            default: std::cout << "Invalid selection.\n";
            }
            break;

        case 2:
            // Ordered Associative Containers
            std::cout << "Select an Ordered Associative Container:\n";
            std::cout << "1. set\n2. multiset\n3. map\n4. multimap\n";
            std::cin >> secondChoice;

            // Validate second choice
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
                continue;
            }

            switch (secondChoice) {
            case 1: handleSet(); break;
            case 2: handleMultiset(); break;
            case 3: handleMap(); break;
            case 4: handleMultimap(); break;
            default: std::cout << "Invalid selection.\n";
            }
            break;

        case 3:
            // Unordered Associative Containers
            std::cout << "Select an Unordered Associative Container:\n";
            std::cout << "1. unordered_set\n2. unordered_multiset\n3. unordered_map\n4. unordered_multimap\n";
            std::cin >> secondChoice;

            // Validate second choice
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
                continue;
            }

            switch (secondChoice) {
            case 1: handleUnorderedSet(); break;
            case 2: handleUnorderedMultiset(); break;
            case 3: handleUnorderedMap(); break;
            case 4: handleUnorderedMultimap(); break;
            default: std::cout << "Invalid selection.\n";
            }
            break;

        case 4:
            // Container Adapters
            std::cout << "Select a Container Adapter:\n";
            std::cout << "1. stack\n2. queue\n3. priority_queue\n";
            std::cin >> secondChoice;

            // Validate second choice
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
                continue;
            }

            switch (secondChoice) {
            case 1: handleStack(); break;
            case 2: handleQueue(); break;
            case 3: handlePriorityQueue(); break;
            default: std::cout << "Invalid selection.\n";
            }
            break;

        default:
            std::cout << "Invalid selection. Please choose a number between 0 and 4.\n";
        }
    }

    return 0;
}
