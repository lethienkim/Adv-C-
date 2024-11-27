#include "functions.h"
#include <vector>
#include <string>

int get_menu_choice(const std::vector<std::string>& options) {
    int choice;
    std::cout << "\nChoose an operation:\n";
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << i + 1 << ". " << options[i] << "\n";
    }
    std::cin >> choice;
    if (choice < 1 || choice > static_cast<int>(options.size())) {
        std::cout << "Invalid choice! Try again.\n";
        return get_menu_choice(options);
    }
    return choice;
}

int main() {
    CustomList custom_list;
    std::vector<std::string> list_operations = {
        "Insert at the beginning of the list",
        "Insert at the end of the list",
        "Delete from the beginning of the list",
        "Delete from the end of the list",
        "Insert at a location (index value) in the list",
        "Delete a node from the list based on its value",
        "End list processing"
    };

    std::vector<std::string> search_sort_operations = {
        "Linear search",
        "Selection sort",
        "Merge sort",
        "Binary search",
        "End search/sort operations"
    };

    while (true) {
        int choice = get_menu_choice(list_operations);
        if (choice == 7) break;

        try {
            int value, index;
            switch (choice) {
            case 1:
                std::cout << "Enter a value: ";
                std::cin >> value;
                custom_list.insert_beginning(value);
                std::cout << "Updated list: ";
                custom_list.print_list();
                break;
            case 2:
                std::cout << "Enter a value: ";
                std::cin >> value;
                custom_list.insert_end(value);
                std::cout << "Updated list: ";
                custom_list.print_list();
                break;
            case 3:
                custom_list.delete_beginning();
                std::cout << "Deleted from the beginning.\n";
                std::cout << "Updated list: ";
                custom_list.print_list();
                break;
            case 4:
                custom_list.delete_end();
                std::cout << "Deleted from the end.\n";
                std::cout << "Updated list: ";
                custom_list.print_list();
                break;
            case 5:
                std::cout << "Enter an index: ";
                std::cin >> index;
                std::cout << "Enter a value: ";
                std::cin >> value;
                custom_list.insert_at(index, value);
                std::cout << "Updated list: ";
                custom_list.print_list();
                break;
            case 6:
                std::cout << "Enter a value: ";
                std::cin >> value;
                custom_list.delete_value(value);
                std::cout << "Updated list: ";
                custom_list.print_list();
                break;
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    while (true) {
        int choice = get_menu_choice(search_sort_operations);
        if (choice == 5) break;

        try {
            int value, index;
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
                std::cout << "Updated list: ";
                custom_list.print_list();
                break;
            case 3:
                custom_list.merge_sort();
                std::cout << "List sorted: ";
                custom_list.print_list();
                std::cout << "Updated list: ";
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
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
