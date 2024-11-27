#include "functions.h"

int main() {
    CustomList custom_list;
    int choice, value, index;

    while (true) {
        std::cout << "\nChoose an operation:\n";
        std::cout << "1. Insert at the beginning of the list\n";
        std::cout << "2. Insert at the end of the list\n";
        std::cout << "3. Delete from the beginning of the list\n";
        std::cout << "4. Delete from the end of the list\n";
        std::cout << "5. Insert at a location (index value) in the list\n";
        std::cout << "6. Delete a node from the list based on its value\n";
        std::cout << "7. End list processing\n";
        std::cin >> choice;

        if (choice == 7) break;

        try {
            switch (choice) {
            case 1:
                std::cout << "Enter a value: ";
                std::cin >> value;
                custom_list.insert_beginning(value);
                break;
            case 2:
                std::cout << "Enter a value: ";
                std::cin >> value;
                custom_list.insert_end(value);
                break;
            case 3:
                custom_list.delete_beginning();
                std::cout << "Deleted from the beginning\n";
                break;
            case 4:
                custom_list.delete_end();
                std::cout << "Deleted from the end\n";
                break;
            case 5:
                std::cout << "Enter an index: ";
                std::cin >> index;
                std::cout << "Enter a value: ";
                std::cin >> value;
                custom_list.insert_at(index, value);
                break;
            case 6:
                std::cout << "Enter a value: ";
                std::cin >> value;
                custom_list.delete_value(value);
                break;
            default:
                std::cout << "Invalid choice!\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    while (true) {
        std::cout << "\nChoose a search/sort operation:\n";
        std::cout << "1. Linear search\n";
        std::cout << "2. Selection sort\n";
        std::cout << "3. Merge sort\n";
        std::cout << "4. Binary search\n";
        std::cout << "5. End search/sort operations\n";
        std::cin >> choice;

        if (choice == 5) break;

        try {
            switch (choice) {
            case 1:
                std::cout << "Enter a value to search: ";
                std::cin >> value;
                index = custom_list.linear_search(value);
                if (index != -1) {
                    std::cout << "Value found at index: " << index << "\n";
                }
                else {
                    std::cout << "Value not found\n";
                }
                break;
            case 2:
                custom_list.selection_sort();
                std::cout << "List sorted: ";
                custom_list.print_list();
                break;
            case 3:
                custom_list.merge_sort();
                std::cout << "List sorted: ";
                custom_list.print_list();
                break;
            case 4:
                std::cout << "Enter a value to search: ";
                std::cin >> value;
                index = custom_list.binary_search(value);
                if (index != -1) {
                    std::cout << "Value found at index: " << index << "\n";
                }
                else {
                    std::cout << "Value not found\n";
                }
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
