
#include <iostream>
#include <fstream>
#include <string>

#include "CustomList.h"

int main() {
    CustomList<std::string> customList;
    int choice;
    std::string value;
    int index;

    while (true) {
        std::cout << "Enter your choice (1-7): \n";
        std::cout << "1. Insert at the beginning\n";
        std::cout << "2. Insert at the end\n";
        std::cout << "3. Delete from the beginning\n";
        std::cout << "4. Delete from the end\n";
        std::cout << "5. Insert at a location (index)\n";
        std::cout << "6. Delete by value\n";
        std::cout << "7. End list processing\n";

        std::cin >> choice;

        try {
            switch (choice) {
            case 1:
                std::cout << "Enter value to insert at the beginning: ";
                std::cin >> value;
                customList.insertBeginning(value);
                break;
            case 2:
                std::cout << "Enter value to insert at the end: ";
                std::cin >> value;
                customList.insertEnd(value);
                break;
            case 3:
                customList.deleteBeginning();
                break;
            case 4:
                customList.deleteEnd();
                break;
            case 5:
                std::cout << "Enter index: ";
                std::cin >> index;
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                customList.insertAtIndex(index, value);
                break;
            case 6:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                customList.deleteByValue(value);
                break;
            case 7:
                std::cout << "Ending list processing. Final List:\n";
                customList.display();
                return 0;
            default:
                std::cout << "Invalid choice. Please select a number between 1 and 7.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
            std::cout << "Please try another operation.\n";
        }

        customList.display();
    }
}


