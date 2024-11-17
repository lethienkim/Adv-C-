#include "function.h"
#include <exception>

using namespace std;

// Displays the menu options for stack operations
void displayMenu() {
    cout << "\nStack Operations:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Top\n";
    cout << "4. Clear\n";
    cout << "5. Check if Empty\n";
    cout << "6. Exit to main menu\n";
}

// Function template to perform stack operations for any type T
template <typename T>
void performStackOperations(Stack<T>& stack) {
    int operation;
    T value;

    while (true) {
        displayMenu();
        cout << "\nSelect an operation (1-6): ";
        cin >> operation;

        try {
            switch (operation) {
            case 1: // Push
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                cout << "Value pushed onto the stack.\n";
                break;
            case 2: // Pop
                cout << "Popped value: " << stack.pop() << endl;
                break;
            case 3: // Top
                cout << "Top value: " << stack.top() << endl;
                break;
            case 4: // Clear
                stack.clear();
                cout << "Stack cleared.\n";
                break;
            case 5: // Empty
                if (stack.empty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;
            case 6: // Exit
                cout << "Returning to main menu.\n";
                return;
            default:
                cout << "Invalid operation. Please select a number from 1 to 6.\n";
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
}

// Explicit template instantiation declarations
template void performStackOperations<int>(Stack<int>& stack);
template void performStackOperations<double>(Stack<double>& stack);
template void performStackOperations<string>(Stack<string>& stack);
